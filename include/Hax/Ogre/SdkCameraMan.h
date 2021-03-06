/*
 -----------------------------------------------------------------------------
 This source file is part of OGRE
 (Object-oriented Graphics Rendering Engine)
 For the latest info, see http://www.ogre3d.org/

 Copyright (c) 2000-2009 Torus Knot Software Ltd

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 -----------------------------------------------------------------------------
 */
#ifndef __SdkCameraMan_H__
#define __SdkCameraMan_H__

#include "Ogre.h"
#include <OIS/OIS.h>
#include <OIS/OISMouse.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISInputManager.h>

namespace OgreBites
{
	enum CameraStyle   // enumerator values for different styles of camera movement
	{
		CS_FREELOOK,
		CS_ORBIT,
		CS_MANUAL
	};

	/*=============================================================================
	| Utility class for controlling the camera in samples.
	=============================================================================*/
	class SdkCameraMan
    {
    public:
		SdkCameraMan(Ogre::Camera* cam)
		: mCamera(0)
		, mTarget(0)
		, mOrbiting(false)
		, mZooming(false)
		, mTopSpeed(150)
		, mVelocity(Ogre::Vector3::ZERO)
		, mGoingForward(false)
		, mGoingBack(false)
		, mGoingLeft(false)
		, mGoingRight(false)
		, mGoingUp(false)
		, mGoingDown(false)
		, mFastMove(false)
    , MAX_PITCH(1.4f)
    , MIN_PITCH(0.25f)
    , MAX_Y(100)
    , MIN_Y(1)
		{
			setCamera(cam);
			setStyle(CS_FREELOOK);
		}

		virtual ~SdkCameraMan() {}

		/*-----------------------------------------------------------------------------
		| Swaps the camera on our camera man for another camera.
		-----------------------------------------------------------------------------*/
		virtual void setCamera(Ogre::Camera* cam)
		{
			mCamera = cam;
		}

		virtual Ogre::Camera* getCamera()
		{
			return mCamera;
		}

		/*-----------------------------------------------------------------------------
		| Sets the target we will revolve around. Only applies for orbit style.
		-----------------------------------------------------------------------------*/
		virtual void setTarget(Ogre::SceneNode* target)
		{
      mTarget = target;
			if (mStyle == CS_ORBIT)
			{
				mTarget = target ? target : mCamera->getSceneManager()->getRootSceneNode();
				setYawPitchDist(Ogre::Degree(0), Ogre::Degree(15), 150);
				mCamera->setAutoTracking(true, mTarget);
			}
		}

		virtual Ogre::SceneNode* getTarget()
		{
			return mTarget;
		}

		/*-----------------------------------------------------------------------------
		| Sets the spatial offset from the target. Only applies for orbit style.
		-----------------------------------------------------------------------------*/
		virtual void setYawPitchDist(Ogre::Radian yaw, Ogre::Radian pitch, Ogre::Real dist)
		{
			if (mStyle == CS_ORBIT)
			{
				if (mTarget)
        {
          mCamera->setPosition(mTarget->_getDerivedPosition());
          mCamera->setOrientation(mTarget->_getDerivedOrientation());
        }
				mCamera->yaw(yaw);
				mCamera->pitch(-pitch);
				mCamera->moveRelative(Ogre::Vector3(0, 0, dist));
			}
		}

		/*-----------------------------------------------------------------------------
		| Sets the camera's top speed. Only applies for free-look style.
		-----------------------------------------------------------------------------*/
		virtual void setTopSpeed(Ogre::Real topSpeed)
		{
			mTopSpeed = topSpeed;
		}

		virtual Ogre::Real getTopSpeed()
		{
			return mTopSpeed;
		}

		/*-----------------------------------------------------------------------------
		| Sets the movement style of our camera man.
		-----------------------------------------------------------------------------*/
		virtual void setStyle(CameraStyle style)
		{
			if (mStyle != CS_ORBIT && style == CS_ORBIT)
			{
				mStyle = CS_ORBIT;
				setTarget(mTarget);
				mCamera->setFixedYawAxis(true);
			}
			else if (mStyle != CS_FREELOOK && style == CS_FREELOOK)
			{
				mStyle = CS_FREELOOK;
				mCamera->setAutoTracking(false);
				mCamera->setFixedYawAxis(true);
			}
			else if (mStyle != CS_MANUAL && style == CS_MANUAL)
			{
				mStyle = CS_MANUAL;
				mCamera->setAutoTracking(false);
				mCamera->setFixedYawAxis(true);
			}
		}

		virtual CameraStyle getStyle()
		{
			return mStyle;
		}

