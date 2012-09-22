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

#ifndef H_HAX_GAME_MANAGER_H
#define H_HAX_GAME_MANAGER_H

#include "Hax/Hax.hpp"
#include "Hax/Logger.hpp"
#include "Hax/Configurable.hpp"
#include "Hax/Configurator.hpp"
#include "Hax/FileManager.hpp"
#include "Hax/InputManager.hpp"
#include "Hax/EventManager.hpp"

#include <map>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

// OGRE
#include <Ogre.h>
#include <OgreConfigFile.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>

namespace Hax
{
	class GameState;

	/**
   * @class GameManager
   *
	 * @brief
	 * Runs and handles the flow between Hax::GameState s,
	 * and acts as an input listener and dispatcher.
	 */
	class GameManager
  : public Logger,
    public Configurable,
    public OIS::KeyListener,
    public OIS::MouseListener,
    public Ogre::WindowEventListener
  {
	public:
		virtual ~GameManager();

		static GameManager* getSingletonPtr();
		static GameManager& getSingleton();

    /**
     * @note Only called manually when running on OS X.
     */
    void _setup();

    void _cleanup();

    /** Loads StateGame game state to start the game. */
    void startGame(/*int argc, char** argv*/ GameState* inState);

    /** Ticks everything! */
    void _update();

    /**
     *  Shuts down current game state and loads another.
     *  @param
     *  inState   Instance of GameState to be loaded.
     */
    void changeState(GameState *inState);

    /**
     * Loads a game state while another is running, which gets paused.
     *
     * @param inState Instance of GameState to be loaded.
     *
     * @note
     * Current running state must have a functional implementation
     * of GameState::pause() for this context switching to work properly.
     */
    void pushState(GameState *inState);

    /**
     * Reloads an earlier running GameState and shuts down the current one.
     *
     * @note
     * If the stack contains only one state, the system will shutdown
     * upon calling this method.
     */
    void popState();

    /** Shuts down the system, consequently shutting down all running game states. */
    void requestShutdown();

		GameState* getCurrentState();

    /** Are we in the middle of a shutdown request? */
		bool isShuttingDown() const;

    Ogre::RenderWindow* getRenderWindow() const;

    boost::asio::io_service& getIOService();

    /** Overridden from Hax::Configurable */
    void setOption(const string_t&, const string_t&);

  private:
		static GameManager *__instance;

  private:
    GameManager();
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;


    void resolvePaths();

    /**
		 * Prepares Ogre for use by the game components
		 *	\note
		 *	This method is called internally within startGame().
		 *
		 *	Ogre Root, RenderWindow, Resource Groups, and SceneManager
		 *	are set up here.
		 */
		bool configureGame();

		void loadRenderSystems();

    /**
		 * Loads resources for use by the Ogre engine
     *
     * @note
     * This method is called internally within startGame().
		 */
		void setupResources(std::string inResourcesPath);

    /**
		 *  OIS key input event handler/dispatcher method
		 *	\note
		 *	Events received here are dispatched to the
		 *	current running GameState for processing.
		 */
		bool keyPressed( const OIS::KeyEvent &e );

    /**
		 *  OIS key input event handler/dispatcher method
		 *	\note
		 *	Events received here are dispatched to the
		 *	current running GameState for processing.
		 */
		bool keyReleased( const OIS::KeyEvent &e );

    /**
		 *  OIS mouse input event handler/dispatcher method
		 *	\note
		 *	Events received here are dispatched to the
		 *	current running GameState for processing.
		 */
		bool mouseMoved( const OIS::MouseEvent &e );

    /**
		 *  OIS mouse input event handler/dispatcher method
		 *	\note
		 *	Events received here are dispatched to the
		 *	current running GameState for processing.
		 */
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    /**
		 *  OIS mouse input event handler/dispatcher method
		 *	\note
		 *	Events received here are dispatched to the
		 *	current running GameState for processing.
		 */
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		Ogre::Root			    *mRoot;
		Ogre::RenderWindow	*mRenderWindow;
		InputManager		    *mInputMgr;
		GameState           *mCurrentState;

		unsigned long lTimeLastFrame, lTimeCurrentFrame, lTimeSinceLastFrame;

		bool fShuttingDown; /// do we want to shutdown?
    bool fSetup; /// are we set up?

    typedef std::vector<GameState*> states_t;
		states_t mStates;

    boost::asio::io_service       mIOService;
    boost::asio::io_service::work mWork;
    boost::thread                 *mWorker;

    struct config_t {

    } mConfig;
	};
} // end of namespace

#endif
