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

#ifndef H_HAX_FILE_MANAGER_H
#define H_HAX_FILE_MANAGER_H

#include "Hax/Hax.hpp"
#include "Hax/Logger.hpp"
#include "Hax/Configurable.hpp"
#include "Hax/binreloc/binreloc.h"

#include <sstream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <curl/curl.h>

namespace Hax {

  typedef boost::filesystem::path path_t;

  /**
   * @class FileManager
   *
   * Manages a logging system through log4cpp that can be used by an application
   * to log messages to a number of output devices; stdout, a file, or syslog.
   *
   * Logging devices and the format of messages are configurable.
   *
   * Actual logging of the messages should be done by by instances derived from
   * Hax::logger (see Hax/Hax_logger.hpp).
   */
  class FileManager : public Configurable, public Logger {
  public:

    /* the file manager's config context is "file manager" */
    struct {

      /**
       * dist_from_root:
       *  indicates how many directories to traverse up from the binary to reach
       *  the application's root directory
       *
       * default: "1" (application binary resides in /path/to/app/bin)
       *
       * alias keys: "dist from root"
       */
      string_t distFromRoot;
    } mConfig;

    static FileManager& getSingleton();

    virtual ~FileManager();
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    /**
     * Finds the fully-qualified paths of the application's binary, and its root.
     **/
    void resolvePaths();

    path_t const& getRootPath() const;

    path_t const& getConfigPath() const;
    /** Alias for getConfigPath() */
    path_t const& getCfgPath() const;

    path_t const& getResourcesPath() const;
    /** Alias for getResourcesPath() */
    path_t const& getResPath() const;

    path_t const& getPluginsPath() const;
    /** Alias for getPluginsPath() */
    path_t const& getPlgPath() const;

    path_t const& getBinaryPath() const;
    /** Alias for getBinaryPath() */
    path_t const& getBinPath() const;

    path_t const& getLogPath() const;

    path_t const& getScriptsPath() const;

    string_t const& getSuffix() const;

    typedef std::function<void (bool, const string_t&, string_t)> dl_cb_t;

    /**
     * a resource can be a remote file identified by a URL or a local file
     *  1. remote files: http://path/to/file
     *  2. local files: file://path/to/file
     */
    bool getResource(string_t const& resource_path, string_t& out_buf);

    /**
     * downloads the file found at URL and stores it in out_buf
     *
     * @return true if the file was correctly DLed, false otherwise
     */
    bool getRemote(string_t const& URL, string_t& out_buf);

    /** same as above but outputs to file instead of buffer */
    bool getRemote(string_t const& URL, std::ofstream& out_file);

    /**
     * note: the stream must be open and this method will NOT close it
     */
    bool loadFile(std::ifstream &file, string_t& out);

    /** overridden from Hax::configurable */
    virtual void setOption(string_t const& key, string_t const& value);

    size_t __onCurlData(char *buffer, size_t size, size_t nmemb, void *userdata);
  private:
    explicit FileManager();
    static FileManager* __instance;

    // all paths do NOT end with the trailing / or \, you must supply that
		path_t mCfgPath;
    path_t mBinPath;  // this is where the binary is
    path_t mRootPath; // path to the application tree root
    path_t mPlgPath;  // path to the plugins folder
    path_t mResPath;  // path to the resources folder
    path_t mLogPath;  // where logs are dumped
    path_t mScriptsPath;  // app scripts path

    string_t mSuffix;
    struct download_t {
      uint64_t        id;
      string_t        *buf;
      string_t        uri;
      dl_cb_t         callback;
      bool            status;
    };

    static uint64_t mDownloadId;
  };

} // namespace Hax

#endif // H_HAX_FILE_MANAGER_H
