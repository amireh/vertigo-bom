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

#ifndef H_HAX_EXCEPTION_H
#define H_HAX_EXCEPTION_H

#include <exception>
#include <stdexcept>

namespace Hax {

	class BadConversion : public std::runtime_error {
	public:
		inline BadConversion(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

	class BadStream : public std::runtime_error {
	public:
		inline BadStream(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

	class UnknownEvent : public std::runtime_error {
	public:
		inline UnknownEvent(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

	class BadEvent : public std::runtime_error {
	public:
		inline BadEvent(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

	class BadFormat : public std::runtime_error {
	public:
		inline BadFormat(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

  class UnidentifiedResource : public std::runtime_error {
  public:
    inline UnidentifiedResource(const std::string& s)
    : std::runtime_error(s)
    { }
  };

	class IntegrityViolation : public std::runtime_error {
	public:
		inline IntegrityViolation(const std::string& s)
		: std::runtime_error(s)
		{ }
	};

  class lua_runtime_error : public std::runtime_error {
    public:

    lua_runtime_error(std::string msg)
    : std::runtime_error(msg) {
    }
    virtual ~lua_runtime_error() throw() {
    }
  };
} // end of namespace Pixy

#endif
