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

#include "Hax/GameManager.hpp"
#include "Hax/Utility.hpp"
#include "Hax/GameState.hpp"
#include "Hax/EventManager.hpp"
#include "Hax/log4cpp/HaxLogLayout.hpp"

#include <boost/filesystem.hpp>

#include "Hax/UIEngine.hpp"
#include "Hax/GfxEngine.hpp"
#include "Hax/FxEngine.hpp"
#include "Hax/ScriptEngine.hpp"
#include "Hax/InputManager.hpp"
#include "Hax/Ogre/OgreSdkTrays.h"
#include "Hax/binreloc/binreloc.h"

using namespace Ogre;

namespace Hax {

	GameManager* GameManager::__instance;

	GameManager::GameManager()
  : Logger("GameMgr"),
    Configurable({"Game Manager"}),
    mIOService(),
    mWork(mIOService),
    mWorker(0),
    mRoot(0),
    mInputMgr(0),
    fShuttingDown(false),
    fSetup(false)
  {
	}

	GameManager::~GameManager() {
	}

  boost::asio::io_service& GameManager::getIOService() {
    return mIOService;
  }

  void GameManager::_setup() {

    FileManager &lFileMgr = FileManager::getSingleton();

    // Load configuration
    {
      string_t json_cfg;
      if (lFileMgr.getResource((lFileMgr.getCfgPath() / "Vertigo.cfg").make_preferred().string(), json_cfg))
      {
        Configurator cfg(json_cfg); cfg.run();
      } else {
        mLog->errorStream() << "configuration file could not be loaded";
      }
    }

    mWorker = new boost::thread(boost::bind(&boost::asio::io_service::run, &mIOService));

    // set up Ogre paths
    string_t lPathOgreRes, lPathOgrePlugins, lPathOgreCfg, lPathOgreLog;
    // string_t lSuffix = lFileMgr.getSuffix();

    lPathOgreRes      = (lFileMgr.getCfgPath() / string_t("resources.cfg")).make_preferred().string();
    lPathOgrePlugins  = (lFileMgr.getCfgPath() / string_t("plugins.cfg")).make_preferred().string();
    lPathOgreCfg      = (lFileMgr.getCfgPath() / "ogre.cfg").make_preferred().string();
    lPathOgreLog      = (lFileMgr.getLogPath() / "Ogre.log").make_preferred().string();

    mRoot = OGRE_NEW Root(lPathOgrePlugins, lPathOgreCfg, lPathOgreLog);
    if (!mRoot) {
    	throw Ogre::Exception( Ogre::Exception::ERR_INTERNAL_ERROR,
    						  "Error - Couldn't initalize OGRE!",
    						  HAX_APP_NAME_STR + " - Error");
    }
    //loadRenderSystems();

    // Setup and configure game
    if( !this->configureGame() ) {
        // If game can't be configured, throw exception and quit application
        throw Ogre::Exception( Ogre::Exception::ERR_INTERNAL_ERROR,
    						  "Error - Couldn't Configure Renderwindow",
    						  HAX_APP_NAME_STR + " - Error" );
        return;
    }

    // Setup input & register as listener
    mInputMgr = InputManager::getSingletonPtr();
    mRenderWindow = mRoot->getAutoCreatedWindow();
    mInputMgr->initialise( mRenderWindow );
    WindowEventUtilities::addWindowEventListener( mRenderWindow, this );

    // load initial resources
    this->setupResources(lPathOgreRes);

    mInputMgr->addKeyListener( this, "GameManager" );
    mInputMgr->addMouseListener( this, "GameManager" );

    EventManager::getSingletonPtr();
    GfxEngine::getSingletonPtr()->setup();
    UIEngine::getSingletonPtr()->setup();
    FxEngine::getSingletonPtr()->setup();
    ScriptEngine::getSingletonPtr()->setup();

    ScriptEngine::getSingletonPtr()->runScript("Hax.lua");
    ScriptEngine::getSingletonPtr()->passToLua("Hax.onEnter", 0);

    // Change to first state
    //~ this->changeState( Intro::getSingletonPtr() );
    //~ this->changeState( Intro::getSingletonPtr() );

    // lTimeLastFrame remembers the last time that it was checked
    // we use it to calculate the time since last frame

    lTimeLastFrame = 0;
    lTimeCurrentFrame = 0;
    lTimeSinceLastFrame = 0;

    mRoot->getTimer()->reset();

    fSetup = true;
  }

	void GameManager::startGame(GameState* inState) {

    this->_setup();
    this->changeState(inState);

		// main game loop
		while( !fShuttingDown ) {
      _update();
		}

    this->_cleanup();
	}

  void GameManager::_cleanup()
  {
    if (!fSetup)
      return;

    // Clean up all the states
		while( !mStates.empty() ) {
		    mStates.back()->exit();
		    mStates.pop_back();
		}

    if (fSetup)
    {
      if (mLog)
        mLog->infoStream() << "cleaning up the scripts";

      // make the scripts clean up
      ScriptEngine::getSingletonPtr()->passToLua("Hax.onExit", 0);

      if (mLog)
        mLog->infoStream() << "tearing down all engines";

      delete GfxEngine::getSingletonPtr();
      delete FxEngine::getSingletonPtr();
      delete UIEngine::getSingletonPtr();
      delete ScriptEngine::getSingletonPtr();
      delete EventManager::getSingletonPtr();
    }

		if( mInputMgr )
      delete mInputMgr;
    mInputMgr = 0;

		if( mRoot )
      delete mRoot;
    mRoot = 0;

    mLog->infoStream() << "++++++ " << HAX_APP_NAME << " cleaned up successfully ++++++";

    if (mWorker)
    {
      mIOService.stop();
      mWorker->join();
      delete mWorker;
    }
    mWorker = 0;

    fSetup = false;
  }

