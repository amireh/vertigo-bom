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

#include "Hax/Hax.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/Intro.hpp"

using namespace Hax;
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT ) {
#else
  int main( int argc, char **argv ) {
#endif
// Apple
#if (OGRE_PLATFORM == OGRE_PLATFORM_APPLE) && __LP64__
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    mAppDelegate = [[AppDelegate alloc] init];
    [[NSApplication sharedApplication] setDelegate:mAppDelegate];
    int retVal = NSApplicationMain(argc, (const char **) argv);

    [pool release];

    return retVal;
#else

    HaxInit();

// Win32 && Linux
    GameManager *gameManager = GameManager::getSingletonPtr();
    try {
      // Initialise the game and switch to the first state
      gameManager->startGame(Intro::getSingletonPtr());

    }
    catch ( Ogre::Exception& ex ) {
# if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox( NULL, ex.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL );
# else
      std::cerr << "An exception has occured: " << ex.getFullDescription();
# endif
    } catch (std::exception& e) {
      Ogre::String errMsg = e.what();
      HAX_LOG->errorStream() << errMsg;
      gameManager->_cleanup();
    }

    delete gameManager;
    HaxCleanup();
    return 0;
#endif
  }

