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

#ifndef H_HAX_INTRO_H
#define H_HAX_INTRO_H

#include "Hax/GameState.hpp"
#include "Hax/EventListener.hpp"
#include "Hax/Logger.hpp"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <map>
#include <list>

namespace Hax
{

  class Engine;
  class GfxEngine;
  class FxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  // class NetworkManager;
  /*!
   * @class Intro
   * @brief
   * Main Menu state, handles non-Combat game tasks.
   */
	class Intro : public GameState, public EventListener, public Logger {
	public:

		void enter( void );
		void exit( void );

		void pause( void );
		void resume( void );
		void update( unsigned long lTimeElapsed );

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		static Intro* getSingletonPtr( void );
		static Intro& getSingleton();

	protected:
    boost::asio::strand mStrand;

	private:
		Intro( void );
		virtual ~Intro();
		Intro( const Intro& );
		Intro & operator = ( const Intro& );

		GfxEngine		*mGfxEngine;
		UIEngine		*mUIEngine;
    FxEngine      *mFxEngine;
		ScriptEngine	*mScriptEngine;
		EventManager	*mEvtMgr;
		// NetworkManager  *mNetMgr;

    bool fSetup;

		static Intro    *mIntro;
	};
} // end of namespace
#endif
