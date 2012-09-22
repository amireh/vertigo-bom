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

#ifndef H_HAX_LOGGABLE_H
#define H_HAX_LOGGABLE_H

namespace Hax
{
	/*!
   * @brief
   * Loggable objects respond to the operator<< for logging to an std::ostream.
	 */
	class Loggable
	{
    public:
		Loggable() {}
		Loggable& operator=(const Loggable& rhs) { return *this; }
		Loggable(const Loggable& src) {}
		virtual ~Loggable() {}

    inline friend std::ostream& operator<<(std::ostream& inStream, Loggable const* inLoggable)
    {
      return inLoggable->toStream(inStream);
    }

    inline friend std::ostream& operator<<(std::ostream& inStream, Loggable const& inLoggable)
    {
      return inLoggable.toStream(inStream);
    }

    inline virtual std::string dump() const {
      return "";
    };

		protected:
    virtual std::ostream& toStream(std::ostream& inStream) const=0;

	}; // end of Loggable class
} // end of Hax namespace
#endif
