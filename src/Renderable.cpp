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

#include "Hax/Renderable.hpp"
#include "Hax/Utility.hpp"
#include "Hax/GfxEngine.hpp"

namespace Hax {

  using Utility::stringify;

  int Renderable::gUID = 0;

	Renderable::Renderable()
  : mSceneNode(0),
    mSceneObject(0),
    mMesh("Undefined"),
    mMaterial("Undefined")
	{
	}

  Renderable::~Renderable() {

    for (extensions_t::iterator ext = mExtensions.begin(); ext != mExtensions.end(); ++ext)
    {
      GfxEngine::getSingletonPtr()->getSceneMgr()->destroyEntity((*ext)->getName());
    }
    mExtensions.clear();

		mSceneNode = 0;
    mSceneObject = 0;
	}

  Renderable::Renderable(const Renderable& src)
  {
    copyFrom(src);
  }

  Renderable& Renderable::operator=(const Renderable& rhs)
  {
    if (&rhs != this)
      copyFrom(rhs);

    return *this;
  }

  void Renderable::copyFrom(const Renderable& src)
  {
    mSceneNode = src.mSceneNode;
    mSceneObject = src.mSceneObject;
    mExtensions = src.mExtensions;
    mMesh = src.mMesh;
    mMaterial = src.mMaterial;
  }

	void Renderable::attachSceneNode(Ogre::SceneNode* inNode)
  {
    mSceneNode = inNode;
  }

  void Renderable::attachSceneObject(Ogre::Entity* inObject)
  {
    mSceneObject = inObject;
    //if (mSceneObject)
    //  mSceneObject->setUserAny(Ogre::Any(this));
  }

  Ogre::Entity* Renderable::attachExtension(string_t const& inMesh, string_t const& inBone)
  {
    Ogre::Entity* tmp =
      GfxEngine::getSingletonPtr()->getSceneMgr()->createEntity(stringify(++gUID) + "extension" + stringify(mExtensions.size()), inMesh);

    mSceneObject->attachObjectToBone(inBone, tmp);
    mExtensions.push_back(tmp);

    return tmp;
  }

  Ogre::SceneNode* Renderable::getSceneNode() const
  {
    return mSceneNode;
  }

  Ogre::Entity* Renderable::getSceneObject() const
  {
    return mSceneObject;
  }

  string_t const& Renderable::getMesh() const
  {
    return mMesh;
  }
  string_t const& Renderable::getMaterial() const
  {
    return mMaterial;
  }
  void Renderable::setMaterial(string_t const& inMaterial)
  {
    mMaterial = inMaterial;
  }
  void Renderable::setMesh(string_t const& inMesh)
  {
    mMesh = inMesh;
  }
} // end of namespace
