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

#include "Hax/UIEngine.hpp"
#include "Hax/EventManager.hpp"
#include "Hax/Utility.hpp"
#include "Hax/GameManager.hpp"

// CEGUI
// For some reason, on OS X CEGUI.h complains that CFBundleRef is undeclared
// so we include the CoreFoundation framework to get around that
// hack date: 09/07/2011
// #if HAX_PLATFORM == HAX_PLATFORM_APPLE
// # include <CoreFoundation/CoreFoundation.h>
// #endif

namespace Hax {
	UIEngine* UIEngine::__instance = NULL;

	UIEngine* UIEngine::getSingletonPtr() {
		if( !__instance ) {
		    __instance = new UIEngine();
		}

		return __instance;
	}

	UIEngine::UIEngine()
  : Logger("UIEngine")
  {
		mLog->infoStream() << "firing up";
		fSetup = false;
	}

	UIEngine::~UIEngine() {
    mLog->infoStream() << "shutting down";

    cleanup();

		if (fSetup) {
      mLog->debugStream() << "destroying all windows";
			fSetup = false;
		}
	}

	bool UIEngine::cleanup() {
    if (!fSetup)
      return true;

    CEGUI::WindowManager::getSingleton().destroyAllWindows();

    mLog->debugStream() << "destroying system";
    mOgreRenderer->destroySystem();

    mOgreRenderer = NULL; mUISystem = NULL;

    fSetup = false;

		return true;
	}

	CEGUI::MouseButton UIEngine::convertButton(OIS::MouseButtonID buttonID)
	{
		switch (buttonID)
		{
			case OIS::MB_Left:
				return CEGUI::LeftButton;

			case OIS::MB_Right:
				return CEGUI::RightButton;

			case OIS::MB_Middle:
				return CEGUI::MiddleButton;

			default:
				return CEGUI::LeftButton;
		}
	}

	const char* UIEngine::getDataPathPrefix() const
	{
		static char dataPathPrefix[PATH_MAX];

		return dataPathPrefix;
	}

	bool UIEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mEvtMgr = EventManager::getSingletonPtr();

		mLog->infoStream() << "initting CEGUI system & CEGUIOgreRenderer.";

		if (CEGUI::System::getSingletonPtr())
			throw CEGUI::InvalidRequestException("OgreRenderer::bootstrapSystem: "
										  "CEGUI::System object is already initialised.");


		CEGUI::DefaultLogger* lUILog = new CEGUI::DefaultLogger();

    using boost::filesystem::path;
		std::string lUILogPath =
      (path(FileManager::getSingleton().getLogPath()) / "CEGUI.log").make_preferred().string();
		lUILog->setLogFilename(lUILogPath, true);

		mOgreRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
		mUISystem = &CEGUI::System::getSingleton();

    lUILog = 0;

		// load resources
		loadResources();

		mLog->infoStream() << "Set up!";

		fSetup = true;
		return true;
	}


	bool UIEngine::loadResources() {

		mLog->infoStream() << "Loading resources...";
		using namespace Ogre;
		ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();

		// set the default resource groups to be used
		// CEGUI::ImagesetManager::setDefaultResourceGroup("imagesets");
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::Scheme::setDefaultResourceGroup("schemes");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");

		// setup default group for validation schemas
		CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
		if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
			parser->setProperty("SchemaDefaultResourceGroup", "schemas");

    // CEGUI::AnimationManager::getSingleton().loadAnimationsFromXML("animations.xml");

		// load LUA script
		return true;
	}

	void UIEngine::update( unsigned long lTimeElapsed ) {
		mUISystem->injectTimePulse(lTimeElapsed * 0.001f);

		processEvents();
	}

	bool UIEngine::mouseMoved( const OIS::MouseEvent &e )
	{
    // return mUISystem->getDefaultGUIContext().injectMouseMove(e.state.X.rel, e.state.Y.rel);
		return mUISystem->injectMouseMove(e.state.X.rel, e.state.Y.rel);
	}

	bool UIEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // return mUISystem->getDefaultGUIContext().injectMouseButtonDown(convertButton(id));
		return mUISystem->injectMouseButtonDown(convertButton(id));
	}

	bool UIEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // return mUISystem->getDefaultGUIContext().injectMouseButtonUp(convertButton(id));
		return mUISystem->injectMouseButtonUp(convertButton(id));
  }

	void UIEngine::keyReleased( const OIS::KeyEvent &e ) {
    // mUISystem->getDefaultGUIContext().injectKeyUp((CEGUI::Key::Scan)e.key);
    mUISystem->injectKeyUp((CEGUI::Key::Scan)e.key);
	}
	void UIEngine::keyPressed( const OIS::KeyEvent &e ) {
    // mUISystem->getDefaultGUIContext().injectKeyDown((CEGUI::Key::Scan)e.key);
    mUISystem->injectKeyDown((CEGUI::Key::Scan)e.key);
	}

  void UIEngine::setMargin(CEGUI::Window* win, CEGUI::UBox& margin) {
    win->setMargin(margin);
  }


  void UIEngine::connectAnimation(CEGUI::Window* inWindow, std::string inAnim) {

    CEGUI::AnimationInstance* instance = CEGUI::AnimationManager::getSingleton().instantiateAnimation(inAnim);

    // after we instantiate the animation, we have to set its target window
    instance->setTargetWindow(inWindow);
    inWindow->subscribeEvent(
      CEGUI::Window::EventShown,
      CEGUI::Event::Subscriber(&CEGUI::AnimationInstance::handleStart, instance));
  }


  void UIEngine::reportLuaError(std::string const& inMsg)
  {
    // std::string lWindowName = "Elementum/LuaErrorBox";
    // CEGUI::WindowManager *lWindowMgr = CEGUI::WindowManager::getSingletonPtr();
    // if (!lWindowMgr->isWindowPresent(lWindowName))
    // {
      // mLog->errorStream() << "Could not find LuaErrorBox window, unable to report message: " << inMsg;
      // return;
    // }

    // CEGUI::Window* lErrorBox = lWindowMgr->getWindow("Elementum/LuaErrorBox");
    // lErrorBox->show();
    // lErrorBox->getChildAtIdx(0)->setText(inMsg);
  }

}
