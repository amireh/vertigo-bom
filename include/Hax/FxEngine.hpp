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

#ifndef H_HAX_FXENGINE_H
#define H_HAX_FXENGINE_H

#include "Hax/Logger.hpp"
#include "Hax/Engine.hpp"
#include "Hax/EventListener.hpp"

#include <Ogre.h>
// #include "ParticleUniverseCommon.h"
// #include "ParticleUniverseSystem.h"
// #include "ParticleUniverseSystemManager.h"
// #include "ParticleUniverseSystemListener.h"

namespace Ogre {
  class Vector3;
  class SceneManager;
  class SceneNode;
}

namespace Hax {

  struct Event;
  class Entity;
	class FxEngine : public Engine, public EventListener, public Logger {

    typedef void effect_t;
    typedef void effect_mgr_t;
	public:
		virtual ~FxEngine();
		static FxEngine& getSingleton();
    static FxEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

    effect_t* loadEffect(std::string inName);
    effect_t* playEffect(std::string inEffect, Entity* inEntity, bool newInstance = false);
    effect_t* playEffect(effect_t*, Entity* inEntity);
    effect_t* playEffect(std::string inEffect, const Ogre::Vector3 pos, bool newInstance = false);

    //~ void registerHighlightEffect(std::string inName);

    void unloadAllEffects();

	protected:
	private:
		static FxEngine* __instance;

		FxEngine();
		FxEngine(const FxEngine& src);
		FxEngine& operator=(const FxEngine& rhs);

    Ogre::SceneManager *mSceneMgr;
    effect_mgr_t* mFxMgr;

    typedef std::map< std::string, effect_t* > effects_t;
    typedef std::list<Ogre::SceneNode*> deathlist_t;
    typedef deathlist_t portable_effects_t;

    effects_t mEffects;

    portable_effects_t mPortableEffects;
    deathlist_t mDeathlist;

    static int gUID;
	};
}

#endif // H_HAX_FXENGINE_H
