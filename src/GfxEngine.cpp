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

#include "Hax/GfxEngine.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/EventManager.hpp"
#include "Hax/Entity.hpp"
#include "Hax/InputManager.hpp"
#include "Hax/FxEngine.hpp"
#include "Hax/ScriptEngine.hpp"
#include "Hax/Utility.hpp"
#include "Hax/Ogre/MousePicker.h"
#include "Hax/Ogre/OgreRTT.h"
#include "Hax/Ogre/SdkCameraMan.h"
#include "Hax/Ogre/MovableTextOverlay.h"
#include "Hax/Ogre/RectLayoutManager.h"
#include "Hax/Ogre/OgreSdkTrays.h"

namespace Hax {

  using Utility::stringify;

	GfxEngine* GfxEngine::_myGfxEngine = NULL;

	GfxEngine* GfxEngine::getSingletonPtr() {
		if( !_myGfxEngine ) {
		    _myGfxEngine = new GfxEngine();
		}

		return _myGfxEngine;
	}

	GfxEngine::GfxEngine()
  : Logger("GfxEngine")
  {
    mLog->infoStream() << "My Listener UID: " << mUID;

		fSetup = false;
		mCameraMan = 0;
    attrs = 0;
    inBlockPhase = false;
    mSelected = 0;
    mPicker = 0;
    mGenericPicker = 0;
    mPolyPicker = 0;
    mTrayMgr = 0;
    mCameraYawPitchDist = Ogre::Vector3::ZERO;
	}

	GfxEngine::~GfxEngine() {
    mLog->infoStream() << "shutting down";

		if (fSetup) {

      delete mGenericPicker;
      delete mPolyPicker;
      mGenericPicker = 0;
      mPolyPicker = 0;
      mPicker = 0;

      delete mCameraMan;
      mCameraMan = 0;

			mRoot = 0;
			mSceneMgr = 0;
			mCamera = 0;
			mViewport = 0;
			mRenderWindow = 0;


      delete mTrayMgr;

      if (attrs)
        delete attrs;
      attrs = 0;

			//if (mSceneLoader)
				//delete mSceneLoader;

			fSetup = false;
		}
	}

	bool GfxEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mRoot = Ogre::Root::getSingletonPtr();
		mSceneMgr = mRoot->createSceneManager("OctreeSceneManager", "CombatScene");
		mCamera = mSceneMgr->createCamera("Combat_Camera");
		mRenderWindow = mRoot->getAutoCreatedWindow();
	  mViewport = mRenderWindow->addViewport(mCamera);

		mEvtMgr = EventManager::getSingletonPtr();

    Ogre::MovableObject::setDefaultQueryFlags(TERRAIN_MASK);
    Ogre::MovableObject::setDefaultVisibilityFlags(TERRAIN_MASK);

    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
    mCameraMan->setStyle(OgreBites::CS_FREELOOK);

    mTrayMgr = new SdkTrayManager("Zephyr", mRenderWindow, InputManager::getSingletonPtr()->getMouse(), 0);
    mTrayMgr->hideCursor();

    mGenericPicker = new GenericMousePicker(mSceneMgr);
    mPolyPicker = new PolyMousePicker(mSceneMgr);

    mPicker = (MousePicker*)mPolyPicker;

		mUpdate = &GfxEngine::updateIntro;

    mAnimables.clear();
    mMobiles.clear();
    mMTOs.clear();
    mRTTs.clear();

