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

#include "Hax/Serializable.hpp"

namespace Hax {

  char Serializable::Prefix = '$';
  char Serializable::Separator = ';';
  char Serializable::Suffix = '\n';

	Serializable::~Serializable()
	{
	}

  Serializable::Serializable()
  {
	}

  Serializable::Serializable(const Serializable& src)
  {
  }

  Serializable& Serializable::operator=(const Serializable& rhs)
  {
    return (*this);
  }

}
