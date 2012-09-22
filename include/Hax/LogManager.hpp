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

#ifndef H_HAX_LOG_MANAGER_H
#define H_HAX_LOG_MANAGER_H

#include "Hax/Hax.hpp"
#include "Hax/Log.hpp"
#include "Hax/Configurable.hpp"

#include <boost/filesystem.hpp>

namespace Hax {

  /**
   * @class LogManager
   *
   * Manages a logging system through log4cpp that can be used by an application
   * to log messages to a number of output devices; stdout, a file, or syslog.
   *
   * Logging devices and the format of messages are configurable.
   *
   * Actual logging of the messages should be done by by instances derived from
   * Hax::Logger (see Hax/Logger.hpp).
   */
  class LogManager : public Configurable {
  public:

    /* the log manager's config context is "log manager" */
    struct config_t {
      string_t device;   /** possible values: 'stdout' or 'syslog' or 'file', default: 'file' */
      string_t level;    /** possible values: 'debug', 'notice', 'info', 'warn', 'error', default: 'debug' */

      /* the following apply only when logging to a file */
      string_t dir;      /** default: "log", the log file will be in /path/to/app/log/mLogname.log */
      string_t filename;     /** default: "Hax.log" */
      string_t filesize; /** value format: "[NUMBER][B|K|M]", default: 10M */

      string_t app_name;
      string_t app_version;
      string_t app_website;

      bool     silent;
    } mConfig;

    static LogManager& getSingleton();

    /** The unique log4cpp::category identifier, used internally by logger instances */
    string_t const& getCategory();

    virtual ~LogManager();
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

    /**
     * Initializes the logging system, this must be called before the LogManager
     * is configured.
     *
     * @param category_name
     *  A unique identifier for the primary logging category used to create
     *  instances of loggers. (Note: this string will not be visible in logs.)
     **/
    void init(string_t inCategoryName = "Hax");

    /**
     * If you init() the log manager, you must call this when you're done
     * to free allocated resources.
     *
     * @warning
     * Any attempt to log messages once the log manager is cleaned up might
     * result in undefined behaviour.
     */
    void cleanup();

    /**
     * Re-builds the logging system with the current configuration settings.
     *
     * @note
     * For internal implementation reasons, the log manager does not subscribe
     * itself to the "log manager" configuration context automatically; you must
     * do that somewhere BEFORE the configuration is parsed.
     *
     * IE, somewhere before you parse configuration file:
     *  configurator::subscribe(&LogManager::singleton(), "log manager");
     */
    virtual void configure();

    /** overridden from Hax::configurable */
    virtual void setOption(string_t const& key, string_t const& value);

    /** a log that can be used by any entity that is not a derivative of Hax::logger */
    log_t* getLog();

  private:
    explicit LogManager();
    static LogManager* __instance;

    log4cpp::Appender *mAppender;
    log4cpp::Layout   *mLayout;
    log4cpp::Category *mCategory;
    log4cpp::Category	*mLog;
    log4cpp::Category	*mAnonymousLog;

    string_t mCategoryName;
  };

# ifndef HAX_LOG
#   define HAX_LOG Hax::LogManager::getSingleton().getLog()
# endif

} // namespace Hax

#endif // H_HAX_LOG_MANAGER_H
