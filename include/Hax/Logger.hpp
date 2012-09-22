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

#ifndef H_HAX_LOGGER_H
#define H_HAX_LOGGER_H

#include "Hax/Hax.hpp"
#include "Hax/Log.hpp"
#include "Hax/LogManager.hpp"

namespace Hax
{
	/*!
   * @brief
   * Logger objects respond to the operator<< for logging to an std::ostream.
	 */
	class Logger
	{

	public:
    /**
     * @param context
     *  A prefix prepended to every message logged by this system. This should
     *  normally denote the name of the logging module.
     */
		inline Logger(const char* context = "Unnamed")
    : mLog(0)
    {
      mLog = new log4cpp::FixedContextCategory(LogManager::getSingleton().getCategory(), context);
    }

		inline Logger& operator=(const Logger& rhs)
    {
      if (this != &rhs) mLog = rhs.mLog;

      return *this;
    }

		inline Logger(const Logger& src)
    {
      mLog = src.mLog;
    }

		inline virtual ~Logger()
    {
      delete mLog;
      mLog = 0;
    }

    inline log_t* getLog()
    {
      return mLog;
    }

		protected:
		log_t* mLog;

	}; // end of Logger class
} // end of Hax namespace
#endif
