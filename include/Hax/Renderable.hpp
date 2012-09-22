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

#ifndef H_HAX_RENDERABLE_H
#define H_HAX_RENDERABLE_H

#include "Hax/Hax.hpp"

#include <Ogre.h>

namespace Hax
{
	class Renderable
	{
    public:

		Renderable();
		Renderable& operator=(const Renderable& rhs);
		Renderable(const Renderable& src);
		virtual ~Renderable();

		void attachSceneNode(Ogre::SceneNode* inNode);
		Ogre::SceneNode* getSceneNode() const;

		void attachSceneObject(Ogre::Entity* inObject);
		Ogre::Entity* getSceneObject() const;

    Ogre::Entity* attachExtension(string_t const& inMesh, string_t const& inBone);

    string_t const& getMesh() const;
    string_t const& getMaterial() const;
    void setMaterial(string_t const&);
    void setMesh(string_t const&);

		protected:

    void copyFrom(const Renderable& src);

		Ogre::SceneNode     *mSceneNode;
		Ogre::Entity        *mSceneObject;
    typedef std::vector<Ogre::Entity*> extensions_t;
    extensions_t mExtensions;

    string_t mMesh;
    string_t mMaterial;

    static int gUID;

	}; // end of Renderable class
} // end of Hax namespace
#endif
