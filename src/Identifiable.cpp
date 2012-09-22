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

#include "Hax/Identifiable.hpp"
#include "Hax/Utility.hpp"

namespace Hax {
  using Utility::stringify;

	Identifiable::~Identifiable()
	{
    mUID = -1;
    mName = "Unnamed";
	}

  Identifiable::Identifiable()
  : mUID(-1),
    mName("Unnamed")
  {
	}

  Identifiable::Identifiable(const Identifiable& src)// : Caster(this)
  {
    copyFrom(src);
  }

  Identifiable& Identifiable::operator=(const Identifiable& rhs)
  {
    if (this != &rhs) // check for self-assignment
      copyFrom(rhs);

    return (*this);
  }

  void Identifiable::copyFrom(const Identifiable& src)
  {
    mUID = src.mUID;
    mName = src.mName;
  }

	void Identifiable::__setUID(const int inUID)
	{
    if (mUID != -1)
    {
      string_t msg = "Attempting to re-assign an object's UID after it's been set! Object: " + mName + "#" + stringify(mUID);
      throw IntegrityViolation(msg);
    }

		mUID = inUID;
	}


	void Identifiable::__setName(string_t const& inName)
	{
    if (mName != "Unnamed")
    {
      string_t msg = "Attempting to re-assign an object's UID after it's been set! Object: " + mName + "#" + stringify(mUID);
      throw IntegrityViolation(msg);
    }

		mName = inName;
	}

	int Identifiable::getUID() const {
    return mUID;
  }
	string_t const& Identifiable::getName() const {
    return mName;
  }

  bool Identifiable::operator==(const Identifiable& rhs)
  {
    return rhs.mUID == this->mUID;
  }

  void Identifiable::serialize(Event& inEvt) {
    inEvt.setProperty("UID", this->mUID);
  }
  void Identifiable::deserialize(const Event& inEvt) {
    this->mUID = Utility::toNumber(inEvt.getProperty("UID"));
  }
}