	Ogre::RenderWindow* GameManager::getRenderWindow() const {
    return mRenderWindow;
	}

  void GameManager::_update() {
	  // calculate time since last frame and remember current time for next frame
    lTimeCurrentFrame = mRoot->getTimer()->getMilliseconds();
    lTimeSinceLastFrame = lTimeCurrentFrame - lTimeLastFrame;
    lTimeLastFrame = lTimeCurrentFrame;

    // update input manager
    mInputMgr->capture();

    // cpdate current state
    mStates.back()->update( lTimeSinceLastFrame );

		WindowEventUtilities::messagePump();

		// render next frame
	  mRoot->renderOneFrame();
  }

	bool GameManager::configureGame() {

		// Load config settings from ogre.cfg
		if( !mRoot->restoreConfig() ) {
		    // If there is no config file, show the configuration dialog
		    if( !mRoot->showConfigDialog() ) {
		        return false;
		    }
		}

		// Initialise and create a default rendering window
		mRenderWindow = mRoot->initialise( true, HAX_APP_NAME_STR + " Version " + HAX_APP_VERSION );

		// Initialise resources
		//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

		// Create needed scenemanagers
		Ogre::SceneManager *mSceneMgr = mRoot->createSceneManager( "DefaultSceneManager", "LoadingScene" );
		Ogre::Camera *mCamera = mSceneMgr->createCamera("LoadingCamera");
		mRenderWindow->addViewport(mCamera, -1);

		return true;
	}

	void GameManager::setupResources(std::string inPath) {

		// Load resource paths from config file
		ConfigFile cf;
		cf.load( inPath );

		// Go through all settings in the file
		ConfigFile::SectionIterator itSection = cf.getSectionIterator();

		String sSection, sType, sArch;
		while( itSection.hasMoreElements() ) {
		    sSection = itSection.peekNextKey();

		    ConfigFile::SettingsMultiMap *mapSettings = itSection.getNext();
		    ConfigFile::SettingsMultiMap::iterator itSetting = mapSettings->begin();
		    while( itSetting != mapSettings->end() ) {
		        sType = itSetting->first;
		        sArch = itSetting->second;
				    ResourceGroupManager::getSingleton().addResourceLocation( sArch, sType, sSection);
		        ++itSetting;
		    }
		}
		// Initialise resources
		ResourceGroupManager::getSingleton().initialiseResourceGroup("Bootstrap");
		OgreBites::SdkTrayManager *mTrayMgr =
		  new OgreBites::SdkTrayManager(HAX_APP_NAME_STR + "/Loader", mRenderWindow, InputManager::getSingletonPtr()->getMouse(), 0);
		//mTrayMgr->showAll();
		mTrayMgr->showLoadingBar(1,1, 1);
		//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("Scripts");
		mTrayMgr->hideLoadingBar();
		delete mTrayMgr;

    // TODO: when do we clean these up?
		//mRenderWindow->removeViewport(-1);
		//mRoot->getSceneManager("LoadingScene")->destroyCamera("LoadingCamera");
		//mRoot->destroySceneManager(mRoot->getSceneManager("LoadingScene"));
	}

	void GameManager::changeState( GameState *inState ) {

		// Cleanup the current state
		if( !mStates.empty() ) {
	    mStates.back()->exit();
	    mStates.pop_back();
		}

		// Store and init the new state
		mCurrentState = inState;
		mStates.push_back( inState );
		mStates.back()->enter();

		// reset our frame timer to eliminate any frame bursts
		// mRoot->getTimer()->reset();
		// lTimeLastFrame = 0;
	}

	void GameManager::pushState( GameState *inState ) {

		// Pause current state
		if( !mStates.empty() ) {
		    mStates.back()->pause();
		}

		mCurrentState = inState;

		// Store and init the new state
		mStates.push_back( inState );
		mStates.back()->enter();

		// reset our frame timer to eliminate any frame bursts
		// mRoot->getTimer()->reset();
		// lTimeLastFrame = 0;
	}

	void GameManager::popState() {
		// Cleanup the current state
		if( !mStates.empty() ) {
		    mStates.back()->exit();
		    mStates.pop_back();
		}

		// Resume previous state
		if( !mStates.empty() ) {
		    mCurrentState = mStates.back();
		    mStates.back()->resume();
		}

		// reset our frame timer to eliminate any frame bursts
		// mRoot->getTimer()->reset();
		// lTimeLastFrame = 0;
	}

	void GameManager::requestShutdown() {
		fShuttingDown = true;
	}

	bool GameManager::keyPressed( const OIS::KeyEvent &e ) {
		mStates.back()->keyPressed( e );

		return true;
	}

	bool GameManager::keyReleased( const OIS::KeyEvent &e ) {
		mStates.back()->keyReleased( e );

		return true;
	}

	bool GameManager::mouseMoved( const OIS::MouseEvent &e ) {
		mStates.back()->mouseMoved( e );

		return true;
	}

	bool GameManager::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mStates.back()->mousePressed( e, id );

		return true;
	}

	bool GameManager::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mStates.back()->mouseReleased( e, id );

		return true;
	}

	GameManager* GameManager::getSingletonPtr() {
		if( !__instance ) {
		    __instance = new GameManager();
		}

		return __instance;
	}

	GameManager& GameManager::getSingleton() {
		return *getSingletonPtr();
	}

	GameState* GameManager::getCurrentState() {
		return mCurrentState;
	}

	bool GameManager::isShuttingDown() const {
    return fShuttingDown;
  };

  void GameManager::setOption(const string_t& key, const string_t& value)
  {
  }

} // end of namespace Hax
