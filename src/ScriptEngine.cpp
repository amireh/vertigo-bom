/*
 * This file is part of Vertigo: The Brink of Madness.
 *
 * Vertigo: The Brink of Madness - a cross-platform arcade game powered by Ogre3D.
 * Copyright (C) 2011-2012  Ahmad Amireh <ahmad@amireh.net>
 *
 * Vertigo: The Brink of Madness is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Vertigo: The Brink of Madness is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Vertigo: The Brink of Madness.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Hax/ScriptEngine.hpp"
#include "Hax/GameState.hpp"
#include "Hax/EventManager.hpp"
#include "Hax/Utility.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/UIEngine.hpp"

TOLUA_API int  tolua_Hax_open (lua_State* tolua_S);
TOLUA_API int  tolua_Ogre_open (lua_State* tolua_S);
// TOLUA_API int  tolua_CEGUI_open (lua_State* tolua_S);
TOLUA_API int  tolua_OIS_open (lua_State* tolua_S);

namespace Hax {
	ScriptEngine* ScriptEngine::__instance = NULL;

	ScriptEngine* ScriptEngine::getSingletonPtr() {
		if( !__instance ) {
		    __instance = new ScriptEngine();
		}

		return __instance;
	}

	ScriptEngine& ScriptEngine::getSingleton() {
		return *(getSingletonPtr());
	}

	ScriptEngine::ScriptEngine()
  : Logger("ScriptEngine")
  {
		mLuaLog = new Logger("Lua");
    mUpdater = &ScriptEngine::updateNothing;
    mLuaState = 0;
    mCEGUILua = 0;
    mTimer = 0;
    fReportIsShown = false;
    fCorruptState = false;
		fSetup = false;

    mCEGUILua = &CEGUI::LuaScriptModule::create();
	}

	ScriptEngine::~ScriptEngine() {
		cleanup();

    mLog->infoStream() << "shutting down.";
    delete mLuaLog;
    mLuaLog = 0;
	}

	bool ScriptEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		CEGUI::System::getSingleton().setScriptingModule(mCEGUILua);

		mLuaState = mCEGUILua->getLuaState();
    tolua_Hax_open(mLuaState);
    tolua_Ogre_open(mLuaState);
    tolua_OIS_open(mLuaState);
    // tolua_CEGUI_open(mLuaState);

    mUpdater = &ScriptEngine::updateNothing;

    mTimer = new boost::asio::deadline_timer(GameManager::getSingleton().getIOService());

    bind(EventUID::Unassigned, boost::bind(&ScriptEngine::passToLua, this, _1));

    fReportIsShown = false;
		fSetup = true;
		return true;
	}

  bool ScriptEngine::setup(int inState)
  {
    if (!fSetup)
      setup();

    bool lSuccess = setupIntro();
    mUpdater = &ScriptEngine::updateIntro;

    return lSuccess;
  }

	bool ScriptEngine::cleanup() {
    if (!fSetup)
      return true;

    unbindAll();

    CEGUI::LuaScriptModule::destroy(*mCEGUILua);

		mCEGUILua = 0;
		mLuaState = 0;

    delete mTimer;
    mTimer = 0;

    mUpdater = &ScriptEngine::updateNothing;

    fSetup = false;

		return true;
	}

  void ScriptEngine::callMeAfter(int inSeconds, string_t inFunc)
  {
    mTimer->expires_from_now(boost::posix_time::milliseconds(inSeconds * 1000));
    mTimer->async_wait(boost::bind(&ScriptEngine::luaCallback, this, inFunc));
  }

  void ScriptEngine::luaCallback(string_t inFunc)
  {
    passToLua(inFunc.c_str(), 0);
  }

	bool ScriptEngine::setupIntro() {

		mLog->infoStream() << "setting up Intro & Lobby";

		fSetup = true;
		return true;
	}


	void ScriptEngine::update( unsigned long lTimeElapsed ) {
		processEvents();

		(this->*mUpdater)(lTimeElapsed);
	}

	void ScriptEngine::updateNothing(unsigned long lTimeElapsed) {
  }

	void ScriptEngine::updateIntro(unsigned long lTimeElapsed) {

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "update");
    lua_pushinteger(mLuaState,lTimeElapsed);
		if(lua_isfunction(mLuaState, 1))
		{
      int ec = lua_pcall(mLuaState, 1, 0, 0);
      if (ec != 0)
      {
        // there was a lua error, dump the state and shut down the instance
        reportError();
        return;
      }

		} else {
      mLog->errorStream() << "could not find Lua updater!";
    }
	}


	void ScriptEngine::loadResources() {
	}

	lua_State* ScriptEngine::getLuaState() {
		return mLuaState;
	}

	log4cpp::Category* ScriptEngine::getLuaLog() { return mLuaLog->getLog(); }

	void ScriptEngine::luaLog(string_t inMsg) {
		ScriptEngine::getSingletonPtr()->getLuaLog()->infoStream() << inMsg;
	}

	void ScriptEngine::runScript(const char* inScript) {
		try {
			CEGUI::System::getSingleton().executeScriptFile(inScript);
		} catch (CEGUI::Exception& e) {
			mLog->errorStream() << "Could not execute script " << inScript << "; " << e.what();
		} catch (std::exception& e) {
			mLog->errorStream() << "Could not execute script `" << inScript
				<< "' out of an unexpected exception; " << e.what();
		}
	}
	bool ScriptEngine::passToLua(const Event& inEvt) {

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "processEvt");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "could not find Lua event processor!";
      reportError();
      return false;
		}

		tolua_pushusertype(mLuaState,(void*)&inEvt,"Hax::Event");

    int ec = lua_pcall(mLuaState, 1, 1, 0);
    if (ec != 0)
    {
      reportError();
      return false;
    }

		bool result = lua_toboolean(mLuaState, lua_gettop(mLuaState));
		lua_remove(mLuaState, lua_gettop(mLuaState));

		return result;
	}

  bool ScriptEngine::passToLua(const char* inFunc, int argc, ...) {
    if (fCorruptState)
    {
      mLog->warnStream() << "Lua state is corrupt, bailing out on method call " << inFunc;
      return false;
    }

    va_list argp;
    va_start(argp, argc);

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "arbitrary");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "could not find Lua arbitrary functor " << inFunc << "!";
      //~ reportError();
      unbind(EventUID::Unassigned);
      mUpdater = &ScriptEngine::updateNothing;
      return false;
			//lua_pop(mLuaState,1);
			//return true;
		}

    lua_pushfstring(mLuaState, inFunc);
    for (int i=0; i < argc; ++i) {
      const char* argtype = (const char*)va_arg(argp, const char*);
      void* argv = (void*)va_arg(argp, void*);
      tolua_pushusertype(mLuaState,argv,argtype);
    }

    int ec = lua_pcall(mLuaState, argc+1, 1, 0);
    if (ec != 0)
    {
      // there was a lua error, dump the state and shut down the instance
      reportError();
      return false;
    }

		bool result = lua_toboolean(mLuaState, lua_gettop(mLuaState));
		lua_remove(mLuaState, lua_gettop(mLuaState));

    va_end(argp);
    return true;
  }

  void ScriptEngine::reportError()
  {
    // pop the error msg from the stack
    string_t lError = lua_tostring(mLuaState, lua_gettop(mLuaState));

    fCorruptState = true;

    // unbind any lua callers
    unbind(EventUID::Unassigned);
    mUpdater = &ScriptEngine::updateNothing;

    UIEngine::getSingletonPtr()->reportLuaError(lError);
    mLog->errorStream() << "Lua Error: " << lError;
    assert(false);
    return;

    // don't flood error reports, show only one at a time
    if (fReportIsShown)
      return;

    // now we attempt to report the error, in the case where we can't get to the
    // reporter function or call it successfully, the client has encountered
    // a fatal error and can not be recovered, thus we throw lua_runtime_error()

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "arbitrary");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "Fatal - could not call Lua error reporter, shutdown is inevitable";
      throw lua_runtime_error(lError);
		}

		lua_pushfstring(mLuaState,"UI.reportLuaError");
		lua_pushfstring(mLuaState,lError.c_str());

    int ec = lua_pcall(mLuaState, 1, 0, 0);
    if (ec != 0)
    {
			mLog->errorStream() << "Fatal - failed to report Lua error, shutdown is inevitable";
      throw lua_runtime_error(lError);
    }

    fReportIsShown = true;

    // throw lua_runtime_error(lua_tostring(mLuaState, lua_gettop(mLuaState)));
    // assert(false);
  }

  void ScriptEngine::_reportAccepted()
  {
    fReportIsShown = false;
  }


	bool ScriptEngine::mouseMoved( const OIS::MouseEvent &e )
	{
		//return passToLua("onMouseMoved", 1, "OIS::MouseEvent", &e);
		return true;
	}

	bool ScriptEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("Input.onMousePressed", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
	}

	bool ScriptEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("Input.onMouseReleased", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
    //CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    //return (window && window->isVisible() && window->getAlpha() > 0.0f && (window->getType() != "DefaultWindow"));
  }

	void ScriptEngine::keyReleased( const OIS::KeyEvent &e ) {
    passToLua("Input.onKeyReleased", 1, "OIS::KeyEvent", &e);
	}
	void ScriptEngine::keyPressed( const OIS::KeyEvent &e ) {
		passToLua("Input.onKeyPressed", 1, "OIS::KeyEvent", &e);
	}

  string_t ScriptEngine::getScriptPathPrefix() const {
    return FileManager::getSingleton().getScriptsPath().string();
  }

  string_t ScriptEngine::getModulePathPrefix() const {
    return FileManager::getSingleton().getPluginsPath().string();
  }

}
