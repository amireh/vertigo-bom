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

#ifndef H_HAX_ANIMABLE_H
#define H_HAX_ANIMABLE_H

#include "Hax/Hax.hpp"
#include <Ogre.h>

namespace Hax
{
  class Renderable;
	class Animable
	{
    public:

    // all the animations our character has, and a null ID
    // some of these affect separate body parts and will be blended together
    enum AnimID
    {
      ANIM_NONE=0,
      ANIM_LIVE,
      ANIM_IDLE,
      ANIM_WALK,
      ANIM_RUN,
      ANIM_ATTACK,
      ANIM_HIT,
      ANIM_REST,
      ANIM_GETUP,
      ANIM_DIE
    };

		Animable();
		Animable& operator=(const Animable& rhs);
		Animable(const Animable& src);
		virtual ~Animable();


    void registerAnimationState(AnimID inId, std::string inState, bool doLoop = true);

    void step(unsigned long deltaTime);

    float animateLive();
    float animateDie();
    float animateIdle();
    float animateWalk();
    float animateRun();
    float animateAttack();
    float animateHit();
    float animateRest();
    float animateGetUp();

    // if override is true, then the given animation will instantly
    // play and override any currently playing one (even mini ones)
    //
    // note: only applies to Mini animations
    float _animate(AnimID inId, bool override = false);

    static void setAnimFadeSpeed(float inSpeed);
    static float getAnimFadeSpeed();

		protected:

    /**
     * @brief
     * Registers the given SceneNode and Ogre Entity to be used for animating and
     * prepares the animable object.
     *
     * @warning
     * This function MUST be called before any usage of the Animable instance.
     **/
    void setup(Renderable*);

    private:

    static float mAnimeFadeSpeed;
    Ogre::Real mAnimeTimer;
    Renderable *mRenderable;

    /**
     * @struct Animation clips interface
     *
     *
     **/
    typedef struct {

      AnimID ID;
      Ogre::AnimationState* State;
      bool FadingIn;
      bool FadingOut;

      inline bool isMini() const {
        return (!State->getLoop());
      }

    } Animation;

    Animation *mCurrentAnim;
    Animation *mLoopAnim;

    typedef std::vector<Animation*> anims_t;
    typedef std::map<AnimID, anims_t > anim_map_t;
    anim_map_t mAnims;

    std::list<Animation*> mAnimQueue;

    void _applyNextAnimation();

    void setupBody();
    void setupAnimations();
    void fadeAnimations(Ogre::Real deltaTime);

	}; // end of Animable class
} // end of Hax namespace

#endif // header guard H_HAX_ANIMABLE_H
