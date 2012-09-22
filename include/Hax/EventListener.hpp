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

#ifndef H_HAX_EVENT_LISTENER_H
#define H_HAX_EVENT_LISTENER_H

#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "Hax/Utility.hpp"
#include "Event.hpp"

using std::map;
using std::vector;
using std::pair;
using std::list;
using std::queue;
namespace Hax
{
  /** @class EventListener "EventListener.h" "../include/EventListener.h"
   *
   *  @brief
   *  EventListener interfaces with EventManager for attaching events
   *	to handlers
   *
   *	Components interested in Events need to derive from this class.
   *	Using bind() children are able to register as many handlers
   *	as needed to a certain event.
   *
   *	@warning
   *	Modules subclassing EventListener MUST implement a VIRTUAL destructor!!!
   *
   *  @note
   *  Usage:
   *	You should never need to create or call an EventListener
   *  directly. Instead, derive from it and use bind()
   *
   *	Example:
   *
   *	@code
   *	class Foo : public EventListener {
   *		Foo();
   *		virtual ~Foo();
   *		bool bar(Event* inEvt);
   *	};
   *
   *	Foo::Foo() {
   *		bind<Foo>(EVT_SOMETHING, this, &Foo::bar);
   *	}
   *	\endcode
   *
   */
  class EventListener
  {
    public:
    typedef boost::function<bool(const Event&)> evt_handler_t;

    EventListener();
    virtual ~EventListener();

    bool processEvents();

    void enqueue(const Event& inEvt) {
      mEvents.push(inEvt);
    }

    void bind(unsigned char evt, evt_handler_t handler) {
      // register message if it isn't already
      evt_handlers_t::iterator binder = mEvtHandlers.find(evt);
      if (binder == mEvtHandlers.end())
      {
        std::vector<evt_handler_t> handlers;
        binder = mEvtHandlers.insert(make_pair(evt, handlers)).first;
      }

      binder->second.push_back( handler );
      do_subscribe(evt);
    }


    inline void
    unbind(unsigned char evt)
    {
      mEvtHandlers.erase(evt);
      do_unsubscribe(evt);
    };

    void unbindAll();

    int getUID() { return mUID; }

  protected:
    typedef std::map< unsigned char , std::vector<evt_handler_t> > evt_handlers_t;
    evt_handlers_t mEvtHandlers;

    typedef std::list<evt_handler_t> tracker_t;
    tracker_t mTracker;

    queue<Event> mEvents; // processing queue

    static int gUIDGenerator;
    int mUID;
  private:
    void do_subscribe(unsigned char);
    void do_unsubscribe(unsigned char);
  };
}
#endif // H_HAX_EVENT_LISTENER_H
