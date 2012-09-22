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

#ifndef H_HAX_EVENT_MANAGER_H
#define H_HAX_EVENT_MANAGER_H

#include <string>
#include <map>
#include <queue>
#include <list>
#include <vector>
#include <utility>
#include <exception>

#include "Hax/Hax.hpp"
#include "Hax/Logger.hpp"
#include "Hax/Event.hpp"
#include "Hax/EventListener.hpp"

using std::make_pair;
using std::pair;
using std::map;
using std::vector;
using std::string;
using std::list;
namespace Hax
{
	class EventListener;
  /*!
  * @class EventManager "EventManager.h" "../include/EventManager.h"
  * @brief
  * Creates, releases, registers, and fires Events, the EventManager makes
  *	for the interface for subscribing EventListeners to be notified upon
  *	dispatching of certain Events. Also acts as a Factory for the creation
  *	of Events and releasing them.
  *
  * @remarks
  * All Event interaction should be done via this interface;
  * when a component would like to trigger an event, it first has to
  *	retrieve a newly created instance by calling createEvt(), then
  *	enqueue it by calling hook(). From there on, it's this module's job
  *	to make sure all EventListeners interested in this Event are notified
  *	when the Event's turn has come in the queue.
  */
  class EventManager : public Logger
  {
    typedef std::list<EventListener*> subscribers_t;
    typedef std::map< unsigned char, subscribers_t > subscription_t;

    public:
    virtual ~EventManager();

    //! Retrieve the singleton instance of this class
    static EventManager* getSingletonPtr();
    static EventManager& getSingleton();

    static void shutdown();

    void clear();

    /*! \brief Subscribes an EventListener method to an Event.
    *
    *	EventListeners subscribed to an Event evt will be notified
    *	whenever evt is dispatched. From there on, the Listeners
    *	will process the event by calling their registered handlers.
    *
    *  @param inIdEvt
    *		Unique identifier for the Event
    *  @param inListener
    *		Instance of the class that will handle this event
    *
    *  @return nothing
    *
    *  \note inListener MUST be a derivative of EventListener
    */
    void subscribe(unsigned char evt, EventListener* listener) {
      subscription_t::iterator binder = mSubscriptions.find(evt);
      if (binder == mSubscriptions.end())
      {
        subscribers_t handlers;
        binder = mSubscriptions.insert(make_pair(evt, handlers)).first;
      }

      binder->second.push_back( listener );
    }

    void unsubscribe(unsigned char evt, EventListener* inListener);

    /*! \brief Hooks an event onto the queue for processing.
     *
     *  Called by Event Listeners when an event is
     *  required to be fired.
     *
     *  \remarks
     *  When an Event is requested to be fired, ie hooked,
     *  EventManager determines the position for this Event
     *  in the queue using the Rank of the event;
     *
     *  If the Event is ranked MINOR_EVT, it is queued right
     *  after the last minor event in the queue.
     *  If the Event is ranked MAJOR_EVT, it is queued in the
     *  end; will be processed once all preceding events
     *  are done.
     *
     *  \note
     *  For more info about the Ranks of events, see
     *  the class reference for Event.
     */
    void hook(const Event& inEvt) {
      mEvents.push(Event(inEvt));
    }

    /*! \brief
    *	Processes Events in queue.
    *
    *  \note Should be updated in the game loop.
    */
    void update();

    protected:
    EventManager();
    EventManager(const EventManager& src);
    EventManager& operator=(const EventManager& rhs);
    static EventManager* mInstance;

    bool alreadySubscribed(EventListener* inListener);
    void detachListener(EventListener* inListener);

    //! container for direct subscribers
    subscription_t mSubscriptions;

    //! processing queue
    std::queue<Event> mEvents;

  };
} // Hax namespace

#endif // H_HAX_EVENT_MANAGER_H
