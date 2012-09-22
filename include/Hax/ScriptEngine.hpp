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

#ifndef H_HAX_SCRIPT_ENGINE_H
#define H_HAX_SCRIPT_ENGINE_H

#include "Hax/Engine.hpp"
#include "Hax/Logger.hpp"
#include "Hax/EventListener.hpp"
#include "Hax/InputListener.hpp"

#include <stdarg.h>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

// #include <CEGUI/System.h>
#include <CEGUI/CEGUI.h>
// #include <CEGUI/Exceptions.h>

// Lua
extern "C" {
	#include "lua.h"
	#include "lualib.h"
}

#include "tolua++.h"

// #include <CEGUI/ScriptModules/Lua/ScriptModule.h>
#include <CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h>

namespace Hax {

  class Entity;
	/*! \class ScriptEngine
	 *	\brief
	 *	Manages the Lua module, loads Script resources, listens to and passes off
	 *	Events fro and to Lua.
	 */
	class ScriptEngine : public Engine, public EventListener, public InputListener, public Logger {

	public:
		virtual ~ScriptEngine();
		static ScriptEngine* getSingletonPtr();
		static ScriptEngine& getSingleton();

		virtual bool setup();
		virtual bool setup(int inState);
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void runScript(const char* inScript);
		lua_State* getLuaState();
		static void luaLog(std::string inMsg);
		log4cpp::Category* getLuaLog();

		bool passToLua(const Event& inEvt);
    bool passToLua(const char* inFunc, int argc, ...);

    string_t getScriptPathPrefix() const;
    string_t getModulePathPrefix() const;

    void callMeAfter(int inSeconds, std::string func);

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    void _reportAccepted();

	protected:

    void luaCallback(std::string inFunc);

		lua_State* mLuaState;
		CEGUI::LuaScriptModule* mCEGUILua;
		Logger *mLuaLog;
		void loadResources();

		bool setupIntro();

		void updateNothing(unsigned long lTimeElapsed);
		void updateIntro(unsigned long lTimeElapsed);

    /**
     * retrieves the error message from the lua stack
     **/
    void reportError();

    // if this flag is set to true, then reportError() will do nothing until
    // the user accepts the error report (this is used to prevent flooding)
    // the flag is turned off by Lua calling ScriptEngine::reportAccepted()
    bool fReportIsShown;

    bool fCorruptState;

    boost::asio::deadline_timer* mTimer;

    void pushUserData(void* inData, std::string inFullyQualifiedCppType);

	private:
		static ScriptEngine* __instance;
		ScriptEngine();
		ScriptEngine(const ScriptEngine& src);
		ScriptEngine& operator=(const ScriptEngine& rhs);

		void (ScriptEngine::*mUpdater)(unsigned long);
	};
}
#endif
