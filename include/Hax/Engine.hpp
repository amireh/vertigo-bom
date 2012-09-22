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

#ifndef H_HAX_ENGINE_H
#define H_HAX_ENGINE_H

#include "Hax/Hax.hpp"

namespace Hax
{
  class Engine {
  public:
    Engine(const Engine& src) = delete;
    Engine& operator=(const Engine& rhs) = delete;
    inline virtual ~Engine() { }

    /**
     * Resource allocation should be done in this method.
     */
    virtual bool setup()=0;

    /**
     * All registered Engine instances will be called to update(), or step, every
     * frame.
     *
     * @param lTimeElapsed
     * The number of milliseconds elapsed since the last time update() was called.
     */
    virtual void update(unsigned long lTimeElapsed)=0;

    /**
     * A chance to clean up all the allocated resources by this engine.
     */
    virtual bool cleanup()=0;

  protected:
    inline Engine() : fSetup(false) { }

    bool fSetup;
  }; // class Engine
} // namespace Hax

#endif
