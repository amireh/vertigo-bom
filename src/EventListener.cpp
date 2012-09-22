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

#include "Hax/EventListener.hpp"
#include "Hax/EventManager.hpp"

namespace Hax {

  int EventListener::gUIDGenerator = 0;

	EventListener::EventListener() {
    mUID = ++gUIDGenerator;
	}

	EventListener::~EventListener() {
    mEvtHandlers.clear();
    mTracker.clear();
    //while (!mEvents.empty())
    //  mEvents.pop();
	}

	bool EventListener::processEvents() {
    if (mEvents.empty())
      return true;

    const Event& evt = mEvents.front();

    //~ std::cout << "processing an evt " << (int)evt.UID << ": " << Event::_uid_to_string(evt.UID) << "\n";
    // fill our tracker with the handlers listening to this event
    if (mEvtHandlers.find(evt.UID) == mEvtHandlers.end() &&
        mEvtHandlers.find(EventUID::Unassigned) == mEvtHandlers.end()) {
      std::cout << "ERROR!! found no handlers!!\n";
      mEvents.pop();
      return true; // there r no handlers
    }

    // if the tracker isn't empty, it means one of the handlers wasn't done with
    // an earlier event
    if (mTracker.empty()) {
      evt_handlers_t::iterator finder = mEvtHandlers.find(evt.UID);
      if (finder != mEvtHandlers.end()) {
        std::vector<evt_handler_t>* handlers = &(finder->second);
        std::vector<evt_handler_t>::const_iterator handler;
        for (handler = handlers->begin();
             handler != handlers->end();
             ++handler)
          mTracker.push_back(*handler);

      }

      std::vector<evt_handler_t>::const_iterator handler;
      // handlers listening to all events
      for (handler = mEvtHandlers.find(EventUID::Unassigned)->second.begin();
           handler != mEvtHandlers.find(EventUID::Unassigned)->second.end();
           ++handler)
        mTracker.push_back((*handler));
    }

    // now call all the handlers, and remove the event only if they're all done
    bool done = true;
    for (tracker_t::iterator handler = mTracker.begin(); handler != mTracker.end(); ++handler)
      if ( (*handler)(evt) ) {
        tracker_t::iterator tmp = handler;
        ++handler;
        mTracker.erase(tmp);
      } else
        done = false;

    if (done)
      mEvents.pop();

    return done;
  }

  void EventListener::do_subscribe(unsigned char evt) {
    EventManager::getSingleton().subscribe(evt, this);
  }
  void EventListener::do_unsubscribe(unsigned char evt) {
    EventManager::getSingleton().unsubscribe(evt, this);
  }

  void EventListener::unbindAll()
  {
    for (evt_handlers_t::iterator pair = mEvtHandlers.begin();
      pair != mEvtHandlers.end();
      ++pair)
    {
      EventManager::getSingleton().unsubscribe(pair->first, this);
    }
    mEvtHandlers.clear();
  }

}
