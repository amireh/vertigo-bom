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

#include "Hax/EventManager.hpp"
#include "Hax/EventListener.hpp"

namespace Hax {

	EventManager* EventManager::mInstance = NULL;

	EventManager::EventManager()
  : Logger("EventMgr")
  {
		mLog->noticeStream() << "up and running";
	}

	EventManager::~EventManager()
	{
		mLog->infoStream() << "shutting down";

		// clean up events
		while (!mEvents.empty())
			mEvents.pop();

		// clean up Listeners

		mInstance = 0;

		if (mLog)
			delete mLog;

		mLog = 0;
		//mIdCounter = 0;
	}

	EventManager* EventManager::getSingletonPtr() {
		return mInstance = (!mInstance) ? new EventManager() : mInstance;
	}

	EventManager& EventManager::getSingleton() {
		return *getSingletonPtr();
	}

	void EventManager::shutdown() {
		delete mInstance;
	}

  void EventManager::unsubscribe(unsigned char evt, EventListener* inListener)
  {
    if (mSubscriptions.find(evt) == mSubscriptions.end())
    {
      mLog->warnStream() << "attempting to unbind an unsubscribed event " << (int)evt;
      return;
    }

    subscribers_t& handlers = mSubscriptions.find(evt)->second;
    for (subscribers_t::iterator handler = handlers.begin();
      handler != handlers.end();
      ++handler)
      if ((*handler) == inListener)
      {
        handlers.erase(handler);
        break;
      }

  }
  void EventManager::update() {
    if (!mEvents.empty())
    {
      subscription_t::iterator subs = mSubscriptions.find(mEvents.front().UID);
      if (subs != mSubscriptions.end()) {
        subscribers_t *handlers = &(subs->second);
        subscribers_t::iterator handler;
        for (handler = handlers->begin();
             handler != handlers->end();
             ++handler) {
             //~ std::cout
              //~ << "enqueued an evt " << (int)mEvents.front().UID
              //~ << " to a listener " << (*handler)->getUID() << "\n";
             (*handler)->enqueue(mEvents.front());
           }
         }

      subs = mSubscriptions.find(EventUID::Unassigned);
      if (subs != mSubscriptions.end()) {
        subscribers_t *handlers = &(subs->second);
        subscribers_t::iterator handler;
        for (handler = handlers->begin();
             handler != handlers->end();
             ++handler) {
          //~ std::cout
            //~ << "enqueued an evt " << (int)mEvents.front().UID
            //~ << " to a full listener " << (*handler)->getUID() << "\n";
          (*handler)->enqueue(mEvents.front());
        }
      }

      mEvents.pop();
    }
  }

  void EventManager::clear()
  {
    while (!mEvents.empty())
      mEvents.pop();
  }
}
