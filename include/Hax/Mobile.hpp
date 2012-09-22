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

#ifndef H_HAX_MOBILE_H
#define H_HAX_MOBILE_H

#include "Hax/Hax.hpp"

#include <Ogre.h>
#include <boost/function.hpp>
#include <boost/asio.hpp>

using Ogre::Real;
using Ogre::Vector3;
namespace Hax
{
  //~ class Unit;
  class Renderable;
	class Mobile
	{
    public:

		Mobile();
		Mobile& operator=(const Mobile& rhs);
		Mobile(const Mobile& src);
		virtual ~Mobile();

    void move(int inWaypoint);

    void step(unsigned long dt);
    bool isMoving() const;

    void setWaypoints(std::vector<Vector3>* inWp);

    void setWalkSpeed(const float inSpeed);
    float getWalkSpeed() const;

    static void setDefaultWalkSpeed(const float inSpeed);
    static float getDefaultWalkSpeed();

    void rotateToEnemy();
    void rotateTo(const Ogre::Vector3& inDest);

    static void setRotationFactor(float inFactor);


		protected:

    /**
     * @brief
     * Registers the given SceneNode and Ogre Entity to be used for animating and
     * prepares the Mobile object.
     *
     * @warning
     * This function MUST be called before any usage of the Mobile instance.
     **/
    void setup(Renderable*);

    /**
     * @brief
     * Hooks a callback method that will be invoked when this entity is done moving
     **/
    void hookOnDoneMoving(boost::function<void(Mobile*)>);

    void copyFrom(const Mobile& src);

    private:

    bool fIsMoving;
    //! used  for tracking the Node's destination
    Vector3 mDestination;
    int mDestinationWP;
    //! used  for tracking and updating Node's direction while moving
    Vector3 mMoveDirection;
    //! used  for calculating the distance left to travel
    Real mMoveDistance;
    //! fixed speed to be used later by mMoveSpeed
    Real mWalkSpeed;
    //! regulates the movement speed by (mWalkSpeed * mTimeElapsed) keeping it consistent
    Real mMoveSpeed;
    std::vector<Vector3>* mWaypoints;
    static float mDefaultWalkSpeed;

    boost::function<void(Mobile*)> mCallback;

    bool setMoving(bool inMoving) {
      fIsMoving = inMoving;
    }

    bool doMove(unsigned long);

    /*!
     * @brief
     * Informs whether the SceneNode has reached its destination and updates the distance left,
     * and the direction the node should be facing.
     *
     * @note used by moveUnit()
     *
     * @return true the Unit still has not reached its destination
     * @return false the Unit should not move further
     */
    bool nextLocation(int inDestination);

    Renderable *mRenderable;

    //Ogre::SceneNode *mSceneNode;
    //Ogre::Entity *mSceneObject;
    Ogre::RaySceneQuery *mRaySceneQuery;

    // for rotation
    Ogre::Quaternion mOrientSrc;               // Initial orientation
    Ogre::Quaternion mOrientDest;              // Destination orientation
    Ogre::Real mRotProgress;                   // How far we've interpolated
    static Ogre::Real mRotFactor;                     // Interpolation step
    bool fRotating;

	}; // end of Mobile class
} // end of Hax namespace
#endif