		/*-----------------------------------------------------------------------------
		| Manually stops the camera when in free-look mode.
		-----------------------------------------------------------------------------*/
		virtual void manualStop()
		{
			if (mStyle == CS_FREELOOK)
			{
				mGoingForward = false;
				mGoingBack = false;
				mGoingLeft = false;
				mGoingRight = false;
				mGoingUp = false;
				mGoingDown = false;
				mVelocity = Ogre::Vector3::ZERO;
			}
		}

		virtual bool update(unsigned long lTimeElapsed)
		//virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt)
		{

      //if (mCamera->getOrientation().getPitch() > MAX_PITCH)
      //  mCamera->pitch(MAX_PITCH);
      //else if (mCamera->getOrientation().getPitch() < MIN_PITCH)
      //  mCamera->pitch(MIN_PITCH);
      //
      //Vector3 pos(mCamera->getPosition());
      //if (pos.y < MIN_Y)
      //  mCamera->setPosition(Ogre::Vector3(pos.x, MIN_Y, pos.z));
      //else if (pos.y > MAX_Y)
      //  mCamera->setPosition(Ogre::Vector3(pos.x, MAX_Y, pos.z));

      //mCamera->moveRelative(Vector3(0, MAX_Y, 0));
			if (mStyle == CS_FREELOOK)
			{
				// build our acceleration vector based on keyboard input composite
				Ogre::Vector3 accel = Ogre::Vector3::ZERO;
				if (mGoingForward) accel += mCamera->getDirection();
				if (mGoingBack) accel -= mCamera->getDirection();
				if (mGoingRight) accel += mCamera->getRight();
				if (mGoingLeft) accel -= mCamera->getRight();
				if (mGoingUp) accel += mCamera->getUp();
				if (mGoingDown) accel -= mCamera->getUp();

				// if accelerating, try to reach top speed in a certain time
				Ogre::Real topSpeed = mFastMove ? mTopSpeed * 20 : mTopSpeed;
				if (accel.squaredLength() != 0)
				{
					accel.normalise();
					mVelocity += accel * topSpeed * lTimeElapsed * 10;
				}
				// if not accelerating, try to stop in a certain time
				else mVelocity -= mVelocity * lTimeElapsed * 10;

				// keep camera velocity below top speed and above zero
				if (mVelocity.squaredLength() > topSpeed * topSpeed)
				{
					mVelocity.normalise();
					mVelocity *= topSpeed;
				}
				else if (mVelocity.squaredLength() < 0.1) mVelocity = Ogre::Vector3::ZERO;

				if (mVelocity != Ogre::Vector3::ZERO) mCamera->move(mVelocity * lTimeElapsed);
			}

			return true;
		}

		/*-----------------------------------------------------------------------------
		| Processes key presses for free-look style movement.
		-----------------------------------------------------------------------------*/
		virtual void injectKeyDown(const OIS::KeyEvent& evt)
		{
			if (mStyle == CS_FREELOOK)
			{
				if (evt.key == OIS::KC_W || evt.key == OIS::KC_UP) mGoingForward = true;
				else if (evt.key == OIS::KC_S || evt.key == OIS::KC_DOWN) mGoingBack = true;
				else if (evt.key == OIS::KC_A || evt.key == OIS::KC_LEFT) mGoingLeft = true;
				else if (evt.key == OIS::KC_D || evt.key == OIS::KC_RIGHT) mGoingRight = true;
				else if (evt.key == OIS::KC_PGUP) mGoingUp = true;
				else if (evt.key == OIS::KC_PGDOWN) mGoingDown = true;
				else if (evt.key == OIS::KC_LSHIFT) mFastMove = true;
			}
		}

		/*-----------------------------------------------------------------------------
		| Processes key releases for free-look style movement.
		-----------------------------------------------------------------------------*/
		virtual void injectKeyUp(const OIS::KeyEvent& evt)
		{
			if (mStyle == CS_FREELOOK)
			{
				if (evt.key == OIS::KC_W || evt.key == OIS::KC_UP) mGoingForward = false;
				else if (evt.key == OIS::KC_S || evt.key == OIS::KC_DOWN) mGoingBack = false;
				else if (evt.key == OIS::KC_A || evt.key == OIS::KC_LEFT) mGoingLeft = false;
				else if (evt.key == OIS::KC_D || evt.key == OIS::KC_RIGHT) mGoingRight = false;
				else if (evt.key == OIS::KC_PGUP) mGoingUp = false;
				else if (evt.key == OIS::KC_PGDOWN) mGoingDown = false;
				else if (evt.key == OIS::KC_LSHIFT) mFastMove = false;
			}
		}

