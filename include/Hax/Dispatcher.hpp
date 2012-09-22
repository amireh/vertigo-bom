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

#ifndef H_HAX_DISPATCHER_H
#define H_HAX_DISPATCHER_H

#include "Hax/Event.hpp"

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <exception>
#include <stdexcept>
#include <map>
#include <deque>

using boost::asio::ip::tcp;
namespace Hax {

  class Dispatcher {
    public:
      //typedef boost::function<void(const message&)> msg_handler_t;
      typedef boost::function<void(const Event&)> evt_handler_t;

      dispatcher(boost::asio::io_service&);
      ~dispatcher();

      template <typename T>
      void bind(unsigned char evt, T* inT, void (T::*handler)(const Event&)) {
        // register message if it isn't already
        evt_handlers_t::iterator binder = evt_handlers_.find(evt);
        if (binder == evt_handlers_.end())
        {
          std::vector<evt_handler_t> handlers;
          binder = evt_handlers_.insert(make_pair(evt, handlers)).first;
        }

        binder->second.push_back( boost::bind(handler, inT, _1) );
      }

      void unbind(unsigned char evt);

      // delivers a local copy of the message to bound handlers
      // @note: the message might not be dispatched immediately, as it will be
      // queued internally and later on dispatched through the strand object
      // unless the immediate flag is set
      //void deliver(const message&);
      void deliver(const Event&, bool immediate=false);

      void reset();

    private:
      void dispatch();

      boost::asio::strand strand_;

      typedef std::map< unsigned char , std::vector<evt_handler_t> > evt_handlers_t;
      evt_handlers_t evt_handlers_;

      std::deque<Event> events;
  };

}
}
#endif
