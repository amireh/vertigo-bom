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

#ifndef H_HAX_OGRE_RTT_H
#define H_HAX_OGRE_RTT_H

#include "Ogre.h"

namespace Hax
{
  class OgreRTT// : public Ogre::RenderTargetListener
  {

    public:
    OgreRTT();
    virtual ~OgreRTT();

    void setup(Ogre::SceneManager *mSceneMgr, Ogre::RenderWindow *inWindow, Ogre::Camera *inCamera);
    void setCorners(Ogre::Real left, Ogre::Real right, Ogre::Real top, Ogre::Real bot);

    void enable();
    void disable();

    bool isEnabled() const;

    void hide();
    void show();

    protected:

    //virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    //~ virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
    //~ virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

    Ogre::Camera* mCamera;
    Ogre::RenderWindow* mWindow;

    Ogre::MaterialPtr mMatPtr;
    Ogre::Technique *mMatTechnique;

    Ogre::Viewport *mViewport;
    Ogre::TexturePtr mTexture;
    Ogre::RenderTexture *mRenderTexture;
    Ogre::Rectangle2D *mMiniScreen;
    Ogre::SceneNode* mSceneNode;

    Ogre::SceneManager* mSceneMgr;

    bool fEnabled;

    static int gUID;
  };
}

#endif
