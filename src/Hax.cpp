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
#include "Hax/FileManager.hpp"
#include "Hax/LogManager.hpp"
#include "Hax/Configurator.hpp"

namespace Hax {

  void HaxInit()
  {
    // set up the logger
    FileManager::getSingleton().resolvePaths();
    LogManager::getSingleton().init();
    LogManager::getSingleton().mConfig.silent = true;
    LogManager::getSingleton().configure();

    Configurator::subscribe(&LogManager::getSingleton(), "Log Manager");
  }

  void HaxCleanup()
  {
    LogManager::getSingleton().cleanup();
  }

}
