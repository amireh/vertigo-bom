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

#ifndef H_HAX_LOG4CPP_FILE_LAYOUT_H
#define H_HAX_LOG4CPP_FILE_LAYOUT_H

#include <log4cpp/Portability.hh>
#include <log4cpp/Layout.hh>
#include <memory>

using namespace log4cpp;
namespace Hax {

  class LOG4CPP_EXPORT FileLayout : public Layout {
  public:
    FileLayout();
    virtual ~FileLayout();

    /**
     * Formats the message in style:<br>
     * "timeStamp priority category ndc: message"
     **/
    virtual std::string format(const LoggingEvent& event);
  };
}

#endif // END OF H_HAX_LOG4CPP_FILE_LAYOUT_H
