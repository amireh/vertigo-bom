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

#include "Hax/Intro.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/EventManager.hpp"
// #include "Hax/NetworkManager.hpp"
#include "Hax/UIEngine.hpp"
#include "Hax/GfxEngine.hpp"
#include "Hax/ScriptEngine.hpp"
#include "Hax/FxEngine.hpp"

using namespace Ogre;
namespace Hax
{

	Intro* Intro::mIntro = 0;

	Intro::Intro()
  : Logger("Intro"),
    mStrand(GameManager::getSingleton().getIOService()),
    fSetup(false)
  {
    mId = GameState::State::Intro;
	}

	Intro::~Intro() {
	}

  Intro* Intro::getSingletonPtr( void ) {
    if( !mIntro )
        mIntro = new Intro();

    return mIntro;
  }

  Intro& Intro::getSingleton( void ) {
    return *getSingletonPtr();
  }

	void Intro::enter( void ) {

    //~ mWorker = new boost::thread(boost::bind(&boost::asio::io_service::run, &GameManager::getSingleton().getIOService()));

		mLog->infoStream() << "---- Entering ----";

		mEvtMgr = EventManager::getSingletonPtr();
    mEvtMgr->clear();
		// mNetMgr = NetworkManager::getSingletonPtr();

		// init engines
		mGfxEngine = GfxEngine::getSingletonPtr();
    mGfxEngine->setup();

    mFxEngine = FxEngine::getSingletonPtr();
    mFxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup(mId);

		// start the interface chain
		mScriptEngine->runScript("Intro/EntryPoint.lua");
    mScriptEngine->passToLua("Intro.onEnter", 0);

		mLog->infoStream() << "Initialized successfully.";
    fSetup = true;
	}


	void Intro::exit( void ) {

    if (fSetup)
      mScriptEngine->passToLua("Intro.onExit", 0);

		mLog->infoStream() << "---- Exited ----";

    unbindAll();
	}

	void Intro::update( unsigned long lTimeElapsed ) {

		mEvtMgr->update();

		processEvents();

		mGfxEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
    mFxEngine->update(lTimeElapsed);
	}

	void Intro::keyPressed( const OIS::KeyEvent &e )
	{
    mUIEngine->keyPressed(e);
    mScriptEngine->keyPressed(e);
	}

	void Intro::keyReleased( const OIS::KeyEvent &e ) {
    mUIEngine->keyReleased(e);
    mScriptEngine->keyReleased(e);

		switch (e.key) {
			case OIS::KC_ESCAPE:
				this->requestShutdown();
				break;
		}
	}

	bool Intro::mouseMoved( const OIS::MouseEvent &e )
	{
		// Update CEGUI with the mouse motion
    mUIEngine->mouseMoved(e);
    mGfxEngine->mouseMoved(e);
    return true;
	}

	bool Intro::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mousePressed(e, id);
    mGfxEngine->mousePressed(e, id);
    return true;
	}

	bool Intro::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mouseReleased(e, id);
    mGfxEngine->mouseReleased(e, id);
    return true;
	}

	void Intro::pause( void ) {
	}

	void Intro::resume( void ) {
	}

} // end of namespace
