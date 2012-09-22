/*
 *  Copyright (c) 2011-2012:
 *  Author: gerds <http://www.ogre3d.org/tikiwiki/Raycasting+to+the+polygon+level&structure=Cookbook>
 *  Modified by: Ahmad Amireh <ahmad@amireh.net>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 */

#ifndef H_HAX_OGRE_MOUSE_PICKER_H
#define H_HAX_OGRE_MOUSE_PICKER_H

#include "Ogre.h"
#include "CEGUI/CEGUI.h"
#include "OIS.h"

namespace CEGUI {
  // typedef Vector2<float> Point;
}

namespace Hax {

  class MousePicker {
    public:

    MousePicker(Ogre::SceneManager*);
    virtual ~MousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK)=0;

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK)=0;

    protected:

    Ogre::SceneManager *mSceneMgr;
    Ogre::RaySceneQuery *mRayQuery;
  };

  class GenericMousePicker : MousePicker {
    public:

    GenericMousePicker(Ogre::SceneManager*);
    virtual ~GenericMousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);
  };

  class PolyMousePicker : MousePicker {
    public:

    //typedef bool (*filter_t)(Ogre::MovableObject*);

    PolyMousePicker(Ogre::SceneManager*);
    virtual ~PolyMousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    void setStep(Ogre::Real);
    Ogre::Real getStep() const;

    private:

    bool
    RaycastFromPoint(
      const Ogre::Vector3 &point,
      const Ogre::Vector3 &normal,
      Ogre::Vector3 &result,
      Ogre::MovableObject** out,
      Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    void
    GetMeshInformation(
      Ogre::Entity *entity,
      size_t &vertex_count,
      Ogre::Vector3* &vertices,
      size_t &index_count,
      Ogre::uint32* &indices,
      const Ogre::Vector3 &position,
      const Ogre::Quaternion &orient,
      const Ogre::Vector3 &scale);

    Ogre::Vector2 mCorners[9];
    Ogre::Real    mStep;

    void generateCorners();
    //void assignFilter(filter_t inFilter);

    //private:
    //Ogre::RaySceneQuery *m_pray_scene_query;
    //Ogre::SceneManager  *m_pscene_manager;

    //filter_t filter;
  };


}

#endif
