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

#include "Hax/log4cpp/FileLayout.hpp"
#include "log4cpp/Priority.hh"
#include "log4cpp/FactoryParams.hh"

#ifdef LOG4CPP_HAVE_SSTREAM
#include <sstream>
#endif
#include <iostream>
#include <iomanip>
#include <time.h>

namespace Hax {

  FileLayout::FileLayout()
  {
  }

  FileLayout::~FileLayout() {
  }

  std::string FileLayout::format(const LoggingEvent& event) {

		std::ostringstream message;

    const std::string& priorityName = Priority::getPriorityName(event.priority);

    // no need to print timestamps if we're using syslog
    struct tm *pTime;
    time_t ctTime; time(&ctTime);
    pTime = localtime( &ctTime );
    message << std::setw(2) << std::setfill('0') << pTime->tm_hour
        << ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
        << ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
        << " ";

		// start off with priority
		message << "[" << priorityName[0]	<< "] ";

		// append NDC
		if (event.ndc != "")
			message << event.ndc << ": ";

		message << event.message << "\n";

    return message.str();
  }
}