		mSelected = 0;
		fSetup = true;
		return fSetup;
	}

  void GfxEngine::setupMovableTextOverlays() {

    if (attrs)
    {
      delete attrs;
      attrs = 0;
    }

    attrs =
      new MovableTextOverlayAttributes(
        "MTOAttributes",
        mCamera,
        mMTOFontName,mMTOFontSize,mMTOFontColor,mMTOMaterialName);
  }

  void GfxEngine::trackNode(Ogre::SceneNode* inNode)
  {
    mCameraMan->setTarget(inNode);
  }

  void GfxEngine::setYawPitchDist(Ogre::Vector3 inVec)
  {
    mCameraYawPitchDist = inVec;
    mCameraMan->setYawPitchDist(Ogre::Degree(mCameraYawPitchDist.x), Ogre::Degree(mCameraYawPitchDist.y), mCameraYawPitchDist.z);
  }


	void GfxEngine::setCamera(const Ogre::String& inCameraName) {
		mCamera = mSceneMgr->createCamera(inCameraName);
	}

	SdkCameraMan* GfxEngine::getCameraMan() {
		return mCameraMan;
	}
	Ogre::Camera* GfxEngine::getCamera() {
		return mCamera;
	}

	Ogre::Root* GfxEngine::getRoot() {
		return mRoot;
	}

	Ogre::SceneManager* GfxEngine::getSceneMgr() {
		return mSceneMgr;
	}

  Ogre::RenderWindow* GfxEngine::getWindow() {
    return mRenderWindow;
  }

	Ogre::Viewport* GfxEngine::getViewport() {
		return mViewport;
	}

  Entity* GfxEngine::getSelected() {
    return mSelected;
  }

	void GfxEngine::updateNothing(unsigned long lTimeElapsed) {

	};

	void GfxEngine::updateIntro(unsigned long lTimeElapsed) {
		mCameraMan->update(lTimeElapsed);

    // update movable text overlays
		using namespace Ogre;

    RectLayoutManager lRLM(0,0,
      mCamera->getViewport()->getActualWidth(),
      mCamera->getViewport()->getActualHeight());
    lRLM.setDepth(0);

    int visible=0;
    MovableTextOverlay *m=0;
    mtos_t::const_iterator lMTOIter;
    for (lMTOIter = mMTOs.begin(); lMTOIter != mMTOs.end(); ++lMTOIter) {
      m = *lMTOIter;

      if (m->isHidden())
        continue;

      m->update(lTimeElapsed);

      if (m->isOnScreen()) {
        ++visible;

        RectLayoutManager::Rect
          lRect(m->getPixelsLeft(),
                m->getPixelsTop()+10,
                m->getPixelsRight(),
                m->getPixelsBottom()+10);

        RectLayoutManager::RectList::iterator lRectIter = lRLM.addData(lRect);
        if (lRectIter != lRLM.getListEnd())
          m->enable(true);
        else
          m->enable(false);
      } else {
        m->enable(false);
      } // MTO is onScreen
    }
	};

	void GfxEngine::update(unsigned long lTimeElapsed) {
		processEvents();

    // common steppable routines

		// update our good tray manager
    evt.timeSinceLastFrame = evt.timeSinceLastEvent = lTimeElapsed;
    mTrayMgr->frameRenderingQueued(evt);

    // step registered Animable and Mobile objects
    animables_t::const_iterator lAnimable;
    for (lAnimable = mAnimables.begin(); lAnimable != mAnimables.end(); ++lAnimable)
      (*lAnimable)->step(lTimeElapsed);

    mobiles_t::const_iterator lMobile;
    for (lMobile = mMobiles.begin(); lMobile != mMobiles.end(); ++lMobile) {
      if (lMobile->second) // if the Mobile object is moving and needs updates
        lMobile->first->step(lTimeElapsed);
    }

    // state specific update routines
		(this->*mUpdate)(lTimeElapsed);
	}

	bool GfxEngine::cleanup() {
	  mLog->infoStream() << "Cleaning up";

		return true;
	}


  void GfxEngine::enableCompositorEffect(std::string inEffect) {
	  Ogre::CompositorManager::getSingleton().addCompositor(mViewport, inEffect);
	  Ogre::CompositorManager::getSingleton().setCompositorEnabled(mViewport, inEffect, true);
  }

  Ogre::SceneNode* GfxEngine::createNode(String& inName, Vector3& inPosition, Vector3& inScale, Vector3& inDirection, Ogre::SceneNode* inParent)
  {
    Ogre::SceneNode* mNode;
    if (!inParent)
      inParent = mSceneMgr->getRootSceneNode();

    if (mSceneMgr->hasSceneNode(inName))
      mSceneMgr->destroySceneNode(inName);

    mNode = inParent->createChildSceneNode(inName, inPosition);
    mNode->setScale(inScale);

    return mNode;
  };

  Ogre::SceneNode* GfxEngine::renderEntity(Entity* inEntity)
  {
    mLog->debugStream() << "rendering entity " << inEntity->getName();

    Ogre::SceneNode* mNode = 0;
    Ogre::Entity* mOgreEntity = 0;
    int idNode = -1;

    String entityName = "", nodeName = "", ownerName = "";
    mNode = mSceneMgr->createSceneNode(inEntity->getName() + stringify(inEntity->getUID()));
    mSceneMgr->getRootSceneNode()->addChild(mNode);

    mOgreEntity = mSceneMgr->createEntity(entityName, inEntity->getMesh());
    mOgreEntity->setMaterialName(inEntity->getMaterial());
    mOgreEntity->setQueryFlags(GfxEngine::ENTITY_MASK);
    mOgreEntity->setVisibilityFlags(GfxEngine::ENTITY_MASK);
    mOgreEntity->setRenderQueueGroup(Ogre::RENDER_QUEUE_8);
    mOgreEntity->setUserAny(Ogre::Any(inEntity));

    mNode->attachObject(mOgreEntity);
    mNode->setScale(Ogre::Vector3(0,0,0));

    MovableTextOverlay *lMTO =
      new MovableTextOverlay(mOgreEntity->getName() + "_text"," UBER CYBOT ", mOgreEntity, attrs);

    lMTO->enable(false); // make it invisible for now
    lMTO->setUpdateFrequency(0.01f);// set update frequency to 0.01 seconds
    inEntity->setText(lMTO);
    mMTOs.push_back(lMTO);
    lMTO = 0;

    inEntity->attachSceneNode(mNode);
    inEntity->attachSceneObject(mOgreEntity);
    inEntity->setup(mSceneMgr);

    // update the MTO
    inEntity->updateTextOverlay();

    mAnimables.push_back(inEntity);

    return mNode;
  };


  bool GfxEngine::attachToScene(Entity* inEntity)
  {
    assert(inEntity);

    // render the object
    renderEntity(inEntity);

    return true;
  };

  void GfxEngine::detachFromScene(Entity* inEntity)
  {
    dehighlight();

    Ogre::SceneNode* mTmpNode = inEntity->getSceneNode();

    mLog->debugStream() << "I'm detaching " << inEntity << " from SceneNode : " << mTmpNode->getName();
    mTmpNode->detachAllObjects();

    // destroy entity
    mSceneMgr->destroyEntity((Ogre::Entity*)inEntity->getSceneObject());

    // remove it from the Animables tracker
    mAnimables.remove(inEntity);

    inEntity->attachSceneNode(NULL);
    inEntity->attachSceneObject(NULL);

    // remove it from the Mobiles tracker if it's a Unit
    mMobiles.erase(static_cast<Mobile*>(inEntity));

    mTmpNode = 0;
  }

	bool GfxEngine::mouseMoved( const OIS::MouseEvent &e )
	{

		if (mCameraMan)
			mCameraMan->injectMouseMove(e);

    return true;
	}

	bool GfxEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id )
	{
    // check if the mouse is over any UI element that wants to capture the input
#if 0 // DISABLED
    CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    if (window)
    {
      typedef std::list<std::string> list_t;
      for (list_t::const_iterator itr = mUIInputCapturingElements.begin();
        itr != mUIInputCapturingElements.end();
        ++itr)
      {
        if (window->getName().find((*itr)) != CEGUI::String::npos) return false;
      }
    }

		if (mCameraMan)
			mCameraMan->injectMouseDown(e, id);

    CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();

    if (id != OIS::MB_Left)
      return false;

    Ogre::MovableObject *resultObj = 0;
    bool result = mPicker->cast( e, mousePos, mCamera, &resultObj, ENTITY_MASK);

    if (!result)
    {
      dehighlight();
      return true;
    }

    assert(resultObj);
    highlight(Ogre::any_cast<Hax::Entity*>(resultObj->getUserAny()));

#endif

    return true;
	}

	bool GfxEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id )
	{
		if (mCameraMan)
			mCameraMan->injectMouseUp(e, id);

    return true;
	}

	void GfxEngine::keyReleased( const OIS::KeyEvent &e ) {
	  if (mCameraMan)
			mCameraMan->injectKeyUp(e);

    switch (e.key) {
      case OIS::KC_K:
        if (mTrayMgr->areFrameStatsVisible())
          mTrayMgr->hideFrameStats();
        else
          mTrayMgr->showFrameStats(OgreBites::TL_TOPRIGHT);
      break;
    }
	}

	void GfxEngine::keyPressed( const OIS::KeyEvent &e ) {
	  if (mCameraMan)
			mCameraMan->injectKeyDown(e);
	}

	void GfxEngine::highlight(Entity* inEntity) {

    Event e(EventUID::EntitySelected);
    e.Any = (void*)inEntity;
    mEvtMgr->hook(e);

	};

	void GfxEngine::dehighlight() {
	  if (!mSelected)
	    return;

    Event e(EventUID::EntityDeselected);
    e.Any = (void*)mSelected;
    mEvtMgr->hook(e);

	  mSelected = 0;
	};

  void GfxEngine::updateMe(Mobile* inUnit) {
    if (mMobiles.find(inUnit) != mMobiles.end()) {
      mMobiles.find(inUnit)->second = true;
      return;
    }

    mMobiles.insert(std::make_pair(inUnit, true));
  }

  void GfxEngine::stopUpdatingMe(Mobile* inUnit) {
    if (mMobiles.find(inUnit) != mMobiles.end())
      mMobiles.find(inUnit)->second = false;
  }


  Ogre::Vector2 GfxEngine::getScreenCoords(Ogre::MovableObject* inObject) {
    using namespace Ogre;

    Real MinX = 0;
    Real MinY = 0;
    Real MaxX = 0;
    Real MaxY = 0;

    Ogre::Real X[4];// the 2D dots of the AABB in screencoordinates
    Ogre::Real Y[4];

    if (!inObject->isInScene())
       return Vector2(0,0);

    const Ogre::AxisAlignedBox &AABB = inObject->getWorldBoundingBox(true);// the AABB of the target
    const Ogre::Vector3 CornersOfTopAABB[4] = {
      AABB.getCorner(AxisAlignedBox::FAR_LEFT_TOP),
      AABB.getCorner(AxisAlignedBox::FAR_RIGHT_TOP),
      AABB.getCorner(AxisAlignedBox::NEAR_LEFT_TOP),
      AABB.getCorner(AxisAlignedBox::NEAR_RIGHT_TOP)};

    Ogre::Vector3 CameraPlainNormal = mCamera->getDerivedOrientation().zAxis();//The normal vector of the plaine.this points directly infront of the cam

    Ogre::Plane CameraPlain = Plane(CameraPlainNormal,mCamera->getDerivedPosition());//the plaine that devides the space bevor and behin the cam

    for (int i = 0; i < 4; i++)
    {
      X[i] = 0;
      Y[i] = 0;


      Vector3 hcsPosition = mCamera->getProjectionMatrix() * (mCamera->getViewMatrix() * CornersOfTopAABB[i]);

      X[i] = 1.0f - ((hcsPosition.x * 0.5f) + 0.5f);// 0 <= x <= 1 // left := 0,right := 1
      Y[i] = ((hcsPosition.y * 0.5f) + 0.5f);// 0 <= y <= 1 // bottom := 0,top := 1
      //_getScreenCoordinates(CornersOfTopAABB[i],X[i],Y[i]);// transfor into 2d dots

      if (CameraPlain.getSide(CornersOfTopAABB[i]) == Plane::NEGATIVE_SIDE)
      {

       if (i == 0)// accept the first set of values, no matter how bad it might be.
       {
        MinX = X[i];
        MinY = Y[i];
        MaxX = X[i];
        MaxY = Y[i];
       }
       else// now compare if you get "better" values
       {
        if (MinX > X[i])// get the x minimum
        {
           MinX = X[i];
        }
        if (MinY > Y[i])// get the y minimum
        {
           MinY = Y[i];
        }
        if (MaxX < X[i])// get the x maximum
        {
           MaxX = X[i];
        }
        if (MaxY < Y[i])// get the y maximum
        {
           MaxY = Y[i];
        }
       }
      }
      else
      {
      MinX = 0;
      MinY = 0;
      MaxX = 0;
      MaxY = 0;
      break;
      }
    }

    Real relWidth = inObject->getWorldBoundingBox().getSize().x * 2 / Ogre::OverlayManager::getSingleton().getViewportWidth();
    return Vector2(1-(MinX + MaxX + 0.05f + relWidth )/2, 1-MaxY+0.05f);
  }


  void GfxEngine::switchMousePickingMode()
  {
    mPicker = (mPicker == (MousePicker*)mPolyPicker) ? (MousePicker*)mGenericPicker : (MousePicker*)mPolyPicker;
  }

  int GfxEngine::getMousePickingMode() const
  {
    return (mPicker == (MousePicker*)mPolyPicker) ? POLY : GENERIC;
  };

  void GfxEngine::_setUserAny(Ogre::MovableObject* inObj, void* any)
  {
    inObj->setUserAny(Ogre::Any(any));
  }

  void GfxEngine::attachRTT(OgreRTT* inRTT)
  {
    mRTTs.push_back(inRTT);
  }
  void GfxEngine::detachRTT(OgreRTT* inRTT)
  {
    mRTTs.remove(inRTT);
  }


  void GfxEngine::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
  {
    // todo: don't reference a scenenode by its name in here.... create a hook for a callback
    mSceneMgr->getSceneNode("EntitySelectionNode")->setVisible(false);
    for (std::list<OgreRTT*>::iterator rtt = mRTTs.begin(); rtt != mRTTs.end(); ++rtt)
      (*rtt)->hide();
  }

  void GfxEngine::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
  {
    mSceneMgr->getSceneNode("EntitySelectionNode")->setVisible(true);
    for (std::list<OgreRTT*>::iterator rtt = mRTTs.begin(); rtt != mRTTs.end(); ++rtt)
      (*rtt)->show();
  }

  void GfxEngine::disableMouseCaptureOverUIElement(std::string const& inElementName)
  {
    // make sure the element isn't already tracked
    std::list<std::string>::const_iterator itr;
    for (itr = mUIInputCapturingElements.begin();
      itr != mUIInputCapturingElements.end();
      ++itr)
      if ((*itr) == inElementName) return;

    mUIInputCapturingElements.push_back(inElementName);
  }
  void GfxEngine::enableMouseCaptureOverUIElement(std::string const& inElementName)
  {
    mUIInputCapturingElements.remove(inElementName);
  }

  void GfxEngine::createColourCube()
  {
      /// Create the mesh via the MeshManager
      Ogre::MeshPtr msh = MeshManager::getSingleton().createManual("ColourCube", "General");

      /// Create one submesh
      SubMesh* sub = msh->createSubMesh();

      const float sqrt13 = 0.577350269f; /* sqrt(1/3) */

      /// Define the vertices (8 vertices, each consisting of 2 groups of 3 floats
      const size_t nVertices = 8;
      const size_t vbufCount = 3*2*nVertices;
      float vertices[vbufCount] = {
              -100.0,100.0,-100.0,        //0 position
              -sqrt13,sqrt13,-sqrt13,     //0 normal
              100.0,100.0,-100.0,         //1 position
              sqrt13,sqrt13,-sqrt13,      //1 normal
              100.0,-100.0,-100.0,        //2 position
              sqrt13,-sqrt13,-sqrt13,     //2 normal
              -100.0,-100.0,-100.0,       //3 position
              -sqrt13,-sqrt13,-sqrt13,    //3 normal
              -100.0,100.0,100.0,         //4 position
              -sqrt13,sqrt13,sqrt13,      //4 normal
              100.0,100.0,100.0,          //5 position
              sqrt13,sqrt13,sqrt13,       //5 normal
              100.0,-100.0,100.0,         //6 position
              sqrt13,-sqrt13,sqrt13,      //6 normal
              -100.0,-100.0,100.0,        //7 position
              -sqrt13,-sqrt13,sqrt13,     //7 normal
      };

      RenderSystem* rs = Root::getSingleton().getRenderSystem();
      RGBA colours[nVertices];
      RGBA *pColour = colours;
      // Use render system to convert colour value since colour packing varies
      rs->convertColourValue(ColourValue(1.0,0.0,0.0), pColour++); //0 colour
      rs->convertColourValue(ColourValue(1.0,1.0,0.0), pColour++); //1 colour
      rs->convertColourValue(ColourValue(0.0,1.0,0.0), pColour++); //2 colour
      rs->convertColourValue(ColourValue(0.0,0.0,0.0), pColour++); //3 colour
      rs->convertColourValue(ColourValue(1.0,0.0,1.0), pColour++); //4 colour
      rs->convertColourValue(ColourValue(1.0,1.0,1.0), pColour++); //5 colour
      rs->convertColourValue(ColourValue(0.0,1.0,1.0), pColour++); //6 colour
      rs->convertColourValue(ColourValue(0.0,0.0,1.0), pColour++); //7 colour

      /// Define 12 triangles (two triangles per cube face)
      /// The values in this table refer to vertices in the above table
      const size_t ibufCount = 36;
      unsigned short faces[ibufCount] = {
              0,2,3,
              0,1,2,
              1,6,2,
              1,5,6,
              4,6,5,
              4,7,6,
              0,7,4,
              0,3,7,
              0,5,1,
              0,4,5,
              2,7,3,
              2,6,7
      };

      /// Create vertex data structure for 8 vertices shared between submeshes
      msh->sharedVertexData = new VertexData();
      msh->sharedVertexData->vertexCount = nVertices;

      /// Create declaration (memory format) of vertex data
      VertexDeclaration* decl = msh->sharedVertexData->vertexDeclaration;
      size_t offset = 0;
      // 1st buffer
      decl->addElement(0, offset, VET_FLOAT3, VES_POSITION);
      offset += VertexElement::getTypeSize(VET_FLOAT3);
      decl->addElement(0, offset, VET_FLOAT3, VES_NORMAL);
      offset += VertexElement::getTypeSize(VET_FLOAT3);
      /// Allocate vertex buffer of the requested number of vertices (vertexCount)
      /// and bytes per vertex (offset)
      HardwareVertexBufferSharedPtr vbuf =
          HardwareBufferManager::getSingleton().createVertexBuffer(
          offset, msh->sharedVertexData->vertexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY);
      /// Upload the vertex data to the card
      vbuf->writeData(0, vbuf->getSizeInBytes(), vertices, true);

      /// Set vertex buffer binding so buffer 0 is bound to our vertex buffer
      VertexBufferBinding* bind = msh->sharedVertexData->vertexBufferBinding;
      bind->setBinding(0, vbuf);

      // 2nd buffer
      offset = 0;
      decl->addElement(1, offset, VET_COLOUR, VES_DIFFUSE);
      offset += VertexElement::getTypeSize(VET_COLOUR);
      /// Allocate vertex buffer of the requested number of vertices (vertexCount)
      /// and bytes per vertex (offset)
      vbuf = HardwareBufferManager::getSingleton().createVertexBuffer(
          offset, msh->sharedVertexData->vertexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY);
      /// Upload the vertex data to the card
      vbuf->writeData(0, vbuf->getSizeInBytes(), colours, true);

      /// Set vertex buffer binding so buffer 1 is bound to our colour buffer
      bind->setBinding(1, vbuf);

      /// Allocate index buffer of the requested number of vertices (ibufCount)
      HardwareIndexBufferSharedPtr ibuf = HardwareBufferManager::getSingleton().
          createIndexBuffer(
          HardwareIndexBuffer::IT_16BIT,
          ibufCount,
          HardwareBuffer::HBU_STATIC_WRITE_ONLY);

      /// Upload the index data to the card
      ibuf->writeData(0, ibuf->getSizeInBytes(), faces, true);

      /// Set parameters of the submesh
      sub->useSharedVertices = true;
      sub->indexData->indexBuffer = ibuf;
      sub->indexData->indexCount = ibufCount;
      sub->indexData->indexStart = 0;

      /// Set bounding information (for culling)
      msh->_setBounds(AxisAlignedBox(-100,-100,-100,100,100,100));
      msh->_setBoundingSphereRadius(Math::Sqrt(3*100*100));

      /// Notify -Mesh object that it has been loaded
      msh->load();
  }

  void GfxEngine::createSphere(const std::string& strName, const float r, const int nRings, const int nSegments)
  {
    using namespace Ogre;
    MeshPtr pSphere = MeshManager::getSingleton().createManual(strName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    SubMesh *pSphereVertex = pSphere->createSubMesh();

    pSphere->sharedVertexData = new VertexData();
    VertexData* vertexData = pSphere->sharedVertexData;

    // define the vertex format
    VertexDeclaration* vertexDecl = vertexData->vertexDeclaration;
    size_t currOffset = 0;
    // positions
    vertexDecl->addElement(0, currOffset, VET_FLOAT3, VES_POSITION);
    currOffset += VertexElement::getTypeSize(VET_FLOAT3);
    // normals
    vertexDecl->addElement(0, currOffset, VET_FLOAT3, VES_NORMAL);
    currOffset += VertexElement::getTypeSize(VET_FLOAT3);
    // two dimensional texture coordinates
    vertexDecl->addElement(0, currOffset, VET_FLOAT2, VES_TEXTURE_COORDINATES, 0);
    currOffset += VertexElement::getTypeSize(VET_FLOAT2);

    // allocate the vertex buffer
    vertexData->vertexCount = (nRings + 1) * (nSegments+1);
    HardwareVertexBufferSharedPtr vBuf = HardwareBufferManager::getSingleton().createVertexBuffer(vertexDecl->getVertexSize(0), vertexData->vertexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
    VertexBufferBinding* binding = vertexData->vertexBufferBinding;
    binding->setBinding(0, vBuf);
    float* pVertex = static_cast<float*>(vBuf->lock(HardwareBuffer::HBL_DISCARD));

    // allocate index buffer
    pSphereVertex->indexData->indexCount = 6 * nRings * (nSegments + 1);
    pSphereVertex->indexData->indexBuffer = HardwareBufferManager::getSingleton().createIndexBuffer(HardwareIndexBuffer::IT_16BIT, pSphereVertex->indexData->indexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
    HardwareIndexBufferSharedPtr iBuf = pSphereVertex->indexData->indexBuffer;
    unsigned short* pIndices = static_cast<unsigned short*>(iBuf->lock(HardwareBuffer::HBL_DISCARD));

    float fDeltaRingAngle = (Math::PI / nRings);
    float fDeltaSegAngle = (2 * Math::PI / nSegments);
    unsigned short wVerticeIndex = 0 ;

    // Generate the group of rings for the sphere
    for( int ring = 0; ring <= nRings; ring++ ) {
        float r0 = r * sinf (ring * fDeltaRingAngle);
        float y0 = r * cosf (ring * fDeltaRingAngle);

        // Generate the group of segments for the current ring
        for(int seg = 0; seg <= nSegments; seg++) {
            float x0 = r0 * sinf(seg * fDeltaSegAngle);
            float z0 = r0 * cosf(seg * fDeltaSegAngle);

            // Add one vertex to the strip which makes up the sphere
            *pVertex++ = x0;
            *pVertex++ = y0;
            *pVertex++ = z0;

            Vector3 vNormal = Vector3(x0, y0, z0).normalisedCopy();
            *pVertex++ = vNormal.x;
            *pVertex++ = vNormal.y;
            *pVertex++ = vNormal.z;

            *pVertex++ = (float) seg / (float) nSegments;
            *pVertex++ = (float) ring / (float) nRings;

            if (ring != nRings) {
                               // each vertex (except the last) has six indices pointing to it
                *pIndices++ = wVerticeIndex + nSegments + 1;
                *pIndices++ = wVerticeIndex;
                *pIndices++ = wVerticeIndex + nSegments;
                *pIndices++ = wVerticeIndex + nSegments + 1;
                *pIndices++ = wVerticeIndex + 1;
                *pIndices++ = wVerticeIndex;
                wVerticeIndex ++;
            }
        }; // end for seg
    } // end for ring

    // Unlock
    vBuf->unlock();
    iBuf->unlock();
    // Generate face list
    pSphereVertex->useSharedVertices = true;

    // the original code was missing this line:
    pSphere->_setBounds( AxisAlignedBox( Vector3(-r, -r, -r), Vector3(r, r, r) ), false );
    pSphere->_setBoundingSphereRadius(r);
        // this line makes clear the mesh is loaded (avoids memory leaks)
        pSphere->load();
  }
}
