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

#ifndef H_HAX_UI_ENGINE_H
#define H_HAX_UI_ENGINE_H

#include "Hax/Hax.hpp"
#include "Hax/Engine.hpp"
#include "Hax/EventListener.hpp"
#include "Hax/InputListener.hpp"
#include "Hax/Logger.hpp"
#include "Hax/EventManager.hpp"

#include <CEGUI/CEGUI.h>
// #include <CEGUI/InputEvent.h>
#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h>
// #include <CEGUI/System.h>
// #include <CEGUI/SchemeManager.h>

#include <Ogre.h>

#include <boost/filesystem.hpp>

namespace Hax {

	/*	\class UIEngine
	 *	\brief
	 *	Loads and unloads UISheets, manages CEGUI system, and handles UI related operations
	 *
	 *	\remark
	 *	At the moment, the UIEngine acts as a manager for UISheets, however,
	 *	the sheets are ought to be handled from within the LUA subsystem.
	 */
	class UIEngine : public Engine, public EventListener, public InputListener, public Logger {

	public:
		virtual ~UIEngine();
		static UIEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID);

    void setMargin(CEGUI::Window*, CEGUI::UBox&);

    void connectAnimation(CEGUI::Window*, std::string inAnim);

    void reportLuaError(std::string const& inMsg);

	protected:
		const char* getDataPathPrefix() const;

		bool loadResources();

		CEGUI::OgreRenderer		*mOgreRenderer;
		CEGUI::System			*mUISystem;

		EventManager			*mEvtMgr;

	private:
		UIEngine();
		UIEngine(const UIEngine& src);
		UIEngine& operator=(const UIEngine& rhs);

		static UIEngine* __instance;
	};
}
#endif
