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

#ifndef H_HAX_CONFIGURATOR_H
#define H_HAX_CONFIGURATOR_H

#include "Hax/Hax.hpp"
#include "Hax/Logger.hpp"
#include "Hax/Configurable.hpp"

#include <map>

#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>

namespace Hax {

  /**
   * @class Configurator
   *
   * Parses a JSON configuration sheet and calls all subscribed Configurable objects
   * with their options.
   */
  class Configurator : public Logger {
  public:

    Configurator(string_t const& json_data);
    Configurator(std::ifstream& json_file_handle);

    virtual ~Configurator();
    Configurator(const Configurator&) = delete;
    Configurator& operator=(const Configurator&) = delete;

    static void init();

    /**
     * performs the actual parsing and configuration of subscribed instances
     */
    void run();

    /**
     * subscribed the given Configurable to its configuration context;
     * once that context is encountered in a configuration file, the object
     * will be passed the options to handle them
     *
     * @note
     * a context can be assigned at most 1 Configurable at any time,
     * but a Configurable can handle many contexts
     */
    static void subscribe(Configurable*, string_t const& context);

    int __onJsonMapStart();
    int __onJsonMapKey(const unsigned char*, size_t);
    int __onJsonMapVal(const unsigned char*, size_t);
    int __onJsonMapEnd();
    int __onJsonArrayStart();
    int __onJsonArrayEnd();

  private:

    /**
     * Is the JSON key a keyword reserved by the Configurator?
     *
     * Currently, only "include" is reserved.
     * */
    bool isReserved(const string_t& ctx);

    typedef std::map<string_t, Configurable*> subs_t;
    static subs_t mSubs;
    static bool fInit;

    string_t mData;

    string_t      mCurrKey;
    string_t      mCurrVal;
    string_t      mCurrCtx;
    Configurable  *mCurrSub;
    int           mDepth;

    enum {
      yajl_continue = 1, /** continue parsing */
      yajl_stop = 0 /** stop parsing */
    };

  };

} // namespace Hax

#endif // H_HAX_CONFIGURATOR_H