		/*-----------------------------------------------------------------------------
		| Processes mouse movement differently for each style.
		-----------------------------------------------------------------------------*/
#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
		virtual void injectMouseMove(const OIS::MultiTouchEvent& evt)
#else
		virtual void injectMouseMove(const OIS::MouseEvent& evt)
#endif
		{
			if (mStyle == CS_ORBIT)
			{
				Ogre::Real dist = (mCamera->getPosition() - mTarget->_getDerivedPosition()).length();

				if (mOrbiting)   // yaw around the target, and pitch locally
				{
					mCamera->setPosition(mTarget->_getDerivedPosition());

					mCamera->yaw(Ogre::Degree(-evt.state.X.rel * 0.25f));

          //~ std::cout << "camera pitch: " << mCamera->getOrientation().getPitch() << "\n";
          if ((mCamera->getOrientation().getPitch() > MIN_PITCH && evt.state.Y.rel < 0) ||
            (mCamera->getOrientation().getPitch() < MAX_PITCH && evt.state.Y.rel > 0))
					mCamera->pitch(Ogre::Degree(-evt.state.Y.rel * 0.25f));


          mCamera->moveRelative(Ogre::Vector3(0, 0, dist));


					// don't let the camera go over the top or around the bottom of the target
				}
				else if (mZooming)  // move the camera toward or away from the target
				{
          // zooming in
          if (evt.state.Y.rel < 0 && mCamera->getPosition().y <= MIN_Y)
            return;
          // zooming out
          if (evt.state.Y.rel > 0  && mCamera->getPosition().y >= MAX_Y)
            return;

          //~ std::cout << "Event: " << evt.state.X.rel << "," << evt.state.Y.rel << "," << evt.state.Z.rel << "\n";
					// the further the camera is, the faster it moves
					mCamera->moveRelative(Ogre::Vector3(0, 0, evt.state.Y.rel * 0.004f * dist));
				}
				else if (evt.state.Z.rel != 0)  // move the camera toward or away from the target
				{

          Ogre::Vector3 pos = mCamera->getPosition();
          //~ std::cout << "Camera now at : " << pos.x << "," << pos.y << "," << pos.z << "\n";
					// the further the camera is, the faster it moves
          if (mCamera->getPosition().y >= MAX_Y && evt.state.Z.rel < 0)
            return;
          else if (mCamera->getPosition().y <= MIN_Y && evt.state.Z.rel > 0)
            return;

          mCamera->moveRelative(Ogre::Vector3(0, 0, -evt.state.Z.rel * 0.0008f * dist));
				}
			}
			else if (mStyle == CS_FREELOOK)
			{
				mCamera->yaw(Ogre::Degree(-evt.state.X.rel * 0.15f));
				mCamera->pitch(Ogre::Degree(-evt.state.Y.rel * 0.15f));
			}
		}

		/*-----------------------------------------------------------------------------
		| Processes mouse presses. Only applies for orbit style.
		| Left button is for orbiting, and right button is for zooming.
		-----------------------------------------------------------------------------*/
#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
		virtual void injectMouseDown(const OIS::MultiTouchEvent& evt)
		{
			if (mStyle == CS_ORBIT)
			{
                mOrbiting = true;
			}
		}
#else
		virtual void injectMouseDown(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
		{
			if (mStyle == CS_ORBIT)
			{
				if (id == OIS::MB_Left) mOrbiting = true;
				else if (id == OIS::MB_Right) mZooming = true;
			}
		}
#endif

		/*-----------------------------------------------------------------------------
		| Processes mouse releases. Only applies for orbit style.
		| Left button is for orbiting, and right button is for zooming.
		-----------------------------------------------------------------------------*/
#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
		virtual void injectMouseUp(const OIS::MultiTouchEvent& evt)
		{
			if (mStyle == CS_ORBIT)
			{
                mOrbiting = false;
			}
		}
#else
		virtual void injectMouseUp(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
		{
			if (mStyle == CS_ORBIT)
			{
				if (id == OIS::MB_Left) mOrbiting = false;
				else if (id == OIS::MB_Right) mZooming = false;
			}
		}
#endif

    protected:

		Ogre::Camera* mCamera;
		CameraStyle mStyle;
		Ogre::SceneNode* mTarget;
		bool mOrbiting;
		bool mZooming;
		Ogre::Real mTopSpeed;
		Ogre::Vector3 mVelocity;
		bool mGoingForward;
		bool mGoingBack;
		bool mGoingLeft;
		bool mGoingRight;
		bool mGoingUp;
		bool mGoingDown;
		bool mFastMove;

    int MAX_Y;
    int MIN_Y;
    Ogre::Radian MAX_PITCH;
    Ogre::Radian MIN_PITCH;
    };
}

#endif
