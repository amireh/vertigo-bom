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

#ifndef H_HAX_GFX_ENGINE_H
#define H_HAX_GFX_ENGINE_H

#include "Hax/Engine.hpp"
#include "Hax/EventListener.hpp"
#include "Hax/InputListener.hpp"
#include "Hax/Logger.hpp"

#include <Ogre.h>

namespace OgreMax {
  class OgreMaxScene;
}
namespace OgreBites {
  class SdkCameraMan;
  class SdkTrayManager;
}

class MovableTextOverlay;
class MovableTextOverlayAttributes;

using Ogre::Vector3;
using Ogre::Real;
using Ogre::SceneNode;
using Ogre::String;
using OgreBites::SdkCameraMan;
using OgreBites::SdkTrayManager;

namespace Hax {

  class Animable;
  class Mobile;
  class Entity;
  class EventManager;
  class MousePicker;
  class GenericMousePicker;
  class PolyMousePicker;
  class OgreRTT;

	/*! \class GfxEngine
	 *	\brief
	 *	Handles all graphics related features of the game, acts as the immediate
	 *	wrapper over OGRE3D. The game scene is entirely managed by and through
	 *	this Engine.
	 */
	class GfxEngine
  : public Engine,
    public EventListener,
    public InputListener,
    public Logger,
    public Ogre::RenderTargetListener
  {

	public:

    enum QueryFlags {
      TERRAIN_MASK = 1<<0,
      ENTITY_MASK = 1<<1
    };

    enum MousePickingMode {
      GENERIC,
      POLY
    };

		virtual ~GfxEngine();
		static GfxEngine* getSingletonPtr();

    Ogre::ColourValue mMTOFontColor;
    Ogre::String      mMTOFontName;
    int               mMTOFontSize;
    Ogre::String      mMTOMaterialName;

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

    void disableMouseCaptureOverUIElement(string_t const& inElementName);
    void enableMouseCaptureOverUIElement(string_t const& inElementName);

		void setCamera(const Ogre::String& inCameraName);

    void switchMousePickingMode();
    int getMousePickingMode() const;

		//! Attaches a Hax::Entity to an SceneNode and renders it
		/*!
		 * Called upon by CombatManager::createUnit();
		 * Determines the appropriate empty SceneNode in which to render
		 * the given inEntity. Moreover, "attaches" Hax::Entity
		 * to the given Ogre::Entity for later retrieval, thus,
		 * linking the GameObject with SceneObject.
		 */
		bool attachToScene(Entity* inEntity);

		//! Detaches a Hax::Entity from an SceneNode and removes it from Scene
		/*!
		 * Called upon by CombatManager::destroyUnit();
		 * Detaches the Ogre::Entity from SceneNode;
		 * stops rendering it. Also detaches Hax::Entity
		 * from the Ogre::Entity.
		 */
		void detachFromScene(Entity* inEntity);

    void setupMovableTextOverlays();

		SdkCameraMan* getCameraMan();
		Ogre::Camera* getCamera();
		Ogre::Root* getRoot();
		Ogre::SceneManager* getSceneMgr();
    Ogre::RenderWindow *getWindow();
		Ogre::Viewport* getViewport();

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		Entity* getSelected();

    void updateMe(Mobile*);
    void stopUpdatingMe(Mobile*);

    void enableCompositorEffect(string_t inEffect);

    Ogre::Vector2 getScreenCoords(Ogre::MovableObject* inObject);

    void setYawPitchDist(Ogre::Vector3 inVec);
    void trackNode(Ogre::SceneNode* inNode);

    void _setUserAny(Ogre::MovableObject*, void*);

    void attachRTT(OgreRTT*);
    void detachRTT(OgreRTT*);

    /**
     * Creates a Cube mesh named ColourCube with a default size of 100 units
     **/
    void createColourCube();

    /**
     * Creates a Sphere mesh with the given name and attributes
     **/
    void createSphere(const string_t& strName, const float r, const int nRings = 16, const int nSegments = 16);

	protected:
	  void (GfxEngine::*mUpdate)(unsigned long);

	  void updateNothing(unsigned long lTimeElapsed);
	  void updateIntro(unsigned long lTimeElapsed);

    virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
    virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

		Ogre::Root           *mRoot;
		Ogre::Camera         *mCamera;
		Ogre::SceneManager   *mSceneMgr;
		Ogre::Viewport       *mViewport;
		Ogre::RenderWindow	 *mRenderWindow;
		Ogre::OverlayManager *mOverlayMgr;
		Ogre::Overlay        *mOverlay;
		EventManager		     *mEvtMgr;
		SdkCameraMan		     *mCameraMan;
    SdkTrayManager       *mTrayMgr;

    Ogre::FrameEvent evt;

		Entity* mSelected; // selected entity

    std::list<string_t> mUIInputCapturingElements;

    typedef std::map<Mobile*, bool> mobiles_t;
    mobiles_t mMobiles;

    typedef std::list<Animable*> animables_t;
    animables_t mAnimables;

    typedef std::list<MovableTextOverlay*> mtos_t;
    mtos_t mMTOs;

		/*!
		 * \brief Creates an Ogre::Entity and renders it in an
		 * appropriate SceneNode. Must not be called directly;
		 * only reachable via attachToScene()
		 */
		SceneNode* renderEntity(Entity* inEntity);

		/*!
		 * \brief Creates a SceneNode with the given attributes
		 *
		 * \note used by setupNodes()
		 * @return the created SceneNode
		 */
		SceneNode* createNode(String& inName, Vector3& inPosition, Vector3& inScale, Vector3& inDirection, SceneNode* inParent=NULL);

    MovableTextOverlayAttributes* attrs;

	  void highlight(Entity* inEntity);
	  void dehighlight();

    bool inBlockPhase;

    OgreMax::OgreMaxScene* mScene;

    GenericMousePicker  *mGenericPicker;
    PolyMousePicker     *mPolyPicker;
    MousePicker         *mPicker;

    std::list<OgreRTT*> mRTTs;

    Vector3 mCameraYawPitchDist;

	private:
		static GfxEngine* _myGfxEngine;
		GfxEngine();
		GfxEngine(const GfxEngine& src);
		GfxEngine& operator=(const GfxEngine& rhs);
	};
}
#endif
