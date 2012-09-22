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

#include "Hax/Entity.hpp"
#include "Hax/Utility.hpp"
#include "Hax/GfxEngine.hpp"

namespace Hax
{

  Entity::Entity()
  : mText(0)
  {
  }

  Entity::~Entity()
  {
    if (mText)
      delete mText;

    mText = 0;
  }


  Entity::Entity(const Entity& src)// : Caster(this)
  {
    copyFrom(src);
  }

  Entity& Entity::operator=(const Entity& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
      return (*this);

    copyFrom(rhs);

    return (*this);
  }

  void Entity::copyFrom(const Entity& src)
  {
    mText = src.mText;
  }

  std::ostream& Entity::toStream(std::ostream& inStream) const
  {
    inStream
      //~ << this->getName() << "[" << this->getUID() << "," << this->getOwner()->getUID() << "]";
      << "\"" << mName << "[" << mUID << "]\"";

    return inStream;
  }

  void Entity::setup(Ogre::SceneManager* inSceneMgr)
  {
    assert(mSceneNode && mSceneObject);
    show();
  }

  bool Entity::live()
  {
  }

  void Entity::die()
  {
    if (mSceneNode && mSceneObject)
    {
      hide();
      GfxEngine::getSingletonPtr()->detachFromScene(this);
    }
  }

  MovableTextOverlay* Entity::getText() const { return mText; }
  void Entity::setText(MovableTextOverlay* inT) { mText = inT; }

  void Entity::hide() {
    if (!mSceneNode || !mText)
      return;

    mSceneNode->setVisible(false);
    if (mText)
    {
      mText->hide(true);
      mText->enable(false);
      mText->update(1);
    }
  }

  void Entity::show() {
    if (!mSceneNode || !mText)
      return;

    mSceneNode->setVisible(true);
    if (mText)
    {
      mText->hide(false);
      mText->enable(true);
      mText->update(1);
    }
  }

} // end of Hax namespace
