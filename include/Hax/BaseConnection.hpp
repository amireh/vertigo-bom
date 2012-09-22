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


#ifndef H_HAX_BASE_CONNECTION_H
#define H_HAX_BASE_CONNECTION_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Hax/Dispatcher.hpp"
#include "Hax/Event.hpp"

namespace Hax {

  /// Represents a single BaseConnection from a client.
  class BaseConnection
    : public boost::enable_shared_from_this<BaseConnection>,
      protected boost::noncopyable
  {
  public:
    /// Construct a BaseConnection with the given io_service.
    explicit BaseConnection(boost::asio::io_service& io_service);
    virtual ~BaseConnection();

    /// Get the socket associated with the BaseConnection.
    boost::asio::ip::tcp::socket& socket();
    dispatcher& get_dispatcher();

    /// Start the first asynchronous operation for the BaseConnection.
    virtual void start();
    /// forcefully breaks all async ops and closes the socket
    virtual void stop();

    virtual void send(const Event& evt);

  protected:

    virtual void read();
    virtual void do_read();

    void
    handle_read( const boost::system::error_code& error, std::size_t bytes_transferred);

    virtual void handle_inbound();
    virtual void do_send(Event&);

    boost::asio::ip::tcp::socket socket_;
    boost::asio::streambuf request_;
    boost::asio::mutable_buffer body_;
    boost::asio::streambuf response_;
    boost::asio::strand strand_;

    dispatcher dispatcher_;
    Event outbound, inbound;

    bool closed_;
  };

  typedef boost::shared_ptr<BaseConnection> BaseConnection_ptr;

} // namespace Hax

#endif
