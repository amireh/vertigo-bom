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

#ifndef H_HAX_CONFIGURABLE_H
#define H_HAX_CONFIGURABLE_H

#include "Hax/Hax.hpp"
#include <array>

namespace Hax {

  class Configurator;

  /**
   * Configurables can register themselves with the dakapi server to be called
   * when the server configuration is parsed and processed.
   */
  class Configurable {
    public:

    /**
     * Default ctor, does not subscribe to any context: you must manually do that by calling
     * Configurable::subscribeContext()
     */
    explicit Configurable();

    /**
     * Subscribes this instance to every given context
     *
     * @note
     * You clearly don't have to call Configurator::subscribeContext() anymore
     * if you use this constructor.
     */
    explicit Configurable(std::vector<string_t> contexts);

    Configurable(const Configurable&);
    Configurable& operator=(const Configurable&);
    virtual ~Configurable();

    /** called whenever a cfg setting is encountered and parsed */
    virtual void setOption(string_t const& key, string_t const& value)=0;

    /**
     * Called when the config section is fully parsed, implementations
     * can do the actual configuration here if needed.
     *
     * @note
     * Sometimes this isn't really required as an implementation could configure
     * itself on-the-fly as setOption() is called, but others might have dependant
     * options.
     */
    inline virtual void configure() { }

    /** is this instance subscribed to the passed configuration context? */
    bool subscribedToContext(string_t const&);

    protected:
    friend class Configurator;

    /** this instance will be called whenever the given context is encountered */
    void subscribeContext(string_t const&);

    /**
     * when a Configurable is subscribed to more than 1 context,
     * this string can be used to determine the current context being parsed
     */
    string_t mCurrentCtx;

    std::vector<string_t> mContexts;

    void copy(const Configurable& src);
  };
}

#endif
