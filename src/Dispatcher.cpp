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

#include "Hax/Dispatcher.hpp"

namespace Hax {

  dispatcher::dispatcher(boost::asio::io_service& io_service)
  : strand_(io_service) {
  }

  dispatcher::~dispatcher() {
    events.clear();
  }

  void dispatcher::deliver(const Event& evt, bool immediate) {
    events.push_back(Event(evt));
    if (!immediate)
      strand_.post( boost::bind( &dispatcher::dispatch, this ) );
    else
      dispatch();
  }

  void dispatcher::dispatch() {
    assert(!events.empty());
    //const Event& evt = events.front();
    Event evt(events.front());
    events.pop_front();

    std::cout << "dispatching event: " << evt << "\n";
    evt_handlers_t::const_iterator handlers = evt_handlers_.find(evt.UID);
    std::vector<evt_handler_t>::const_iterator handler;
    if (handlers != evt_handlers_.end())
      for (handler = handlers->second.begin();
           handler != handlers->second.end();
           ++handler)
        (*handler)( evt );

    handlers = evt_handlers_.find(EventUID::Unassigned);
    if (handlers != evt_handlers_.end())
      for (handler = handlers->second.begin();
           handler != handlers->second.end();
           ++handler)
        (*handler)( evt );

  }

  void dispatcher::unbind(unsigned char evt)
  {
    assert(evt_handlers_.find(evt) != evt_handlers_.end());

    evt_handlers_.find(evt)->second.clear();
  }

  void dispatcher::reset()
  {
    evt_handlers_.clear();
    //events.clear();
  }
}
