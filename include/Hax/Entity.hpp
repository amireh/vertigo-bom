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

#ifndef H_HAX_ENTITY_H
#define H_HAX_ENTITY_H

#include "Hax/Identifiable.hpp"
#include "Hax/Loggable.hpp"
#include "Hax/Animable.hpp"
#include "Hax/Mobile.hpp"
#include "Hax/Renderable.hpp"
#include "Hax/Ogre/MovableTextOverlay.h"

namespace Hax
{
  class Entity
  : public Identifiable,
    public Loggable,
    public Animable,
    public Mobile,
    public Renderable
  {
  public:

    Entity();
    Entity(const Entity& src);
    Entity& operator=(const Entity& rhs);
    virtual ~Entity();

    virtual void setup(Ogre::SceneManager* inSceneMgr = 0);

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);
    virtual void updateTextOverlay() {};

    virtual bool live();
    virtual void die();

    void hide();
    void show();

  protected:

    void copyFrom(const Entity& src);
    virtual std::ostream& toStream(std::ostream& inStream) const;

    MovableTextOverlay  *mText;

  private:

  }; // end of class Entity
} // end of Hax namespace

#endif // H_HAX_ENTITY_H
