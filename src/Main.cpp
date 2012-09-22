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
int main( int argc, char **argv ) {
  HaxInit();

  GameManager *gameManager = GameManager::getSingletonPtr();
  try {
    // Initialise the game and switch to the first state
    gameManager->startGame(Intro::getSingletonPtr());
  } catch ( Ogre::Exception& ex ) {
    std::cerr << "An exception has occured: " << ex.getFullDescription();
  } catch (std::exception& e) {
    Ogre::String errMsg = e.what();
    HAX_LOG->errorStream() << errMsg;
    gameManager->_cleanup();
  }

  delete gameManager;
  HaxCleanup();

  return 0;
}

