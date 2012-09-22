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

#ifndef H_HAX_UTILITY_H
#define H_HAX_UTILITY_H

#include "Hax/Hax.hpp"

#include <typeinfo>
#include <sstream>
#include <vector>
#include <iostream>

namespace Hax {
namespace Utility {

	template<typename T>
	inline static
  string_t stringify(const T& v)
	{
		std::ostringstream o;

    if (!(o << v))
			throw BadConversion(string_t("stringify(") + typeid(v).name() + ")");

		return o.str();
	}

  // Alias for Utility::stringify
  template<typename T>
  inline static
  string_t toString(const T& v)
  {
    return stringify<T>(v);
  }

	// converts an integer-based type to a string
	template<typename T>
	inline static
  void convert(const string_t& s, T& v, bool failIfLeftoverChars = true)
	{
		std::istringstream buf(s);
		char c;
		if (!(buf >> v) || (failIfLeftoverChars && buf.get(c)))
			throw BadConversion(s);
	}

	template<typename T>
	inline static
  T convertTo(const string_t& s, bool failIfLeftoverChars = true)
	{
		T out;
		convert(s, out, failIfLeftoverChars);
		return out;
	}

  // Alias for Utility::convertTo<int>
  inline static
  int toNumber(const string_t& s) {
    return convertTo<int>(s);
  }

  /* splits a string s using the delimiter delim */
  inline static
  std::vector<string_t> split(const string_t &s, char delim) {
    std::vector<string_t> elems;
    std::stringstream ss(s);
    string_t item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
  }

  inline static
  void iJoin(const std::vector<string_t>& tokens, string_t &out, char delim) {
    for (std::vector<string_t>::const_iterator token = tokens.begin();
    token != tokens.end();
    ++token)
    {
      out += *token;
      out.push_back(delim);
    }
  }

  inline static
  string_t join(const std::vector<string_t>& tokens, char delim) {
    string_t out;
    iJoin(tokens, out, delim);
    return out;
  }

  inline static
  void iTrim(string_t &s) {
    int ws_ctr = 0;
    for (char c : s)
    {
      if (c == ' ' || c == '\t')
        ++ws_ctr;
      else
        break;
    }

    int reverse_ws_ctr = 0;
    char c;
    for (int i=s.size()-1; i >= 0; --i)
    {
      c = s[i];
      if (c == ' ' || c == '\t')
        ++reverse_ws_ctr;
      else
        break;
    }

    if (ws_ctr > 0 || reverse_ws_ctr > 0)
      s = s.substr(ws_ctr, s.size() - (ws_ctr + reverse_ws_ctr));
  }

  inline static
  string_t trim(string_t const& in)
  {
    string_t out(in);
    iTrim(out);
    return out;
  }

  inline static
  void iToLower(string_t& in)
  {
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
  }

  inline static
  string_t toLower(string_t const& in)
  {
    string_t out(in);
    iToLower(out);
    return out;
  }

  inline static
  void iToUpper(string_t& in)
  {
    std::transform(in.begin(), in.end(), in.begin(), ::toupper);
  }

  inline static
  string_t toUpper(string_t const& in)
  {
    string_t out(in);
    iToUpper(out);
    return out;
  }

  // Returns true if the string is any of: ["true"|"yes"|"on"]
  // (the comparison is case-insensitive)
  inline static
  bool boolify(const string_t& str)
  {
    string_t s = Utility::toLower(str);

    if (s == "true") return true;
    else if (s == "yes") return true;
    else if (s == "on") return true;

    return false;
  }

  // Alias for Utility::boolify
  inline static
  bool toBool(const string_t& s) {
    return boolify(s);
  }

  inline static
  void iErase(string_t& in, char delim)
  {
    size_t idx;
    while ((idx = in.find(delim)) != string_t::npos)
      in.erase(idx, 1);
  }

  inline static
  string_t erase(string_t const& in, char delim)
  {
    string_t out(in);
    iErase(out, delim);
    return out;
  }

  /**
   * suffixes given string with `fill` until it spans `size` characters
   **/
  inline static
  string_t expand(string_t const& in, size_t size, char fill)
  {
    if (in.size() >= size)
      return in;

    string_t out(in);
    while (out.size() < size)
      out.push_back(fill);

    return out;
  }

  inline static
  string_t rExpand(string_t const& in, size_t size, char fill)
  {
    if (in.size() >= size)
      return in;

    string_t out;
    size_t pad = size - in.size();
    while (out.size() < pad)
      out.push_back(fill);
    out += in;
    return out;
  }

  inline static
  void iShrink(string_t& in, char lsd)
  {
    size_t offset = 0;
    while (in.at(offset) == lsd)
      ++offset;

    in = in.substr(offset, in.size());
  }

  inline static
  bool isDecimal(string_t const& in)
  {
    for (auto c : in)
      if (c < '0' || c > '9')
        return false;

    return true;
  }

  /**
   * perform a locale-agnostic case insensitive search of a substring in a string
   **/
  inline static
  size_t ciFindSubstr(const string_t& str,
                      const string_t& substr,
                      const std::locale& loc = std::locale())
  {
    string_t::const_iterator it = std::search(
      str.begin(), str.end(),
      substr.begin(), substr.end(),
      [&loc](char ch1, char ch2) -> bool {
        return std::toupper(ch1, loc) == std::toupper(ch2, loc);
      });

    if ( it != str.end() )
      return it - str.begin();

    return string_t::npos; // not found
  }

  /**
   * converts a human-readable time string into numerical seconds, format:
   * [number][s|m|h|d|w], eg: 5s, 10m, 30h, 4d
   */
  inline static
  bool stringToSeconds(const string_t& str, timespec* ts)
  {
    if (str == "0") {
      ts->tv_sec = 0;
      return true;
    }

    int modifier = 1;
    switch(str.back())
    {
      case 's': case 'S': modifier = 1;   break;
      case 'm': case 'M': modifier = 60;  break;
      case 'h': case 'H': modifier = 3600;  break;
      case 'd': case 'D': modifier = 86400;  break;
      case 'w': case 'W': modifier = 604800;  break;
      default: return false;
    }

    string_t repl(str.begin(), str.end() - 1);
    try {
      unsigned int orig_nr = convertTo<unsigned int>(repl);
      ts->tv_sec = orig_nr * modifier;
    } catch (Hax::BadConversion& e) {
      return false;
    }

    return true;
  }

  /**
   * converts a human-readable filesize string into numerical bytes, format:
   * [number][b|k|m|g|t], eg: 5M, 10K, 1G, 3T
   */
  inline static
  bool stringToBytes(const string_t& str, uint64_t *sz)
  {
    if (str == "0") {
      (*sz) = 0;
      return true;
    }

    uint64_t modifier = 1;
    switch(str.back())
    {
      case 'b': case 'B': modifier = 1;   break;
      case 'k': case 'K': modifier = 1024;  break;
      case 'm': case 'M': modifier = 1048576;  break;
      case 'g': case 'G': modifier = 1073741824;  break;
      case 't': case 'T': modifier = 1099511627776;  break;
      default: return false;
    }

    string_t repl(str.begin(), str.end() - 1);
    try {
      unsigned int orig_nr = convertTo<unsigned int>(repl);
      (*sz) = orig_nr * modifier;
    } catch (Hax::BadConversion& e) {
      return false;
    }

    return true;
  }
} // namespace Utility
} // namespace Hax

#endif // END OF HAX_UTILITY
