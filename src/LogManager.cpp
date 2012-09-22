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

#include "Hax/LogManager.hpp"
#include "Hax/Utility.hpp"
#include "Hax/FileManager.hpp"
#include <map>

namespace Hax {

  LogManager* LogManager::__instance = 0;

  LogManager::LogManager()
    // Subscribing to a configurable context here would cause an infinite loop
    // since it tries to call the LogManager::getSingleton()
  : Configurable(),
    mAppender(0),
    mLayout(0),
    mCategory(0),
    mLog(0),
    mAnonymousLog(0),
    mCategoryName("Hax")
  {
    mConfig.device = "stdout";
    mConfig.dir = "log";
    mConfig.filename = "Hax.log";
    mConfig.level = "debug";
    mConfig.filesize = "10M";
    mConfig.app_name = "Hax";
    mConfig.app_version = "v0.0.rv0";
    mConfig.app_website = "http://www.hax.com";
    mConfig.silent = false;

    init();
  }

  LogManager::~LogManager()
  {
  }

  LogManager& LogManager::getSingleton() {
    if (!__instance)
      __instance = new LogManager();

    return *__instance;
  }

  string_t const& LogManager::getCategory() {
    return mCategoryName;
  }

  void LogManager::init(string_t cat) {
    if (mLog) // we already initialized
      return;

    mCategoryName = cat;

    mCategory = &log4cpp::Category::getInstance(mCategoryName);
    mCategory->setAdditivity(false);
    mCategory->setPriority(log4cpp::Priority::DEBUG);

    mLog
      = new log4cpp::FixedContextCategory(mCategoryName, "LogMgr");
    mAnonymousLog
      = new log4cpp::FixedContextCategory(mCategoryName, "Anonymous");
  }

  void LogManager::cleanup()
  {
    if (mLog)
      delete mLog;
    if (mAnonymousLog)
      delete mAnonymousLog;

    // shutting down the log4cpp category will take care of freeing the
    // appenders and their layouts, so we don't have to deal with it
    mAppender = 0;
    mCategory = 0;
    mLayout = 0;
    mLog = mAnonymousLog = 0;

    log4cpp::Category::shutdown();
  }

  log_t* LogManager::getLog()
  {
    return mAnonymousLog;
  }

  void LogManager::configure()
  {
    // set the logging level
    std::map< string_t, log4cpp::Priority::Value > str2prio;
    str2prio.insert(std::make_pair("debug",  log4cpp::Priority::DEBUG));
    str2prio.insert(std::make_pair("notice", log4cpp::Priority::NOTICE));
    str2prio.insert(std::make_pair("info",   log4cpp::Priority::INFO));
    str2prio.insert(std::make_pair("warn",   log4cpp::Priority::WARN));
    str2prio.insert(std::make_pair("error",  log4cpp::Priority::ERROR));

    if (str2prio.find(mConfig.level) == str2prio.end()) {
      std::cerr << "invalid logging level '" << mConfig.level << "', falling back to DEBUG\n";

      mConfig.level = "debug";
    }

    mCategory->setPriority(str2prio[mConfig.level]);

    // remove the current appender
    if (mAppender) {
      mAppender->close();
      mCategory->removeAppender(mAppender);
    }

    // create the new appender
    bool using_syslog = false;
    if (mConfig.device == "syslog")
    {
      mAppender =	new log4cpp::SyslogAppender("SyslogAppender", mCategoryName);
      using_syslog = true;
    }
    else if (mConfig.device == "stdout")
    {
      mAppender =	new log4cpp::OstreamAppender("STDOUTAppender", &std::cout);
    }
    else
    {
      uint64_t filesz = 0;
      if (!Utility::stringToBytes(mConfig.filesize, &filesz)) {
        std::cerr << "invalid log filesize '" << mConfig.filesize << ", defaulting to 10M\n";
        filesz = 10 * 1024 * 1024;
      }

      // make sure the directory exists
      FileManager& fmgr = FileManager::getSingleton();
      path_t mLogPath = fmgr.getRootPath() / path_t(mConfig.dir);
      if (!boost::filesystem::exists(mLogPath))
        boost::filesystem::create_directory(mLogPath);

      mAppender =
      new log4cpp::RollingFileAppender(
        "RollingFileAppender",
        mLogPath.make_preferred().string() + "/" + mConfig.filename,
        filesz);
    }

    // register the appender
    mCategory->addAppender(mAppender);

    // assign a vanilla appender layout for header logging
    if (!mConfig.silent) {
      mLayout = new VanillaLayout();
      mAppender->setLayout(mLayout);

      mLog->errorStream() << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
      mLog->errorStream() << "\n+                          "
        << mConfig.app_name
        << " "
        << mConfig.app_version << "                               +";
      mLog->errorStream() << "\n+                         (" << mConfig.app_website << ")                             +";
      mLog->errorStream() << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

      mAppender->close();
      delete mLayout;
    }

    // assign the real appender layout
    // if (using_syslog)
    //   mLayout = new SyslogLayout();
    // else
      mLayout = new FileLayout();

    mAppender->setLayout(mLayout);
    mAppender->reopen();

    mLog->getStream(str2prio[mConfig.level]) << "logging level set to " << mConfig.level;

    if (mConfig.device == "file") {
      mLog->getStream(str2prio[mConfig.level])
      << "log file will be rotated every " << mConfig.filesize;
    }
  }

  void LogManager::setOption(string_t const& key, string_t const& value)
  {
    if (key == "device" || key == "log interface" || key == "log device" || key == "device")
    {
      if (value == "syslog")
        mConfig.device = value;
      else if (value == "stdout")
        mConfig.device = value;
      else if (value == "file")
        mConfig.device = value;
      else {
        mLog->warnStream() << "unknown logging mechanism specified '" << value << "', falling back to 'file'";
        mConfig.device = "file";
      }
    }
    else if (key == "filesize" || key == "log filesize" || key == "filesize") {
      mConfig.filesize = value;
    }
    else if (key == "filename" || key == "log filename" || key == "filename") {
      mConfig.filename = value;
    }
    else if (key == "dir" || key == "log directory" || key == "directory") {
      mConfig.dir = value;
    }
    else if (key == "level" || key == "log level" || key == "level") {
      mConfig.level = value;
    }
    else if (key == "app_name" || key == "app name") {
      mConfig.app_name = value;
    }
    else if (key == "app_version" || key == "app version" || key == "version") {
      mConfig.app_version = value;
    }
    else if (key == "app_website" || key == "app website" || key == "website") {
      mConfig.app_website = value;
    }
    else if (key == "log header") {
      mConfig.silent = (value == "false") ? true : false;
    }
    else {
      mLog->warnStream() << "unknown LogManager config setting '" << key << "' => '" << value << "', discarding";
    }
  }
} // namespace Hax
