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

#ifndef H_HAX_LUA_EXPORTER_H
#define H_HAX_LUA_EXPORTER_H

#include "Hax/ScriptEngine.hpp"
#include "Hax/Entity.hpp"

#include <vector>
#include <list>

namespace Hax {

  template <typename T>
  class LuaExporter {
    public:
      LuaExporter() { }
      virtual ~LuaExporter() {}

      inline virtual void
      __export(T const& container, const char* data_type, const char* out_table)
      {
        lua_State *lua = ScriptEngine::getSingleton().getLuaState();

        lua_newtable(lua); // declare the empty table out_table

        typename T::const_iterator cursor;
        int count = 0;
        for (cursor = container.begin(); cursor != container.end(); ++cursor)
        {
          lua_pushinteger(lua, (++count));
          tolua_pushusertype(lua, (void*)(*cursor), data_type);
          lua_settable(lua, -3);
        }

        lua_setglobal(lua, out_table);
      }
  };
}

#endif
