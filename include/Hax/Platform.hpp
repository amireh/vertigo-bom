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

#ifndef H_HAX_PLATFORM_H
#define H_HAX_PLATFORM_H

/* Finds the current platform
 * Note: shamelessly stolen from the Ogre3D gurus' code in OgrePlatform.h */
#define HAX_PLATFORM_WIN32 1
#define HAX_PLATFORM_LINUX 2
#define HAX_PLATFORM_APPLE 3
#define HAX_PLATFORM_SYMBIAN 4
#define HAX_PLATFORM_IPHONE 5

#if defined( __SYMBIAN32__ )
#   define HAX_PLATFORM HAX_PLATFORM_SYMBIAN
#elif defined( __WIN32__ ) || defined( _WIN32 )
#   define HAX_PLATFORM HAX_PLATFORM_WIN32
#elif defined( __APPLE_CC__) || defined(__APPLE__)
#   if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 30000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 30000
#       define HAX_PLATFORM HAX_PLATFORM_IPHONE
#   else
#       define HAX_PLATFORM HAX_PLATFORM_APPLE
#   endif
#else
#   define HAX_PLATFORM HAX_PLATFORM_LINUX
#endif

#endif
