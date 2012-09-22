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

#ifndef H_HAX_SERIALIZABLE_H
#define H_HAX_SERIALIZABLE_H

#include "Hax/Hax.hpp"
#include <string>

namespace Hax
{
	/**
   * @class Serializable
   *
	 * @brief
   * Serializable objects offer an interface that allow objects to capture and
   * transmit their state across the network or the filesystem.
   *
   * An object can optionally be serialized on a number of _levels_ each of which
   * can control the amount of state that is captured in the serialization.
   *
   * Using separate levels of marshalling gives flexibility in how much data
   * will be transmitted; if there are certain fields that are not needed at a
   * certain stage, simply don't serialize them.
	 */
	class Serializable {

    public:

		Serializable();
		Serializable& operator=(const Serializable& rhs);
		Serializable(const Serializable& src);
		virtual ~Serializable();

    /**
     * @brief
     * Writes this object out onto a stringstream in order to be re-created
     * on the receiving end.
     *
     * The serializing format differs between objects and must be matched by
     * the deserializing routine, naturally.
     *
     * @param inStream the stream onto which this object will be serialized
     * @param inLevel the level at which this object will be serialized
     *
     * @note
     * The serialized dump must start with Serializable::Prefix, end with
     * Serializable::Suffix, and all serialized fields must be separated by
     * Serializable::Separator. Otherwise an exception will be thrown on the
     * receiving end.
     *
     * @warning
     * If the passed level is not recognized by the serialization routine,
     * an std::runtime_error exception will be thrown.
     **/
    virtual void serialize(std::ostringstream& inStream, int inLevel=0)=0;

    /**
     * @brief
     * Populates this object's members from the serialized attributes written
     * by serialize() from the sending end.
     *
     * This method can raise an exception of type BadFormat if the given
     * string can not be parsed properly.
     *
     * @param inDump the stream from which this object will be re-created
     * @param inLevel the level at which this object is to be deserialized,
     *                note that this level must match that at which the object
     *                was serialized
     *
     * @warning
     * If the passed level is not recognized by the serialization routine,
     * or there is missing data required by the given level, an std::runtime_error
     * exception will be thrown.
     **/
    virtual void deserialize(std::string const& inDump, int inLevel=0)=0;

    protected:
    static char Prefix, Separator, Suffix;

	}; // end of Serializable class
} // end of Hax namespace
#endif
