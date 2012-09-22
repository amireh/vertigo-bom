/*
** Lua binding: Hax
** Generated automatically by tolua++-1.0.92 on Sat Sep 22 12:14:45 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Hax_open (lua_State* tolua_S);

#include "Hax/Hax.hpp"
typedef std::string string_t;
#include "Hax/Animable.hpp"
#include "Hax/Entity.hpp"
#include "Hax/Renderable.hpp"
#include "Hax/Mobile.hpp"
#include "Hax/FxEngine.hpp"
#include "Hax/Event.hpp"
#include "Hax/EventManager.hpp"
#include "Hax/EventListener.hpp"
#include "Hax/GameManager.hpp"
#include "Hax/GameState.hpp"
#include "Hax/GfxEngine.hpp"
#include <Ogre.h>
#include "Hax/Intro.hpp"
#include "Hax/InputManager.hpp"
#include "Hax/ScriptEngine.hpp"
#include "Hax/LuaExporter.hpp"
#include "Hax/ScriptEngine.hpp"
#include <lua.h>
#include "Hax/UIEngine.hpp"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Ogre__Vector2 (lua_State* tolua_S)
{
 Ogre::Vector2* self = (Ogre::Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__Mobile (lua_State* tolua_S)
{
 Hax::Mobile* self = (Hax::Mobile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__LuaExporter_std__list_Hax__Entity____ (lua_State* tolua_S)
{
 Hax::LuaExporter<std::list<Hax::Entity*> >* self = (Hax::LuaExporter<std::list<Hax::Entity*> >*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__FxEngine (lua_State* tolua_S)
{
 Hax::FxEngine* self = (Hax::FxEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__Renderable (lua_State* tolua_S)
{
 Hax::Renderable* self = (Hax::Renderable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__Entity (lua_State* tolua_S)
{
 Hax::Entity* self = (Hax::Entity*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__Animable (lua_State* tolua_S)
{
 Hax::Animable* self = (Hax::Animable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__EventListener (lua_State* tolua_S)
{
 Hax::EventListener* self = (Hax::EventListener*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__Event (lua_State* tolua_S)
{
 Hax::Event* self = (Hax::Event*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hax__LuaExporter_std__vector_Hax__Entity____ (lua_State* tolua_S)
{
 Hax::LuaExporter<std::vector<Hax::Entity*> >* self = (Hax::LuaExporter<std::vector<Hax::Entity*> >*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Ogre::Vector2");
 tolua_usertype(tolua_S,"Hax::Mobile");
 tolua_usertype(tolua_S,"Hax::Unit");
 tolua_usertype(tolua_S,"Hax::Engine");
 tolua_usertype(tolua_S,"std::map<string_t,string_t>");
 tolua_usertype(tolua_S,"Ogre::RenderWindow");
 tolua_usertype(tolua_S,"Hax::EventListener");
 tolua_usertype(tolua_S,"Ogre::SceneManager");
 tolua_usertype(tolua_S,"Hax::Intro");
 tolua_usertype(tolua_S,"Hax::Event");
 tolua_usertype(tolua_S,"Hax::UIEngine");
 tolua_usertype(tolua_S,"Hax::FxEngine");
 tolua_usertype(tolua_S,"Ogre::Viewport");
 tolua_usertype(tolua_S,"Hax::Entity");
 tolua_usertype(tolua_S,"Hax::Animable");
 tolua_usertype(tolua_S,"MovableTextOverlay");
 tolua_usertype(tolua_S,"Hax::GfxEngine");
 tolua_usertype(tolua_S,"Hax::LuaExporter<std::list<Hax::Entity*> >");
 tolua_usertype(tolua_S,"Hax::GameManager");
 tolua_usertype(tolua_S,"Hax::Renderable");
 tolua_usertype(tolua_S,"OgreBites::SdkCameraMan");
 tolua_usertype(tolua_S,"Ogre::String");
 tolua_usertype(tolua_S,"CEGUI::UBox");
 tolua_usertype(tolua_S,"Ogre::Root");
 tolua_usertype(tolua_S,"OIS::Keyboard");
 tolua_usertype(tolua_S,"Hax::EventManager");
 tolua_usertype(tolua_S,"CEGUI::Window");
 tolua_usertype(tolua_S,"std::ostream");
 tolua_usertype(tolua_S,"Ogre::ColourValue");
 tolua_usertype(tolua_S,"Hax::ScriptEngine");
 tolua_usertype(tolua_S,"Hax::LuaExporter<std::vector<Hax::Entity*> >");
 tolua_usertype(tolua_S,"Hax::InputManager");
 tolua_usertype(tolua_S,"Ogre::Entity");
 tolua_usertype(tolua_S,"Ogre::Vector3");
 tolua_usertype(tolua_S,"std::vector<Vector3>");
 tolua_usertype(tolua_S,"Hax::GameState");
 tolua_usertype(tolua_S,"Ogre::SceneNode");
 tolua_usertype(tolua_S,"Ogre::MovableObject");
 tolua_usertype(tolua_S,"const");
 tolua_usertype(tolua_S,"Ogre::Camera");
}

/* method: new of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_new00
static int tolua_Hax_Hax_Renderable_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Renderable* tolua_ret = (Hax::Renderable*)  Mtolua_new((Hax::Renderable)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_new00_local
static int tolua_Hax_Hax_Renderable_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Renderable* tolua_ret = (Hax::Renderable*)  Mtolua_new((Hax::Renderable)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Renderable");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_new01
static int tolua_Hax_Hax_Renderable_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Renderable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Renderable* src = ((const Hax::Renderable*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Renderable* tolua_ret = (Hax::Renderable*)  Mtolua_new((Hax::Renderable)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Renderable");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Renderable_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_new01_local
static int tolua_Hax_Hax_Renderable_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Renderable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Renderable* src = ((const Hax::Renderable*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Renderable* tolua_ret = (Hax::Renderable*)  Mtolua_new((Hax::Renderable)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Renderable");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Renderable_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_delete00
static int tolua_Hax_Hax_Renderable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneNode of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_attachSceneNode00
static int tolua_Hax_Hax_Renderable_attachSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* inNode = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneNode'", NULL);
#endif
  {
   self->attachSceneNode(inNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneNode of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_getSceneNode00
static int tolua_Hax_Hax_Renderable_getSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Renderable* self = (const Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneNode'", NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneObject of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_attachSceneObject00
static int tolua_Hax_Hax_Renderable_attachSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Entity* inObject = ((Ogre::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneObject'", NULL);
#endif
  {
   self->attachSceneObject(inObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneObject of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_getSceneObject00
static int tolua_Hax_Hax_Renderable_getSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Renderable* self = (const Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneObject'", NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->getSceneObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachExtension of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_attachExtension00
static int tolua_Hax_Hax_Renderable_attachExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
  string_t const* inMesh = ((string_t const*)  tolua_tousertype(tolua_S,2,0));
  string_t const* inBone = ((string_t const*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachExtension'", NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->attachExtension(*inMesh,*inBone);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMesh of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_getMesh00
static int tolua_Hax_Hax_Renderable_getMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Renderable* self = (const Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMesh'", NULL);
#endif
  {
   string_t const& tolua_ret = (string_t const&)  self->getMesh();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterial of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_getMaterial00
static int tolua_Hax_Hax_Renderable_getMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Renderable* self = (const Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterial'", NULL);
#endif
  {
   string_t const& tolua_ret = (string_t const&)  self->getMaterial();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterial of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_setMaterial00
static int tolua_Hax_Hax_Renderable_setMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
  string_t const* tolua_var_6 = ((string_t const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterial'", NULL);
#endif
  {
   self->setMaterial(*tolua_var_6);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMesh of class  Hax::Renderable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Renderable_setMesh00
static int tolua_Hax_Hax_Renderable_setMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Renderable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Renderable* self = (Hax::Renderable*)  tolua_tousertype(tolua_S,1,0);
  string_t const* tolua_var_7 = ((string_t const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMesh'", NULL);
#endif
  {
   self->setMesh(*tolua_var_7);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_new00
static int tolua_Hax_Hax_Animable_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Animable* tolua_ret = (Hax::Animable*)  Mtolua_new((Hax::Animable)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Animable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_new00_local
static int tolua_Hax_Hax_Animable_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Animable* tolua_ret = (Hax::Animable*)  Mtolua_new((Hax::Animable)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Animable");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_new01
static int tolua_Hax_Hax_Animable_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Animable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Animable* src = ((const Hax::Animable*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Animable* tolua_ret = (Hax::Animable*)  Mtolua_new((Hax::Animable)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Animable");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Animable_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_new01_local
static int tolua_Hax_Hax_Animable_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Animable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Animable* src = ((const Hax::Animable*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Animable* tolua_ret = (Hax::Animable*)  Mtolua_new((Hax::Animable)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Animable");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Animable_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_delete00
static int tolua_Hax_Hax_Animable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerAnimationState of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_registerAnimationState00
static int tolua_Hax_Hax_Animable_registerAnimationState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
  Hax::Animable::AnimID inId = ((Hax::Animable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
   std::string inState = ((  std::string)  tolua_tocppstring(tolua_S,3,0));
  bool doLoop = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerAnimationState'", NULL);
#endif
  {
   self->registerAnimationState(inId,inState,doLoop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerAnimationState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_step00
static int tolua_Hax_Hax_Animable_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
  unsigned long deltaTime = ((unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(deltaTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateLive of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateLive00
static int tolua_Hax_Hax_Animable_animateLive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateLive'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateLive();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateLive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateDie of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateDie00
static int tolua_Hax_Hax_Animable_animateDie00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateDie'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateDie();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateDie'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateIdle of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateIdle00
static int tolua_Hax_Hax_Animable_animateIdle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateIdle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateIdle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateIdle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateWalk of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateWalk00
static int tolua_Hax_Hax_Animable_animateWalk00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateWalk'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateWalk();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateWalk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRun of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateRun00
static int tolua_Hax_Hax_Animable_animateRun00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRun'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRun();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateAttack of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateAttack00
static int tolua_Hax_Hax_Animable_animateAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateAttack'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateAttack();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateHit of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateHit00
static int tolua_Hax_Hax_Animable_animateHit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateHit'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateHit();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRest of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateRest00
static int tolua_Hax_Hax_Animable_animateRest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRest'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRest();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateGetUp of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_animateGetUp00
static int tolua_Hax_Hax_Animable_animateGetUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateGetUp'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateGetUp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateGetUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _animate of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable__animate00
static int tolua_Hax_Hax_Animable__animate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Animable* self = (Hax::Animable*)  tolua_tousertype(tolua_S,1,0);
  Hax::Animable::AnimID inId = ((Hax::Animable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
  bool override = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_animate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->_animate(inId,override);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_animate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimFadeSpeed of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_setAnimFadeSpeed00
static int tolua_Hax_Hax_Animable_setAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Animable::setAnimFadeSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimFadeSpeed of class  Hax::Animable */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Animable_getAnimFadeSpeed00
static int tolua_Hax_Hax_Animable_getAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Animable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Hax::Animable::getAnimFadeSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_new00
static int tolua_Hax_Hax_Entity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Entity* tolua_ret = (Hax::Entity*)  Mtolua_new((Hax::Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_new00_local
static int tolua_Hax_Hax_Entity_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Entity* tolua_ret = (Hax::Entity*)  Mtolua_new((Hax::Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Entity");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_delete00
static int tolua_Hax_Hax_Entity_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setup of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setup00
static int tolua_Hax_Hax_Entity_setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneManager* tolua_var_1 = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'", NULL);
#endif
  {
   self->setup(tolua_var_1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: live of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_live00
static int tolua_Hax_Hax_Entity_live00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'live'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->live();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'live'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: die of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_die00
static int tolua_Hax_Hax_Entity_die00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'die'", NULL);
#endif
  {
   self->die();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'die'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getText of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getText00
static int tolua_Hax_Hax_Entity_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'", NULL);
#endif
  {
   MovableTextOverlay* tolua_ret = (MovableTextOverlay*)  self->getText();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MovableTextOverlay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setText00
static int tolua_Hax_Hax_Entity_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  MovableTextOverlay* inT = ((MovableTextOverlay*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   self->setText(inT);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTextOverlay of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_updateTextOverlay00
static int tolua_Hax_Hax_Entity_updateTextOverlay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTextOverlay'", NULL);
#endif
  {
   self->updateTextOverlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTextOverlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_hide00
static int tolua_Hax_Hax_Entity_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_show00
static int tolua_Hax_Hax_Entity_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __setUID of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity___setUID00
static int tolua_Hax_Hax_Entity___setUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_2 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__setUID'", NULL);
#endif
  {
   self->__setUID(tolua_var_2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__setUID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUID of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getUID00
static int tolua_Hax_Hax_Entity_getUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getUID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __setName of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity___setName00
static int tolua_Hax_Hax_Entity___setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
   std::string tolua_var_3 = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__setName'", NULL);
#endif
  {
   self->__setName(tolua_var_3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getName00
static int tolua_Hax_Hax_Entity_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerAnimationState of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_registerAnimationState00
static int tolua_Hax_Hax_Entity_registerAnimationState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  Hax::Animable::AnimID inId = ((Hax::Animable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
   std::string inState = ((  std::string)  tolua_tocppstring(tolua_S,3,0));
  bool doLoop = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerAnimationState'", NULL);
#endif
  {
   self->registerAnimationState(inId,inState,doLoop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerAnimationState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateLive of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateLive00
static int tolua_Hax_Hax_Entity_animateLive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateLive'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateLive();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateLive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateDie of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateDie00
static int tolua_Hax_Hax_Entity_animateDie00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateDie'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateDie();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateDie'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateIdle of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateIdle00
static int tolua_Hax_Hax_Entity_animateIdle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateIdle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateIdle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateIdle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateWalk of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateWalk00
static int tolua_Hax_Hax_Entity_animateWalk00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateWalk'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateWalk();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateWalk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRun of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateRun00
static int tolua_Hax_Hax_Entity_animateRun00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRun'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRun();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateAttack of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateAttack00
static int tolua_Hax_Hax_Entity_animateAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateAttack'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateAttack();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateHit of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateHit00
static int tolua_Hax_Hax_Entity_animateHit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateHit'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateHit();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRest of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateRest00
static int tolua_Hax_Hax_Entity_animateRest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRest'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRest();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateGetUp of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_animateGetUp00
static int tolua_Hax_Hax_Entity_animateGetUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateGetUp'", NULL);
#endif
  {
   float tolua_ret = (float)  self->animateGetUp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateGetUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _animate of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity__animate00
static int tolua_Hax_Hax_Entity__animate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  Hax::Animable::AnimID inId = ((Hax::Animable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
  bool override = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_animate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->_animate(inId,override);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_animate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimFadeSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setAnimFadeSpeed00
static int tolua_Hax_Hax_Entity_setAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Entity::setAnimFadeSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimFadeSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getAnimFadeSpeed00
static int tolua_Hax_Hax_Entity_getAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Hax::Entity::getAnimFadeSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneNode of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_attachSceneNode00
static int tolua_Hax_Hax_Entity_attachSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* inNode = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneNode'", NULL);
#endif
  {
   self->attachSceneNode(inNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneNode of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getSceneNode00
static int tolua_Hax_Hax_Entity_getSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneNode'", NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneObject of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_attachSceneObject00
static int tolua_Hax_Hax_Entity_attachSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Entity* inObject = ((Ogre::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneObject'", NULL);
#endif
  {
   self->attachSceneObject(inObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneObject of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getSceneObject00
static int tolua_Hax_Hax_Entity_getSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneObject'", NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->getSceneObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachExtension of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_attachExtension00
static int tolua_Hax_Hax_Entity_attachExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
   std::string inMesh = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
   std::string inBone = ((  std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachExtension'", NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->attachExtension(inMesh,inBone);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMesh of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getMesh00
static int tolua_Hax_Hax_Entity_getMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMesh'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getMesh();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterial of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getMaterial00
static int tolua_Hax_Hax_Entity_getMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterial'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getMaterial();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterial of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setMaterial00
static int tolua_Hax_Hax_Entity_setMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
   std::string tolua_var_4 = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterial'", NULL);
#endif
  {
   self->setMaterial(tolua_var_4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMesh of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setMesh00
static int tolua_Hax_Hax_Entity_setMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
   std::string tolua_var_5 = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMesh'", NULL);
#endif
  {
   self->setMesh(tolua_var_5);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_move00
static int tolua_Hax_Hax_Entity_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  int inWaypoint = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(inWaypoint);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isMoving of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_isMoving00
static int tolua_Hax_Hax_Entity_isMoving00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isMoving'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isMoving();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isMoving'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWaypoints of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setWaypoints00
static int tolua_Hax_Hax_Entity_setWaypoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"std::vector<Vector3>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  std::vector<Vector3>* inWp = ((std::vector<Vector3>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWaypoints'", NULL);
#endif
  {
   self->setWaypoints(inWp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWaypoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWalkSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setWalkSpeed00
static int tolua_Hax_Hax_Entity_setWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Entity* self = (Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWalkSpeed'", NULL);
#endif
  {
   self->setWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWalkSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getWalkSpeed00
static int tolua_Hax_Hax_Entity_getWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Entity* self = (const Hax::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWalkSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultWalkSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setDefaultWalkSpeed00
static int tolua_Hax_Hax_Entity_setDefaultWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Entity::setDefaultWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultWalkSpeed of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_getDefaultWalkSpeed00
static int tolua_Hax_Hax_Entity_getDefaultWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Hax::Entity::getDefaultWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationFactor of class  Hax::Entity */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Entity_setRotationFactor00
static int tolua_Hax_Hax_Entity_setRotationFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inFactor = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Entity::setRotationFactor(inFactor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_new00
static int tolua_Hax_Hax_Mobile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Mobile* tolua_ret = (Hax::Mobile*)  Mtolua_new((Hax::Mobile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Mobile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_new00_local
static int tolua_Hax_Hax_Mobile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Mobile* tolua_ret = (Hax::Mobile*)  Mtolua_new((Hax::Mobile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Mobile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_new01
static int tolua_Hax_Hax_Mobile_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Mobile",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Mobile* src = ((const Hax::Mobile*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Mobile* tolua_ret = (Hax::Mobile*)  Mtolua_new((Hax::Mobile)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Mobile");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Mobile_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_new01_local
static int tolua_Hax_Hax_Mobile_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Mobile",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Mobile* src = ((const Hax::Mobile*)  tolua_tousertype(tolua_S,2,0));
  {
   Hax::Mobile* tolua_ret = (Hax::Mobile*)  Mtolua_new((Hax::Mobile)(*src));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Mobile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Mobile_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_delete00
static int tolua_Hax_Hax_Mobile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_move00
static int tolua_Hax_Hax_Mobile_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
  int inWaypoint = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(inWaypoint);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_step00
static int tolua_Hax_Hax_Mobile_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
  unsigned long dt = ((unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
  {
   self->step(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isMoving of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_isMoving00
static int tolua_Hax_Hax_Mobile_isMoving00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Mobile* self = (const Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isMoving'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isMoving();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isMoving'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWaypoints of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_setWaypoints00
static int tolua_Hax_Hax_Mobile_setWaypoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"std::vector<Vector3>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
  std::vector<Vector3>* inWp = ((std::vector<Vector3>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWaypoints'", NULL);
#endif
  {
   self->setWaypoints(inWp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWaypoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWalkSpeed of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_setWalkSpeed00
static int tolua_Hax_Hax_Mobile_setWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWalkSpeed'", NULL);
#endif
  {
   self->setWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWalkSpeed of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_getWalkSpeed00
static int tolua_Hax_Hax_Mobile_getWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Mobile* self = (const Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWalkSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultWalkSpeed of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_setDefaultWalkSpeed00
static int tolua_Hax_Hax_Mobile_setDefaultWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Mobile::setDefaultWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultWalkSpeed of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_getDefaultWalkSpeed00
static int tolua_Hax_Hax_Mobile_getDefaultWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Hax::Mobile::getDefaultWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateToEnemy of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_rotateToEnemy00
static int tolua_Hax_Hax_Mobile_rotateToEnemy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateToEnemy'", NULL);
#endif
  {
   self->rotateToEnemy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateToEnemy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateTo of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_rotateTo00
static int tolua_Hax_Hax_Mobile_rotateTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Mobile* self = (Hax::Mobile*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* inDest = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateTo'", NULL);
#endif
  {
   self->rotateTo(*inDest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationFactor of class  Hax::Mobile */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Mobile_setRotationFactor00
static int tolua_Hax_Hax_Mobile_setRotationFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inFactor = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Hax::Mobile::setRotationFactor(inFactor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_new00
static int tolua_Hax_Hax_Event_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Event* tolua_ret = (Hax::Event*)  Mtolua_new((Hax::Event)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Event");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_new00_local
static int tolua_Hax_Hax_Event_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Event* tolua_ret = (Hax::Event*)  Mtolua_new((Hax::Event)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Event");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_new01
static int tolua_Hax_Hax_Event_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned const char inUID = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
  unsigned const char tolua_var_8 = ((unsigned const char)  tolua_tonumber(tolua_S,3,Hax::EventFeedback::Unassigned));
  unsigned char options = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Hax::Event* tolua_ret = (Hax::Event*)  Mtolua_new((Hax::Event)(inUID,tolua_var_8,options));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Event");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Event_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_new01_local
static int tolua_Hax_Hax_Event_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned const char inUID = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
  unsigned const char tolua_var_8 = ((unsigned const char)  tolua_tonumber(tolua_S,3,Hax::EventFeedback::Unassigned));
  unsigned char options = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Hax::Event* tolua_ret = (Hax::Event*)  Mtolua_new((Hax::Event)(inUID,tolua_var_8,options));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Event");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Hax_Hax_Event_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_delete00
static int tolua_Hax_Hax_Event_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProperty of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_getProperty00
static int tolua_Hax_Hax_Event_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Event* self = (const Hax::Event*)  tolua_tousertype(tolua_S,1,0);
   std::string inName = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getProperty(inName);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProperty of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_setProperty00
static int tolua_Hax_Hax_Event_setProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string inValue = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProperty'", NULL);
#endif
  {
   self->setProperty(inName,inValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasProperty of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_hasProperty00
static int tolua_Hax_Hax_Event_hasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Event* self = (const Hax::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasProperty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasProperty(inName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dump of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_dump00
static int tolua_Hax_Hax_Event_dump00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::Event* self = (const Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dump'", NULL);
#endif
  {
   self->dump();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dump'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dump of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_dump01
static int tolua_Hax_Hax_Event_dump01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::Event",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::ostream",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Hax::Event* self = (const Hax::Event*)  tolua_tousertype(tolua_S,1,0);
  std::ostream* inStream = ((std::ostream*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dump'", NULL);
#endif
  {
   self->dump(*inStream);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Hax_Hax_Event_dump00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UID of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_unsigned_UID
static int tolua_get_Hax__Event_unsigned_UID(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->UID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: UID of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_set_Hax__Event_unsigned_UID
static int tolua_set_Hax__Event_unsigned_UID(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->UID = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Options of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_unsigned_Options
static int tolua_get_Hax__Event_unsigned_Options(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Options'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Options);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Options of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_set_Hax__Event_unsigned_Options
static int tolua_set_Hax__Event_unsigned_Options(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Options'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Options = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Feedback of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_unsigned_Feedback
static int tolua_get_Hax__Event_unsigned_Feedback(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Feedback'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Feedback);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Feedback of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_set_Hax__Event_unsigned_Feedback
static int tolua_set_Hax__Event_unsigned_Feedback(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Feedback'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Feedback = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Properties of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_Properties
static int tolua_get_Hax__Event_Properties(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Properties'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Properties,"std::map<string_t,string_t>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Properties of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_set_Hax__Event_Properties
static int tolua_set_Hax__Event_Properties(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Properties'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::map<string_t,string_t>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Properties = *((  std::map<string_t,string_t>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Footer of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_Footer
static int tolua_get_Hax__Event_Footer(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Hax::Event::Footer);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Any of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_get_Hax__Event_Any
static int tolua_get_Hax__Event_Any(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Any'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->Any);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Any of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_set_Hax__Event_Any
static int tolua_set_Hax__Event_Any(lua_State* tolua_S)
{
  Hax::Event* self = (Hax::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Any'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Any = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: __uidToString of class  Hax::Event */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Event_UIDToString00
static int tolua_Hax_Hax_Event_UIDToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Event",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char tolua_var_9 = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Hax::Event::__uidToString(tolua_var_9);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UIDToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getSingletonPtr00
static int tolua_Hax_Hax_GfxEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::GfxEngine* tolua_ret = (Hax::GfxEngine*)  Hax::GfxEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::GfxEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontColor of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__GfxEngine_mMTOFontColor
static int tolua_get_Hax__GfxEngine_mMTOFontColor(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontColor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMTOFontColor,"Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontColor of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Hax__GfxEngine_mMTOFontColor
static int tolua_set_Hax__GfxEngine_mMTOFontColor(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontColor'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::ColourValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontColor = *((Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontName of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__GfxEngine_mMTOFontName
static int tolua_get_Hax__GfxEngine_mMTOFontName(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMTOFontName,"Ogre::String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontName of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Hax__GfxEngine_mMTOFontName
static int tolua_set_Hax__GfxEngine_mMTOFontName(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontName = *((Ogre::String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontSize of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__GfxEngine_mMTOFontSize
static int tolua_get_Hax__GfxEngine_mMTOFontSize(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mMTOFontSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontSize of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Hax__GfxEngine_mMTOFontSize
static int tolua_set_Hax__GfxEngine_mMTOFontSize(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontSize = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOMaterialName of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__GfxEngine_mMTOMaterialName
static int tolua_get_Hax__GfxEngine_mMTOMaterialName(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOMaterialName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMTOMaterialName,"Ogre::String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOMaterialName of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Hax__GfxEngine_mMTOMaterialName
static int tolua_set_Hax__GfxEngine_mMTOMaterialName(lua_State* tolua_S)
{
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOMaterialName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOMaterialName = *((Ogre::String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableMouseCaptureOverUIElement of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_disableMouseCaptureOverUIElement00
static int tolua_Hax_Hax_GfxEngine_disableMouseCaptureOverUIElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
   std::string inElementName = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableMouseCaptureOverUIElement'", NULL);
#endif
  {
   self->disableMouseCaptureOverUIElement(inElementName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableMouseCaptureOverUIElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableMouseCaptureOverUIElement of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_enableMouseCaptureOverUIElement00
static int tolua_Hax_Hax_GfxEngine_enableMouseCaptureOverUIElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
   std::string inElementName = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableMouseCaptureOverUIElement'", NULL);
#endif
  {
   self->enableMouseCaptureOverUIElement(inElementName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableMouseCaptureOverUIElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCamera of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_setCamera00
static int tolua_Hax_Hax_GfxEngine_setCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::String inCameraName = *((Ogre::String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCamera'", NULL);
#endif
  {
   self->setCamera(inCameraName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: switchMousePickingMode of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_switchMousePickingMode00
static int tolua_Hax_Hax_GfxEngine_switchMousePickingMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'switchMousePickingMode'", NULL);
#endif
  {
   self->switchMousePickingMode();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'switchMousePickingMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMousePickingMode of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getMousePickingMode00
static int tolua_Hax_Hax_GfxEngine_getMousePickingMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::GfxEngine* self = (const Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMousePickingMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMousePickingMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMousePickingMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachToScene of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_attachToScene00
static int tolua_Hax_Hax_GfxEngine_attachToScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Hax::Entity* inEntity = ((Hax::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachToScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachToScene(inEntity);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachToScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachFromScene of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_detachFromScene00
static int tolua_Hax_Hax_GfxEngine_detachFromScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Hax::Entity* inEntity = ((Hax::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachFromScene'", NULL);
#endif
  {
   self->detachFromScene(inEntity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachFromScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupMovableTextOverlays of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_setupMovableTextOverlays00
static int tolua_Hax_Hax_GfxEngine_setupMovableTextOverlays00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupMovableTextOverlays'", NULL);
#endif
  {
   self->setupMovableTextOverlays();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupMovableTextOverlays'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCameraMan of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getCameraMan00
static int tolua_Hax_Hax_GfxEngine_getCameraMan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCameraMan'", NULL);
#endif
  {
   OgreBites::SdkCameraMan* tolua_ret = (OgreBites::SdkCameraMan*)  self->getCameraMan();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OgreBites::SdkCameraMan");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCameraMan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getCamera00
static int tolua_Hax_Hax_GfxEngine_getCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'", NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->getCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoot of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getRoot00
static int tolua_Hax_Hax_GfxEngine_getRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoot'", NULL);
#endif
  {
   Ogre::Root* tolua_ret = (Ogre::Root*)  self->getRoot();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Root");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneMgr of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getSceneMgr00
static int tolua_Hax_Hax_GfxEngine_getSceneMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneMgr'", NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getSceneMgr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindow of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getWindow00
static int tolua_Hax_Hax_GfxEngine_getWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindow'", NULL);
#endif
  {
   Ogre::RenderWindow* tolua_ret = (Ogre::RenderWindow*)  self->getWindow();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::RenderWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewport of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getViewport00
static int tolua_Hax_Hax_GfxEngine_getViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewport'", NULL);
#endif
  {
   Ogre::Viewport* tolua_ret = (Ogre::Viewport*)  self->getViewport();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Viewport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSelected of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getSelected00
static int tolua_Hax_Hax_GfxEngine_getSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelected'", NULL);
#endif
  {
   Hax::Entity* tolua_ret = (Hax::Entity*)  self->getSelected();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateMe of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_updateMe00
static int tolua_Hax_Hax_GfxEngine_updateMe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Hax::Mobile* tolua_var_10 = ((Hax::Mobile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateMe'", NULL);
#endif
  {
   self->updateMe(tolua_var_10);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateMe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopUpdatingMe of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_stopUpdatingMe00
static int tolua_Hax_Hax_GfxEngine_stopUpdatingMe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::Mobile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Hax::Mobile* tolua_var_11 = ((Hax::Mobile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopUpdatingMe'", NULL);
#endif
  {
   self->stopUpdatingMe(tolua_var_11);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopUpdatingMe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableCompositorEffect of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_enableCompositorEffect00
static int tolua_Hax_Hax_GfxEngine_enableCompositorEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
   std::string inEffect = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableCompositorEffect'", NULL);
#endif
  {
   self->enableCompositorEffect(inEffect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableCompositorEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScreenCoords of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_getScreenCoords00
static int tolua_Hax_Hax_GfxEngine_getScreenCoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* inObject = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScreenCoords'", NULL);
#endif
  {
   Ogre::Vector2 tolua_ret = (Ogre::Vector2)  self->getScreenCoords(inObject);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScreenCoords'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setYawPitchDist of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_setYawPitchDist00
static int tolua_Hax_Hax_GfxEngine_setYawPitchDist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Vector3 inVec = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYawPitchDist'", NULL);
#endif
  {
   self->setYawPitchDist(inVec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setYawPitchDist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: trackNode of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_trackNode00
static int tolua_Hax_Hax_GfxEngine_trackNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* inNode = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'trackNode'", NULL);
#endif
  {
   self->trackNode(inNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'trackNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _setUserAny of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine__setUserAny00
static int tolua_Hax_Hax_GfxEngine__setUserAny00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* tolua_var_12 = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
  void* tolua_var_13 = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_setUserAny'", NULL);
#endif
  {
   self->_setUserAny(tolua_var_12,tolua_var_13);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_setUserAny'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createColourCube of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_createColourCube00
static int tolua_Hax_Hax_GfxEngine_createColourCube00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createColourCube'", NULL);
#endif
  {
   self->createColourCube();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createColourCube'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createSphere of class  Hax::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GfxEngine_createSphere00
static int tolua_Hax_Hax_GfxEngine_createSphere00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GfxEngine* self = (Hax::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  const std::string strName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const float r = ((const float)  tolua_tonumber(tolua_S,3,0));
  const int nRings = ((const int)  tolua_tonumber(tolua_S,4,16));
  const int nSegments = ((const int)  tolua_tonumber(tolua_S,5,16));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createSphere'", NULL);
#endif
  {
   self->createSphere(strName,r,nRings,nSegments);
   tolua_pushcppstring(tolua_S,(const char*)strName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSphere'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_delete00
static int tolua_Hax_Hax_FxEngine_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_getSingleton00
static int tolua_Hax_Hax_FxEngine_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::FxEngine& tolua_ret = (Hax::FxEngine&)  Hax::FxEngine::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Hax::FxEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_getSingletonPtr00
static int tolua_Hax_Hax_FxEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::FxEngine* tolua_ret = (Hax::FxEngine*)  Hax::FxEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::FxEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setup of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_setup00
static int tolua_Hax_Hax_FxEngine_setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setup();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_update00
static int tolua_Hax_Hax_FxEngine_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  unsigned long lTimeElapsed = ((unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(lTimeElapsed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cleanup of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_cleanup00
static int tolua_Hax_Hax_FxEngine_cleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanup'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->cleanup();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadAllEffects of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_FxEngine_unloadAllEffects00
static int tolua_Hax_Hax_FxEngine_unloadAllEffects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadAllEffects'", NULL);
#endif
  {
   self->unloadAllEffects();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadAllEffects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Hax of class  Hax::FxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__FxEngine___Hax__EventListener__
static int tolua_get_Hax__FxEngine___Hax__EventListener__(lua_State* tolua_S)
{
  Hax::FxEngine* self = (Hax::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Hax'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Hax::EventListener*>(self), "Hax::EventListener");
#else
   tolua_pushusertype(tolua_S,(void*)((Hax::EventListener*)self), "Hax::EventListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::EventManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventManager_getSingletonPtr00
static int tolua_Hax_Hax_EventManager_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::EventManager* tolua_ret = (Hax::EventManager*)  Hax::EventManager::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::EventManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hook of class  Hax::EventManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventManager_hook00
static int tolua_Hax_Hax_EventManager_hook00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::EventManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Hax::Event",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::EventManager* self = (Hax::EventManager*)  tolua_tousertype(tolua_S,1,0);
  const Hax::Event* inEvt = ((const Hax::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hook'", NULL);
#endif
  {
   self->hook(*inEvt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hook'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::EventListener */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventListener_new00
static int tolua_Hax_Hax_EventListener_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::EventListener* tolua_ret = (Hax::EventListener*)  Mtolua_new((Hax::EventListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::EventListener");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::EventListener */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventListener_new00_local
static int tolua_Hax_Hax_EventListener_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::EventListener* tolua_ret = (Hax::EventListener*)  Mtolua_new((Hax::EventListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::EventListener");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::EventListener */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventListener_delete00
static int tolua_Hax_Hax_EventListener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::EventListener* self = (Hax::EventListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enqueue of class  Hax::EventListener */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_EventListener_enqueue00
static int tolua_Hax_Hax_EventListener_enqueue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::EventListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Hax::Event",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::EventListener* self = (Hax::EventListener*)  tolua_tousertype(tolua_S,1,0);
  Hax::Event* inEvt = ((Hax::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enqueue'", NULL);
#endif
  {
   self->enqueue(*inEvt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enqueue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeState of class  Hax::GameManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameManager_changeState00
static int tolua_Hax_Hax_GameManager_changeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GameManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GameManager* self = (Hax::GameManager*)  tolua_tousertype(tolua_S,1,0);
  Hax::GameState* inState = ((Hax::GameState*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'", NULL);
#endif
  {
   self->changeState(inState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Hax::GameManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameManager_getSingleton00
static int tolua_Hax_Hax_GameManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::GameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::GameManager& tolua_ret = (Hax::GameManager&)  Hax::GameManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Hax::GameManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: requestShutdown of class  Hax::GameManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameManager_requestShutdown00
static int tolua_Hax_Hax_GameManager_requestShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GameManager* self = (Hax::GameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'", NULL);
#endif
  {
   self->requestShutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestShutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeState of class  Hax::GameState */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameState_changeState00
static int tolua_Hax_Hax_GameState_changeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GameState",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Hax::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GameState* self = (Hax::GameState*)  tolua_tousertype(tolua_S,1,0);
  Hax::GameState* state = ((Hax::GameState*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'", NULL);
#endif
  {
   self->changeState(state);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: requestShutdown of class  Hax::GameState */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameState_requestShutdown00
static int tolua_Hax_Hax_GameState_requestShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GameState* self = (Hax::GameState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'", NULL);
#endif
  {
   self->requestShutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestShutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCurrentState of class  Hax::GameState */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_GameState_isCurrentState00
static int tolua_Hax_Hax_GameState_isCurrentState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::GameState* self = (Hax::GameState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCurrentState'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCurrentState();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCurrentState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Hax::Intro */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Intro_getSingleton00
static int tolua_Hax_Hax_Intro_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Intro",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Intro& tolua_ret = (Hax::Intro&)  Hax::Intro::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Hax::Intro");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::Intro */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Intro_getSingletonPtr00
static int tolua_Hax_Hax_Intro_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::Intro",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::Intro* tolua_ret = (Hax::Intro*)  Hax::Intro::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::Intro");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getKeyboard of class  Hax::InputManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_InputManager_getKeyboard00
static int tolua_Hax_Hax_InputManager_getKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::InputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::InputManager* self = (Hax::InputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getKeyboard'", NULL);
#endif
  {
   OIS::Keyboard* tolua_ret = (OIS::Keyboard*)  self->getKeyboard();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OIS::Keyboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getKeyboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::InputManager */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_InputManager_getSingletonPtr00
static int tolua_Hax_Hax_InputManager_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::InputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::InputManager* tolua_ret = (Hax::InputManager*)  Hax::InputManager::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::InputManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Hax::ScriptEngine::luaLog */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_Log00
static int tolua_Hax_Hax_Log00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
   std::string inMsg = ((  std::string)  tolua_tocppstring(tolua_S,1,0));
  {
   Hax::ScriptEngine::luaLog(inMsg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Log'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::LuaExporter<std::list<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00
static int tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::LuaExporter<std::list<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::LuaExporter<std::list<Hax::Entity*> >* tolua_ret = (Hax::LuaExporter<std::list<Hax::Entity*> >*)  Mtolua_new((Hax::LuaExporter<std::list<Hax::Entity*> >)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::LuaExporter<std::list<Hax::Entity*> >");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::LuaExporter<std::list<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00_local
static int tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::LuaExporter<std::list<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::LuaExporter<std::list<Hax::Entity*> >* tolua_ret = (Hax::LuaExporter<std::list<Hax::Entity*> >*)  Mtolua_new((Hax::LuaExporter<std::list<Hax::Entity*> >)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::LuaExporter<std::list<Hax::Entity*> >");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::LuaExporter<std::list<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____delete00
static int tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::LuaExporter<std::list<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::LuaExporter<std::list<Hax::Entity*> >* self = (Hax::LuaExporter<std::list<Hax::Entity*> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __export of class  Hax::LuaExporter<std::list<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____export00
static int tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::LuaExporter<std::list<Hax::Entity*> >",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::LuaExporter<std::list<Hax::Entity*> >* self = (Hax::LuaExporter<std::list<Hax::Entity*> >*)  tolua_tousertype(tolua_S,1,0);
  std::list<Hax::Entity*> const* container = ((std::list<Hax::Entity*> const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'", NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hax::LuaExporter<std::vector<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00
static int tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::LuaExporter<std::vector<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::LuaExporter<std::vector<Hax::Entity*> >* tolua_ret = (Hax::LuaExporter<std::vector<Hax::Entity*> >*)  Mtolua_new((Hax::LuaExporter<std::vector<Hax::Entity*> >)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::LuaExporter<std::vector<Hax::Entity*> >");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hax::LuaExporter<std::vector<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00_local
static int tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::LuaExporter<std::vector<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::LuaExporter<std::vector<Hax::Entity*> >* tolua_ret = (Hax::LuaExporter<std::vector<Hax::Entity*> >*)  Mtolua_new((Hax::LuaExporter<std::vector<Hax::Entity*> >)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::LuaExporter<std::vector<Hax::Entity*> >");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hax::LuaExporter<std::vector<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____delete00
static int tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::LuaExporter<std::vector<Hax::Entity*> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::LuaExporter<std::vector<Hax::Entity*> >* self = (Hax::LuaExporter<std::vector<Hax::Entity*> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __export of class  Hax::LuaExporter<std::vector<Hax::Entity*> > */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____export00
static int tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::LuaExporter<std::vector<Hax::Entity*> >",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::LuaExporter<std::vector<Hax::Entity*> >* self = (Hax::LuaExporter<std::vector<Hax::Entity*> >*)  tolua_tousertype(tolua_S,1,0);
  std::vector<Hax::Entity*> const* container = ((std::vector<Hax::Entity*> const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'", NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_ScriptEngine_getSingletonPtr00
static int tolua_Hax_Hax_ScriptEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::ScriptEngine* tolua_ret = (Hax::ScriptEngine*)  Hax::ScriptEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::ScriptEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScriptPathPrefix of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_ScriptEngine_getScriptPathPrefix00
static int tolua_Hax_Hax_ScriptEngine_getScriptPathPrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::ScriptEngine* self = (const Hax::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScriptPathPrefix'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getScriptPathPrefix();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScriptPathPrefix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getModulePathPrefix of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_ScriptEngine_getModulePathPrefix00
static int tolua_Hax_Hax_ScriptEngine_getModulePathPrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Hax::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Hax::ScriptEngine* self = (const Hax::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getModulePathPrefix'", NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->getModulePathPrefix();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getModulePathPrefix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: callMeAfter of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_ScriptEngine_callMeAfter00
static int tolua_Hax_Hax_ScriptEngine_callMeAfter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::ScriptEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::ScriptEngine* self = (Hax::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
  int inSeconds = ((int)  tolua_tonumber(tolua_S,2,0));
   std::string inFunc = ((  std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'callMeAfter'", NULL);
#endif
  {
   self->callMeAfter(inSeconds,inFunc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'callMeAfter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _reportAccepted of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_ScriptEngine_reportAccepted00
static int tolua_Hax_Hax_ScriptEngine_reportAccepted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::ScriptEngine* self = (Hax::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_reportAccepted'", NULL);
#endif
  {
   self->_reportAccepted();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reportAccepted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Hax of class  Hax::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_get_Hax__ScriptEngine___Hax__EventListener__
static int tolua_get_Hax__ScriptEngine___Hax__EventListener__(lua_State* tolua_S)
{
  Hax::ScriptEngine* self = (Hax::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Hax'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Hax::EventListener*>(self), "Hax::EventListener");
#else
   tolua_pushusertype(tolua_S,(void*)((Hax::EventListener*)self), "Hax::EventListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Hax::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_UIEngine_getSingletonPtr00
static int tolua_Hax_Hax_UIEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hax::UIEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hax::UIEngine* tolua_ret = (Hax::UIEngine*)  Hax::UIEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hax::UIEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMargin of class  Hax::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_UIEngine_setMargin00
static int tolua_Hax_Hax_UIEngine_setMargin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::UIEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CEGUI::UBox",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::UIEngine* self = (Hax::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* tolua_var_14 = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  CEGUI::UBox tolua_var_15 = *((CEGUI::UBox*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMargin'", NULL);
#endif
  {
   self->setMargin(tolua_var_14,tolua_var_15);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMargin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connectAnimation of class  Hax::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Hax_Hax_UIEngine_connectAnimation00
static int tolua_Hax_Hax_UIEngine_connectAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hax::UIEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hax::UIEngine* self = (Hax::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* tolua_var_16 = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
   std::string tolua_var_17 = ((  std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connectAnimation'", NULL);
#endif
  {
   self->connectAnimation(tolua_var_16,tolua_var_17);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connectAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Hax_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Renderable","Hax::Renderable","",tolua_collect_Hax__Renderable);
   #else
   tolua_cclass(tolua_S,"Renderable","Hax::Renderable","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Renderable");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Renderable_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Renderable_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Renderable_new00_local);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Renderable_new01);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Renderable_new01_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Renderable_new01_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_Renderable_delete00);
    tolua_function(tolua_S,"attachSceneNode",tolua_Hax_Hax_Renderable_attachSceneNode00);
    tolua_function(tolua_S,"getSceneNode",tolua_Hax_Hax_Renderable_getSceneNode00);
    tolua_function(tolua_S,"attachSceneObject",tolua_Hax_Hax_Renderable_attachSceneObject00);
    tolua_function(tolua_S,"getSceneObject",tolua_Hax_Hax_Renderable_getSceneObject00);
    tolua_function(tolua_S,"attachExtension",tolua_Hax_Hax_Renderable_attachExtension00);
    tolua_function(tolua_S,"getMesh",tolua_Hax_Hax_Renderable_getMesh00);
    tolua_function(tolua_S,"getMaterial",tolua_Hax_Hax_Renderable_getMaterial00);
    tolua_function(tolua_S,"setMaterial",tolua_Hax_Hax_Renderable_setMaterial00);
    tolua_function(tolua_S,"setMesh",tolua_Hax_Hax_Renderable_setMesh00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Animable","Hax::Animable","",tolua_collect_Hax__Animable);
   #else
   tolua_cclass(tolua_S,"Animable","Hax::Animable","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Animable");
    tolua_constant(tolua_S,"ANIM_NONE",Hax::Animable::ANIM_NONE);
    tolua_constant(tolua_S,"ANIM_LIVE",Hax::Animable::ANIM_LIVE);
    tolua_constant(tolua_S,"ANIM_IDLE",Hax::Animable::ANIM_IDLE);
    tolua_constant(tolua_S,"ANIM_WALK",Hax::Animable::ANIM_WALK);
    tolua_constant(tolua_S,"ANIM_RUN",Hax::Animable::ANIM_RUN);
    tolua_constant(tolua_S,"ANIM_ATTACK",Hax::Animable::ANIM_ATTACK);
    tolua_constant(tolua_S,"ANIM_HIT",Hax::Animable::ANIM_HIT);
    tolua_constant(tolua_S,"ANIM_REST",Hax::Animable::ANIM_REST);
    tolua_constant(tolua_S,"ANIM_GETUP",Hax::Animable::ANIM_GETUP);
    tolua_constant(tolua_S,"ANIM_DIE",Hax::Animable::ANIM_DIE);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Animable_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Animable_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Animable_new00_local);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Animable_new01);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Animable_new01_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Animable_new01_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_Animable_delete00);
    tolua_function(tolua_S,"registerAnimationState",tolua_Hax_Hax_Animable_registerAnimationState00);
    tolua_function(tolua_S,"step",tolua_Hax_Hax_Animable_step00);
    tolua_function(tolua_S,"animateLive",tolua_Hax_Hax_Animable_animateLive00);
    tolua_function(tolua_S,"animateDie",tolua_Hax_Hax_Animable_animateDie00);
    tolua_function(tolua_S,"animateIdle",tolua_Hax_Hax_Animable_animateIdle00);
    tolua_function(tolua_S,"animateWalk",tolua_Hax_Hax_Animable_animateWalk00);
    tolua_function(tolua_S,"animateRun",tolua_Hax_Hax_Animable_animateRun00);
    tolua_function(tolua_S,"animateAttack",tolua_Hax_Hax_Animable_animateAttack00);
    tolua_function(tolua_S,"animateHit",tolua_Hax_Hax_Animable_animateHit00);
    tolua_function(tolua_S,"animateRest",tolua_Hax_Hax_Animable_animateRest00);
    tolua_function(tolua_S,"animateGetUp",tolua_Hax_Hax_Animable_animateGetUp00);
    tolua_function(tolua_S,"_animate",tolua_Hax_Hax_Animable__animate00);
    tolua_function(tolua_S,"setAnimFadeSpeed",tolua_Hax_Hax_Animable_setAnimFadeSpeed00);
    tolua_function(tolua_S,"getAnimFadeSpeed",tolua_Hax_Hax_Animable_getAnimFadeSpeed00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Entity","Hax::Entity","",tolua_collect_Hax__Entity);
   #else
   tolua_cclass(tolua_S,"Entity","Hax::Entity","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Entity");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Entity_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Entity_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Entity_new00_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_Entity_delete00);
    tolua_function(tolua_S,"setup",tolua_Hax_Hax_Entity_setup00);
    tolua_function(tolua_S,"live",tolua_Hax_Hax_Entity_live00);
    tolua_function(tolua_S,"die",tolua_Hax_Hax_Entity_die00);
    tolua_function(tolua_S,"getText",tolua_Hax_Hax_Entity_getText00);
    tolua_function(tolua_S,"setText",tolua_Hax_Hax_Entity_setText00);
    tolua_function(tolua_S,"updateTextOverlay",tolua_Hax_Hax_Entity_updateTextOverlay00);
    tolua_function(tolua_S,"hide",tolua_Hax_Hax_Entity_hide00);
    tolua_function(tolua_S,"show",tolua_Hax_Hax_Entity_show00);
    tolua_function(tolua_S,"__setUID",tolua_Hax_Hax_Entity___setUID00);
    tolua_function(tolua_S,"getUID",tolua_Hax_Hax_Entity_getUID00);
    tolua_function(tolua_S,"__setName",tolua_Hax_Hax_Entity___setName00);
    tolua_function(tolua_S,"getName",tolua_Hax_Hax_Entity_getName00);
    tolua_function(tolua_S,"registerAnimationState",tolua_Hax_Hax_Entity_registerAnimationState00);
    tolua_function(tolua_S,"animateLive",tolua_Hax_Hax_Entity_animateLive00);
    tolua_function(tolua_S,"animateDie",tolua_Hax_Hax_Entity_animateDie00);
    tolua_function(tolua_S,"animateIdle",tolua_Hax_Hax_Entity_animateIdle00);
    tolua_function(tolua_S,"animateWalk",tolua_Hax_Hax_Entity_animateWalk00);
    tolua_function(tolua_S,"animateRun",tolua_Hax_Hax_Entity_animateRun00);
    tolua_function(tolua_S,"animateAttack",tolua_Hax_Hax_Entity_animateAttack00);
    tolua_function(tolua_S,"animateHit",tolua_Hax_Hax_Entity_animateHit00);
    tolua_function(tolua_S,"animateRest",tolua_Hax_Hax_Entity_animateRest00);
    tolua_function(tolua_S,"animateGetUp",tolua_Hax_Hax_Entity_animateGetUp00);
    tolua_function(tolua_S,"_animate",tolua_Hax_Hax_Entity__animate00);
    tolua_function(tolua_S,"setAnimFadeSpeed",tolua_Hax_Hax_Entity_setAnimFadeSpeed00);
    tolua_function(tolua_S,"getAnimFadeSpeed",tolua_Hax_Hax_Entity_getAnimFadeSpeed00);
    tolua_function(tolua_S,"attachSceneNode",tolua_Hax_Hax_Entity_attachSceneNode00);
    tolua_function(tolua_S,"getSceneNode",tolua_Hax_Hax_Entity_getSceneNode00);
    tolua_function(tolua_S,"attachSceneObject",tolua_Hax_Hax_Entity_attachSceneObject00);
    tolua_function(tolua_S,"getSceneObject",tolua_Hax_Hax_Entity_getSceneObject00);
    tolua_function(tolua_S,"attachExtension",tolua_Hax_Hax_Entity_attachExtension00);
    tolua_function(tolua_S,"getMesh",tolua_Hax_Hax_Entity_getMesh00);
    tolua_function(tolua_S,"getMaterial",tolua_Hax_Hax_Entity_getMaterial00);
    tolua_function(tolua_S,"setMaterial",tolua_Hax_Hax_Entity_setMaterial00);
    tolua_function(tolua_S,"setMesh",tolua_Hax_Hax_Entity_setMesh00);
    tolua_function(tolua_S,"move",tolua_Hax_Hax_Entity_move00);
    tolua_function(tolua_S,"isMoving",tolua_Hax_Hax_Entity_isMoving00);
    tolua_function(tolua_S,"setWaypoints",tolua_Hax_Hax_Entity_setWaypoints00);
    tolua_function(tolua_S,"setWalkSpeed",tolua_Hax_Hax_Entity_setWalkSpeed00);
    tolua_function(tolua_S,"getWalkSpeed",tolua_Hax_Hax_Entity_getWalkSpeed00);
    tolua_function(tolua_S,"setDefaultWalkSpeed",tolua_Hax_Hax_Entity_setDefaultWalkSpeed00);
    tolua_function(tolua_S,"getDefaultWalkSpeed",tolua_Hax_Hax_Entity_getDefaultWalkSpeed00);
    tolua_function(tolua_S,"setRotationFactor",tolua_Hax_Hax_Entity_setRotationFactor00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"Unit","Hax::Unit","",NULL);
   tolua_beginmodule(tolua_S,"Unit");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Mobile","Hax::Mobile","",tolua_collect_Hax__Mobile);
   #else
   tolua_cclass(tolua_S,"Mobile","Hax::Mobile","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Mobile");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Mobile_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Mobile_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Mobile_new00_local);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Mobile_new01);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Mobile_new01_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Mobile_new01_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_Mobile_delete00);
    tolua_function(tolua_S,"move",tolua_Hax_Hax_Mobile_move00);
    tolua_function(tolua_S,"step",tolua_Hax_Hax_Mobile_step00);
    tolua_function(tolua_S,"isMoving",tolua_Hax_Hax_Mobile_isMoving00);
    tolua_function(tolua_S,"setWaypoints",tolua_Hax_Hax_Mobile_setWaypoints00);
    tolua_function(tolua_S,"setWalkSpeed",tolua_Hax_Hax_Mobile_setWalkSpeed00);
    tolua_function(tolua_S,"getWalkSpeed",tolua_Hax_Hax_Mobile_getWalkSpeed00);
    tolua_function(tolua_S,"setDefaultWalkSpeed",tolua_Hax_Hax_Mobile_setDefaultWalkSpeed00);
    tolua_function(tolua_S,"getDefaultWalkSpeed",tolua_Hax_Hax_Mobile_getDefaultWalkSpeed00);
    tolua_function(tolua_S,"rotateToEnemy",tolua_Hax_Hax_Mobile_rotateToEnemy00);
    tolua_function(tolua_S,"rotateTo",tolua_Hax_Hax_Mobile_rotateTo00);
    tolua_function(tolua_S,"setRotationFactor",tolua_Hax_Hax_Mobile_setRotationFactor00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"Engine","Hax::Engine","",NULL);
   tolua_beginmodule(tolua_S,"Engine");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Ogre",0);
  tolua_beginmodule(tolua_S,"Ogre");
   tolua_cclass(tolua_S,"Vector3","Ogre::Vector3","",NULL);
   tolua_beginmodule(tolua_S,"Vector3");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SceneManager","Ogre::SceneManager","",NULL);
   tolua_beginmodule(tolua_S,"SceneManager");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SceneNode","Ogre::SceneNode","",NULL);
   tolua_beginmodule(tolua_S,"SceneNode");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Event","Hax::Event","",tolua_collect_Hax__Event);
   #else
   tolua_cclass(tolua_S,"Event","Hax::Event","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Event");
    tolua_constant(tolua_S,"HeaderLength",Hax::Event::HeaderLength);
    tolua_constant(tolua_S,"FooterLength",Hax::Event::FooterLength);
    tolua_constant(tolua_S,"NoFormat",Hax::Event::NoFormat);
    tolua_constant(tolua_S,"Compressed",Hax::Event::Compressed);
    tolua_constant(tolua_S,"IsLocal",Hax::Event::IsLocal);
    tolua_constant(tolua_S,"Broadcast",Hax::Event::Broadcast);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Event_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Event_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Event_new00_local);
    tolua_function(tolua_S,"new",tolua_Hax_Hax_Event_new01);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_Event_new01_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_Event_new01_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_Event_delete00);
    tolua_function(tolua_S,"getProperty",tolua_Hax_Hax_Event_getProperty00);
    tolua_function(tolua_S,"setProperty",tolua_Hax_Hax_Event_setProperty00);
    tolua_function(tolua_S,"hasProperty",tolua_Hax_Hax_Event_hasProperty00);
    tolua_function(tolua_S,"dump",tolua_Hax_Hax_Event_dump00);
    tolua_function(tolua_S,"dump",tolua_Hax_Hax_Event_dump01);
    tolua_variable(tolua_S,"UID",tolua_get_Hax__Event_unsigned_UID,tolua_set_Hax__Event_unsigned_UID);
    tolua_variable(tolua_S,"Options",tolua_get_Hax__Event_unsigned_Options,tolua_set_Hax__Event_unsigned_Options);
    tolua_variable(tolua_S,"Feedback",tolua_get_Hax__Event_unsigned_Feedback,tolua_set_Hax__Event_unsigned_Feedback);
    tolua_variable(tolua_S,"Properties",tolua_get_Hax__Event_Properties,tolua_set_Hax__Event_Properties);
    tolua_variable(tolua_S,"Footer",tolua_get_Hax__Event_Footer,NULL);
    tolua_variable(tolua_S,"Any",tolua_get_Hax__Event_Any,tolua_set_Hax__Event_Any);
    tolua_function(tolua_S,"UIDToString",tolua_Hax_Hax_Event_UIDToString00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GfxEngine","Hax::GfxEngine","",NULL);
   tolua_beginmodule(tolua_S,"GfxEngine");
    tolua_constant(tolua_S,"TERRAIN_MASK",Hax::GfxEngine::TERRAIN_MASK);
    tolua_constant(tolua_S,"ENTITY_MASK",Hax::GfxEngine::ENTITY_MASK);
    tolua_constant(tolua_S,"GENERIC",Hax::GfxEngine::GENERIC);
    tolua_constant(tolua_S,"POLY",Hax::GfxEngine::POLY);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_GfxEngine_getSingletonPtr00);
    tolua_variable(tolua_S,"mMTOFontColor",tolua_get_Hax__GfxEngine_mMTOFontColor,tolua_set_Hax__GfxEngine_mMTOFontColor);
    tolua_variable(tolua_S,"mMTOFontName",tolua_get_Hax__GfxEngine_mMTOFontName,tolua_set_Hax__GfxEngine_mMTOFontName);
    tolua_variable(tolua_S,"mMTOFontSize",tolua_get_Hax__GfxEngine_mMTOFontSize,tolua_set_Hax__GfxEngine_mMTOFontSize);
    tolua_variable(tolua_S,"mMTOMaterialName",tolua_get_Hax__GfxEngine_mMTOMaterialName,tolua_set_Hax__GfxEngine_mMTOMaterialName);
    tolua_function(tolua_S,"disableMouseCaptureOverUIElement",tolua_Hax_Hax_GfxEngine_disableMouseCaptureOverUIElement00);
    tolua_function(tolua_S,"enableMouseCaptureOverUIElement",tolua_Hax_Hax_GfxEngine_enableMouseCaptureOverUIElement00);
    tolua_function(tolua_S,"setCamera",tolua_Hax_Hax_GfxEngine_setCamera00);
    tolua_function(tolua_S,"switchMousePickingMode",tolua_Hax_Hax_GfxEngine_switchMousePickingMode00);
    tolua_function(tolua_S,"getMousePickingMode",tolua_Hax_Hax_GfxEngine_getMousePickingMode00);
    tolua_function(tolua_S,"attachToScene",tolua_Hax_Hax_GfxEngine_attachToScene00);
    tolua_function(tolua_S,"detachFromScene",tolua_Hax_Hax_GfxEngine_detachFromScene00);
    tolua_function(tolua_S,"setupMovableTextOverlays",tolua_Hax_Hax_GfxEngine_setupMovableTextOverlays00);
    tolua_function(tolua_S,"getCameraMan",tolua_Hax_Hax_GfxEngine_getCameraMan00);
    tolua_function(tolua_S,"getCamera",tolua_Hax_Hax_GfxEngine_getCamera00);
    tolua_function(tolua_S,"getRoot",tolua_Hax_Hax_GfxEngine_getRoot00);
    tolua_function(tolua_S,"getSceneMgr",tolua_Hax_Hax_GfxEngine_getSceneMgr00);
    tolua_function(tolua_S,"getWindow",tolua_Hax_Hax_GfxEngine_getWindow00);
    tolua_function(tolua_S,"getViewport",tolua_Hax_Hax_GfxEngine_getViewport00);
    tolua_function(tolua_S,"getSelected",tolua_Hax_Hax_GfxEngine_getSelected00);
    tolua_function(tolua_S,"updateMe",tolua_Hax_Hax_GfxEngine_updateMe00);
    tolua_function(tolua_S,"stopUpdatingMe",tolua_Hax_Hax_GfxEngine_stopUpdatingMe00);
    tolua_function(tolua_S,"enableCompositorEffect",tolua_Hax_Hax_GfxEngine_enableCompositorEffect00);
    tolua_function(tolua_S,"getScreenCoords",tolua_Hax_Hax_GfxEngine_getScreenCoords00);
    tolua_function(tolua_S,"setYawPitchDist",tolua_Hax_Hax_GfxEngine_setYawPitchDist00);
    tolua_function(tolua_S,"trackNode",tolua_Hax_Hax_GfxEngine_trackNode00);
    tolua_function(tolua_S,"_setUserAny",tolua_Hax_Hax_GfxEngine__setUserAny00);
    tolua_function(tolua_S,"createColourCube",tolua_Hax_Hax_GfxEngine_createColourCube00);
    tolua_function(tolua_S,"createSphere",tolua_Hax_Hax_GfxEngine_createSphere00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"FxEngine","Hax::FxEngine","Hax::Engine",tolua_collect_Hax__FxEngine);
   #else
   tolua_cclass(tolua_S,"FxEngine","Hax::FxEngine","Hax::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"FxEngine");
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_FxEngine_delete00);
    tolua_function(tolua_S,"getSingleton",tolua_Hax_Hax_FxEngine_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_FxEngine_getSingletonPtr00);
    tolua_function(tolua_S,"setup",tolua_Hax_Hax_FxEngine_setup00);
    tolua_function(tolua_S,"update",tolua_Hax_Hax_FxEngine_update00);
    tolua_function(tolua_S,"cleanup",tolua_Hax_Hax_FxEngine_cleanup00);
    tolua_function(tolua_S,"unloadAllEffects",tolua_Hax_Hax_FxEngine_unloadAllEffects00);
    tolua_variable(tolua_S,"__Hax__EventListener__",tolua_get_Hax__FxEngine___Hax__EventListener__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_module(tolua_S,"EventUID",0);
   tolua_beginmodule(tolua_S,"EventUID");
    tolua_constant(tolua_S,"Unassigned",Hax::EventUID::Unassigned);
    tolua_constant(tolua_S,"EntitySelected",Hax::EventUID::EntitySelected);
    tolua_constant(tolua_S,"EntityDeselected",Hax::EventUID::EntityDeselected);
    tolua_constant(tolua_S,"SanityCheck",Hax::EventUID::SanityCheck);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"EventFeedback",0);
   tolua_beginmodule(tolua_S,"EventFeedback");
    tolua_constant(tolua_S,"Unassigned",Hax::EventFeedback::Unassigned);
    tolua_constant(tolua_S,"Ok",Hax::EventFeedback::Ok);
    tolua_constant(tolua_S,"Error",Hax::EventFeedback::Error);
    tolua_constant(tolua_S,"InvalidRequest",Hax::EventFeedback::InvalidRequest);
    tolua_constant(tolua_S,"SanityCheck",Hax::EventFeedback::SanityCheck);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"EventManager","Hax::EventManager","",NULL);
   tolua_beginmodule(tolua_S,"EventManager");
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_EventManager_getSingletonPtr00);
    tolua_function(tolua_S,"hook",tolua_Hax_Hax_EventManager_hook00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"EventListener","Hax::EventListener","",tolua_collect_Hax__EventListener);
   #else
   tolua_cclass(tolua_S,"EventListener","Hax::EventListener","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"EventListener");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_EventListener_new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_EventListener_new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_EventListener_new00_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_EventListener_delete00);
    tolua_function(tolua_S,"enqueue",tolua_Hax_Hax_EventListener_enqueue00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"GameManager","Hax::GameManager","",NULL);
   tolua_beginmodule(tolua_S,"GameManager");
    tolua_function(tolua_S,"changeState",tolua_Hax_Hax_GameManager_changeState00);
    tolua_function(tolua_S,"getSingleton",tolua_Hax_Hax_GameManager_getSingleton00);
    tolua_function(tolua_S,"requestShutdown",tolua_Hax_Hax_GameManager_requestShutdown00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"GameState","Hax::GameState","",NULL);
   tolua_beginmodule(tolua_S,"GameState");
    tolua_constant(tolua_S,"Intro",Hax::GameState::Intro);
    tolua_function(tolua_S,"changeState",tolua_Hax_Hax_GameState_changeState00);
    tolua_function(tolua_S,"requestShutdown",tolua_Hax_Hax_GameState_requestShutdown00);
    tolua_function(tolua_S,"isCurrentState",tolua_Hax_Hax_GameState_isCurrentState00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"Intro","Hax::Intro","Hax::GameState",NULL);
   tolua_beginmodule(tolua_S,"Intro");
    tolua_function(tolua_S,"getSingleton",tolua_Hax_Hax_Intro_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_Intro_getSingletonPtr00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"InputManager","Hax::InputManager","",NULL);
   tolua_beginmodule(tolua_S,"InputManager");
    tolua_function(tolua_S,"getKeyboard",tolua_Hax_Hax_InputManager_getKeyboard00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_InputManager_getSingletonPtr00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_function(tolua_S,"Log",tolua_Hax_Hax_Log00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"LuaExporter_std__list_Hax__Entity____","Hax::LuaExporter<std::list<Hax::Entity*> >","",tolua_collect_Hax__LuaExporter_std__list_Hax__Entity____);
   #else
   tolua_cclass(tolua_S,"LuaExporter_std__list_Hax__Entity____","Hax::LuaExporter<std::list<Hax::Entity*> >","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"LuaExporter_std__list_Hax__Entity____");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____new00_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____delete00);
    tolua_function(tolua_S,"export",tolua_Hax_Hax_LuaExporter_std__list_Hax__Entity_____export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"LuaExporter_std__vector_Hax__Entity____","Hax::LuaExporter<std::vector<Hax::Entity*> >","",tolua_collect_Hax__LuaExporter_std__vector_Hax__Entity____);
   #else
   tolua_cclass(tolua_S,"LuaExporter_std__vector_Hax__Entity____","Hax::LuaExporter<std::vector<Hax::Entity*> >","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"LuaExporter_std__vector_Hax__Entity____");
    tolua_function(tolua_S,"new",tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00);
    tolua_function(tolua_S,"new_local",tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00_local);
    tolua_function(tolua_S,".call",tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____new00_local);
    tolua_function(tolua_S,"delete",tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____delete00);
    tolua_function(tolua_S,"export",tolua_Hax_Hax_LuaExporter_std__vector_Hax__Entity_____export00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"ScriptEngine","Hax::ScriptEngine","Hax::Engine",NULL);
   tolua_beginmodule(tolua_S,"ScriptEngine");
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_ScriptEngine_getSingletonPtr00);
    tolua_function(tolua_S,"getScriptPathPrefix",tolua_Hax_Hax_ScriptEngine_getScriptPathPrefix00);
    tolua_function(tolua_S,"getModulePathPrefix",tolua_Hax_Hax_ScriptEngine_getModulePathPrefix00);
    tolua_function(tolua_S,"callMeAfter",tolua_Hax_Hax_ScriptEngine_callMeAfter00);
    tolua_function(tolua_S,"reportAccepted",tolua_Hax_Hax_ScriptEngine_reportAccepted00);
    tolua_variable(tolua_S,"__Hax__EventListener__",tolua_get_Hax__ScriptEngine___Hax__EventListener__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"CEGUI",0);
  tolua_beginmodule(tolua_S,"CEGUI");
   tolua_cclass(tolua_S,"Window","CEGUI::Window","",NULL);
   tolua_beginmodule(tolua_S,"Window");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"UBox","CEGUI::UBox","",NULL);
   tolua_beginmodule(tolua_S,"UBox");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Hax",0);
  tolua_beginmodule(tolua_S,"Hax");
   tolua_cclass(tolua_S,"UIEngine","Hax::UIEngine","",NULL);
   tolua_beginmodule(tolua_S,"UIEngine");
    tolua_function(tolua_S,"getSingletonPtr",tolua_Hax_Hax_UIEngine_getSingletonPtr00);
    tolua_function(tolua_S,"setMargin",tolua_Hax_Hax_UIEngine_setMargin00);
    tolua_function(tolua_S,"connectAnimation",tolua_Hax_Hax_UIEngine_connectAnimation00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Hax (lua_State* tolua_S) {
 return tolua_Hax_open(tolua_S);
};
#endif

