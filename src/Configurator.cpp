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

#include "Hax/Configurator.hpp"
#include "Hax/FileManager.hpp"

namespace Hax {

  Configurator::subs_t Configurator::mSubs;
  bool Configurator::fInit = false;

  //void Configurator::subscribe(Configurable *cfg)
  //{
  //  subscribe(cfg, cfg->context());
  //}

  void Configurator::init()
  {
    mSubs.clear();
    fInit = true;
  }

  void Configurator::subscribe(Configurable *cfg, const string_t& ctx)
  {
    if (!fInit)
      init();

    if (mSubs.find(ctx) != mSubs.end()) {
      HAX_LOG->warnStream() << "configuration context '" << ctx << "' is already registered";
      //~ std::cout << "configuration context '" << ctx << "' is already registered\n";

      return;
    }

    mSubs.insert(std::make_pair(ctx, cfg));
    HAX_LOG->infoStream() << "subscribed a Configurable service '" << ctx << "'";
    //~ std::cout << "subscribed a Configurable service '" << ctx << "'\n";
  }

  // the callbacks to handle the config parsing
  static yajl_callbacks cfg_callbacks = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // on a JSON string value
    [](void* ctx, const unsigned char* key, size_t len) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonMapVal(key, len);
    },

    // on JSON map start
    [](void* ctx) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonMapStart();
    },

    // on JSON map key
    [](void* ctx, const unsigned char* key, size_t len) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonMapKey(key, len);
    },
    // on JSON map end
    [](void* ctx) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonMapEnd();
    },

    // on JSON array start,
    [](void* ctx) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonArrayStart();
    },

    // on JSON array end
    [](void* ctx) -> int {
      Configurator* cfg = (Configurator*)ctx;
      return cfg->__onJsonArrayEnd();
    },
  };

  Configurator::Configurator(string_t const& data)
  : Logger("Configurator"),
    mData(data),
    mDepth(0),
    mCurrSub(0)
  {
  }

  Configurator::Configurator(std::ifstream& fh)
  : Logger("Configurator"),
    mData(),
    mDepth(0),
    mCurrSub(nullptr)
  {
    // TODO: read file contents into string
    FileManager::getSingleton().loadFile(fh, mData);
  }

  Configurator::~Configurator()
  {
    mData.clear();
  }

  void Configurator::run()
  {
    mLog->infoStream() << "configuring subscribers from JSON sheet";
    //~ mLog->debugStream() << "JSON data: \n" << mData;

    yajl_status stat;
    yajl_handle hnd(yajl_alloc(&cfg_callbacks, NULL, this));
    yajl_config(hnd, yajl_allow_comments, 1);

    stat = yajl_parse(hnd, (const unsigned char*)mData.c_str(), mData.size());

    if (stat != yajl_status_ok) {

      unsigned char *yajl_error = yajl_get_error(hnd, 1, (const unsigned char*)mData.c_str(), mData.size());
      mLog->errorStream()
        << "error parsing JSON config, bailing out #{"
        << stat << "} => " << yajl_error;
      yajl_free_error(hnd, yajl_error);
      yajl_free(hnd);
      return;
    }

    yajl_free(hnd);

    mLog->infoStream() << "configuration was successful";
  }


  int Configurator::__onJsonMapStart()
  {
    ++mDepth;
    return yajl_continue;
  }

  int Configurator::__onJsonMapKey(const unsigned char* key, size_t len)
  {
    mCurrKey.clear();
    mCurrKey = std::string((const char*)key, len);

    if (isReserved(mCurrKey))
      return yajl_continue;

    if (!mCurrSub) {
      subs_t::iterator finder = mSubs.find(mCurrKey);
      mCurrCtx = mCurrKey;

      if (finder != mSubs.end())
      {
        mCurrSub = finder->second;
        mCurrSub->mCurrentCtx = mCurrCtx;

        mLog->infoStream() << "configuring '" << mCurrKey << "'";
      } else {
        mLog->warnStream() << "no subscribed configurable for context '" << mCurrKey << "', skipping config";
      }
    }

    return yajl_continue;
  }

  int Configurator::__onJsonMapVal(const unsigned char *val, size_t len)
  {
    if (mCurrKey == "include")
    {
      mCurrVal.clear();
      mCurrVal = string_t((const char*)val, len);

      mLog->infoStream() << "including external config file: " << mCurrVal;
      string_t data;
      if (FileManager::getSingleton().getRemote(mCurrVal, data)) {
        Configurator cfg(data);
        cfg.run();
      }
      return yajl_continue;
    }

    if (mCurrSub) {
      mCurrVal.clear();
      mCurrVal = string_t((const char*)val, len);

      mCurrSub->setOption(mCurrKey, mCurrVal);
    }

    return yajl_continue;
  }

  int Configurator::__onJsonMapEnd()
  {
    --mDepth;

    if (mCurrSub)
      mCurrSub->configure();

    mCurrSub = NULL;
    mCurrKey.clear();
    mCurrVal.clear();
    mCurrCtx.clear();

    if (mDepth == 0) {
      return yajl_continue;
    }

    return yajl_continue;
  }

  int Configurator::__onJsonArrayStart()
  {
    return yajl_continue;
  }

  int Configurator::__onJsonArrayEnd()
  {
    mCurrKey.clear();
    mCurrVal.clear();

    return yajl_continue;
  }

  bool Configurator::isReserved(const string_t& ctx)
  {
    // reserved keywords (or "contexts", in our parser sense)
    if (ctx == "include")
      return true;

    return false;
  }
} // namespace Hax
