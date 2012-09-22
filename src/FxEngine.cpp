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

// #include "ParticleUniverseSystemManager.h"

#include "Hax/FxEngine.hpp"
#include "Hax/GfxEngine.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/Entity.hpp"
#include "Hax/GameState.hpp"
#include "Hax/Utility.hpp"

namespace Hax {

  using Utility::stringify;
  typedef void effect_t;
  typedef void effect_mgr_t;

	FxEngine* FxEngine::__instance = NULL;
  int FxEngine::gUID = 0;

	FxEngine* FxEngine::getSingletonPtr() {
		if( !__instance ) {
		    __instance = new FxEngine();
		}

		return __instance;
	}

  FxEngine& FxEngine::getSingleton() {
    return *FxEngine::getSingletonPtr();
  }

	FxEngine::FxEngine()
  : Logger("FxEngine")
  {
    mLog->infoStream() << "My Listener UID: " << mUID;

    mDeathlist.clear();
    mEffects.clear();
		fSetup = false;
	}

	FxEngine::~FxEngine() {
    mLog->infoStream() << "shutting down";

		if (fSetup) {
      // mFxMgr->destroyAllParticleSystems(mSceneMgr);
      mFxMgr = 0;

			fSetup = false;
		}
	}

	bool FxEngine::cleanup() {
		return true;
	}


	bool FxEngine::setup() {
    mPortableEffects.clear();
    mDeathlist.clear();

		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

    //bind(EventUID::EntitySelected, boost::bind(&FxEngine::onEntitySelected, this, _1));
    //~ bind(EventUID::UnitAttacked, boost::bind(&FxEngine::onEntityAttacked, this, _1));
    //~ if (GameManager::getSingleton().getCurrentState()->getId() == STATE_COMBAT)
    //~ {
      //~ bind(EventUID::EntityDying, boost::bind(&FxEngine::onEntityDying, this, _1));
    //~ } else
      //~ unbind(EventUID::EntityDying);

    mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    // mFxMgr = effect_tManager::getSingletonPtr();

		fSetup = true;
		return true;
	}


	void FxEngine::update( unsigned long lTimeElapsed ) {
		processEvents();
    deathlist_t::iterator node;
    for (node = mDeathlist.begin();
         node != mDeathlist.end();
         ++node) {
      (*node)->detachAllObjects();
      mPortableEffects.remove(*node);
      mSceneMgr->destroySceneNode(*node);
    }
    mDeathlist.clear();
	}

  effect_t* FxEngine::loadEffect(std::string inName) {
    // make sure it's not already registered
    if (mEffects.find(inName) != mEffects.end())
      return mEffects.find(inName)->second;

    // effect_t* effect = 0;
    // effect = mFxMgr->createParticleSystem( inName + "_", inName, mSceneMgr);
    // effect->prepare();

    // mEffects.insert(std::make_pair(inName, effect));

    // return effect;
    return nullptr;
  }

  /*void FxEngine::registerHighlightEffect(std::string inName) {
    assert(mEffects.find(inName) != mEffects.end());

    mHighlightEffect = mEffects.find(inName)->second;
  }*/

  effect_t* FxEngine::playEffect(effect_t* inEffect, Entity* inEntity) {

    // if (inEffect->isAttached()) {
      // inEffect->stop();
      // inEffect->getParentSceneNode()->detachObject(inEffect);
    // }

    //~ inEffect->setUserAny(Ogre::Any(inEntity));
    //~ inEffect->setScale(inEntity->getSceneNode()->getScale());
    // inEntity->getSceneNode()->attachObject(inEffect);
    // inEffect->start();

    return inEffect;
	};

  effect_t* FxEngine::playEffect(std::string inEffect, Entity* inEntity, bool newInstance) {
    if (newInstance)
    {
      // effect_t* effect = mFxMgr->createParticleSystem( inEffect + "_" + stringify(++gUID), inEffect, mSceneMgr);
      // return playEffect(effect, inEntity);
    }
    assert(mEffects.find(inEffect) != mEffects.end());

    return playEffect(mEffects.find(inEffect)->second, inEntity);
  }

  effect_t* FxEngine::playEffect(std::string inEffect, Ogre::Vector3 pos, bool newInstance) {
    /*Ogre::SceneNode* mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mNode->setPosition(pos);

    effect_t* mEffect = 0;
    if (newInstance)
    {
      mEffect = mFxMgr->createParticleSystem( inEffect + "_" + stringify(++gUID), inEffect, mSceneMgr);
    } else {
      assert(mEffects.find(inEffect) != mEffects.end());
      mEffect = mEffects.find(inEffect)->second;

      if (mEffect->isAttached())
        mEffect->getParentSceneNode()->detachObject(mEffect);
    }

    mNode->attachObject(mEffect);
    mEffect->addParticleSystemListener(this);
    mEffect->start();

    mLog->infoStream() << "created a portable effect node";

    mPortableEffects.push_back(mNode);*/

    // return mEffect;
    return nullptr;
  }

  void FxEngine::unloadAllEffects() {
    //~ dehighlight();
    mEffects.clear();
    mDeathlist.clear();
    // mFxMgr->destroyAllParticleSystems(mSceneMgr);
  }

}
