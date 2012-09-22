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

#ifndef H_HAX_EVENT_H
#define H_HAX_EVENT_H

#include <vector>
#include <exception>
#include <map>
#include <iostream>
#include <boost/crc.hpp>
#include <boost/asio.hpp>

namespace Hax {

  namespace EventUID {

    enum {
      Unassigned = 0,
      EntitySelected,
      EntityDeselected,
      SanityCheck
    };
  }

  namespace EventFeedback {

    enum {
      Unassigned = 0,
      Ok,
      Error,
      InvalidRequest,
      SanityCheck
    };
  }

  /**
   * Base Event object that is used and handled to represent game events.
   */
  struct Event {

    enum {
      // if Length is small enough it will be cast to 1 byte thus we can't
      // depend on uint16_t being interpreted as 2 bytes long.. so we -1
      HeaderLength = 7, // "UIDOptionsFeedbackLength"
      FooterLength = 4 // "\r\n\r\n"
    };

    // event options
    enum {
      NoFormat    = 0x01, // events with no format will not be parsed per-property
      Compressed  = 0x02, // whether the content is compressed
      IsLocal     = 0x04, // local events will not be dispatched over the network
      Broadcast   = 0x08
    };

		typedef	std::map< std::string, std::string > property_t;

    Event();
    Event(const unsigned char inUID, const unsigned char = EventFeedback::Unassigned, unsigned char options=0);
    Event(const Event& src);
    Event& operator=(const Event& rhs);

		//! resets evt state
		~Event();

    bool fromStream(boost::asio::streambuf& in);
    void toStream(boost::asio::streambuf& out) const;

    //! resets event state
    void reset();

		std::string const& getProperty(std::string inName) const;

		void setProperty(const std::string inName, const std::string inValue);
    void setProperty(const std::string inName, int inValue);
    bool hasProperty(const std::string inName) const;

    friend std::ostream& operator<<(std::ostream&, const Event&);

    /// debug
		void dump(std::ostream& inStream = std::cout) const;

		unsigned char		      UID;
    unsigned char         Options;
    unsigned char	        Feedback;
    uint32_t              Length;
		int                   Checksum;
    property_t		        Properties;
    uint32_t              Rawsize;
    static const char     *Footer;
    static const uint32_t MaxLength; // no single message can be longer than this (2^32-1)
    void                  *Any;

    static int __CRC32(const std::string& my_string);
    static std::string __uidToString(unsigned char);
		void __clone(const Event& src);
	};

} // end of namespace
#endif // H_Event_H
