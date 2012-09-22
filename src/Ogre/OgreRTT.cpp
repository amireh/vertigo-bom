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

#include "Hax/Ogre/OgreRTT.h"
#include "Hax/GfxEngine.hpp"

namespace Hax
{
  int OgreRTT::gUID = 0;

  OgreRTT::OgreRTT()
  : mWindow(0),
    mCamera(0),
    mMiniScreen(0)
  {
  }

  OgreRTT::~OgreRTT()
  {
    GfxEngine::getSingletonPtr()->detachRTT(this);
    this->disable();
    delete mMiniScreen;
    mSceneMgr->destroySceneNode(mSceneNode);
    Ogre::MaterialManager::getSingleton().remove(mMatPtr->getName());
    //~ Ogre::TextureManager::getSingleton().remove(mTexture->getName());

    //~ delete mMatTechnique;
    //~ mSceneNode = 0;

    //~ delete mRenderTexture;
  }

  void OgreRTT::setup(Ogre::SceneManager *inSceneMgr, Ogre::RenderWindow *inWindow, Ogre::Camera *inCamera)
  {
    mSceneMgr = inSceneMgr;
    mWindow = inWindow;
    mCamera = inCamera;

    using namespace Ogre;
    TexturePtr mTexture =
      TextureManager::getSingleton().createManual(
        "RttTex_" + gUID,
        ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        TEX_TYPE_2D,
        mWindow->getWidth(),
        mWindow->getHeight(),
        0,
        Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);


    mRenderTexture = mTexture->getBuffer()->getRenderTarget();

    mViewport = mRenderTexture->addViewport(mCamera);
    mViewport->setVisibilityMask(GfxEngine::ENTITY_MASK);
    mViewport->setClearEveryFrame(true);
    mViewport->setBackgroundColour(Ogre::ColourValue::Black);
    mViewport->setOverlaysEnabled(false);

    // Create the rectangle
    mMiniScreen = new Ogre::Rectangle2D(true);
    mMiniScreen->setCorners(0.5f, -0.5f, 1.0f, -1.0f);
    mMiniScreen->setBoundingBox(Ogre::AxisAlignedBox(-100000.0f * Ogre::Vector3::UNIT_SCALE, 100000.0f * Ogre::Vector3::UNIT_SCALE));

    mSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MiniScreenNode_" + gUID);
    mSceneNode->attachObject(mMiniScreen);

    // Create the material
    mMatPtr = Ogre::MaterialManager::getSingleton().create("RttMat_" + gUID, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    mMatTechnique = mMatPtr->createTechnique();
    mMatTechnique->createPass();
    mMatPtr->getTechnique(0)->getPass(0)->setLightingEnabled(false);
    mMatPtr->getTechnique(0)->getPass(0)->createTextureUnitState("RttTex_" + gUID);

    mMiniScreen->setMaterial("RttMat_" + gUID);

    ++gUID;

    GfxEngine::getSingletonPtr()->attachRTT(this);
  }

  void OgreRTT::setCorners(Ogre::Real left, Ogre::Real right, Ogre::Real top, Ogre::Real bot)
  {
    assert(mMiniScreen);
    mMiniScreen->setCorners(left, right, top, bot);
  }

  void OgreRTT::enable()
  {
    mRenderTexture->addListener(GfxEngine::getSingletonPtr());
    fEnabled = true;
  }

  void OgreRTT::disable()
  {
    mRenderTexture->removeListener(GfxEngine::getSingletonPtr());
    fEnabled = false;
  }

  bool OgreRTT::isEnabled() const {
    return fEnabled;
  }

  void OgreRTT::hide()
  {
    mMiniScreen->setVisible(false);
  }

  void OgreRTT::show()
  {
    mMiniScreen->setVisible(true);
  }

}
