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

#ifndef H_HAX_HAX_H
#define H_HAX_HAX_H

#include "Hax/Platform.hpp"

#include <cmath>
#include <exception>
#include <stdint.h>
#include <malloc.h>
#include <cstdlib>
#include <string.h>
#include <signal.h>

// Hax
#include "Hax/Exception.hpp"
#include "Hax/Log.hpp"

#define HAX_APP_NAME          "Vertigo: The Brink of Madness"
#define HAX_APP_NAME_STR      string_t(HAX_APP_NAME)
#define HAX_APP_NAME_CFG      "Vertigo"
#define HAX_APP_NAME_CFG_STR  string_t(HAX_APP_NAME_CFG)

#define HAX_APP_VERSION_MAJOR "0"
#define HAX_APP_VERSION_MINOR "1"
#define HAX_APP_VERSION_PATCH "1"
#define HAX_APP_VERSION_BUILD "a1"
#define HAX_APP_VERSION       HAX_APP_VERSION_MAJOR + "." + \
                              HAX_APP_VERSION_MINOR + "." + \
                              HAX_APP_VERSION_PATCH + "-" + \
                              HAX_APP_VERSION_BUILD
#define HAX_APP_VERSION_STR   string_t(HAX_APP_VERSION)

namespace Hax
{
	typedef unsigned short  ushort;
  typedef std::string     string_t;

  void HaxInit();
  void HaxCleanup();

} // end of namespace Hax
#endif
