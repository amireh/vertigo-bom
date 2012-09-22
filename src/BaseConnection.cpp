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

#include "BaseConnection.hpp"

namespace Hax {

BaseConnection::BaseConnection(boost::asio::io_service& io_service)
  : socket_(io_service),
    strand_(io_service),
    dispatcher_(io_service),
    request_(Event::MaxLength),
    response_(Event::MaxLength),
    closed_(false)
{
  std::cout << "A BaseConnection has been created\n";
}

BaseConnection::~BaseConnection() {
  std::cout << "A BaseConnection has been destroyed\n";
}

boost::asio::ip::tcp::socket& BaseConnection::socket() {
  return socket_;
}
dispatcher& BaseConnection::get_dispatcher() {
  return dispatcher_;
}

void BaseConnection::start() {

  socket_.set_option(boost::asio::ip::tcp::no_delay(true));
  //socket_.set_option( boost::asio::socket_base::send_buffer_size( 8096 ) );
  //socket_.set_option( boost::asio::socket_base::receive_buffer_size( 8096 ) );
  boost::asio::socket_base::non_blocking_io command(true);
  socket_.io_control(command);
  read();
}

void BaseConnection::stop() {
  if (closed_)
    return;

  boost::system::error_code ignored_ec;

  // initiate graceful BaseConnection closure & stop all asynchronous ops
  socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
  //socket_.close(ignored_ec);

  std::cout << "Connection: closed\n";
  closed_ = true;
}

void BaseConnection::read() {
  strand_.post(boost::bind(&BaseConnection::do_read, shared_from_this()));
}

  void BaseConnection::do_read() {
    inbound.reset();
    request_.consume(request_.size());

    /*this->async_read( // s11n
     inbound,
     boost::bind(&BaseConnection::handle_read, shared_from_this(), boost::asio::placeholders::error));*/

    async_read_until(
      socket_,
      request_,
      Event::Footer,
      boost::bind(
        &BaseConnection::handle_read,
        shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred
      )
    );
  }

void BaseConnection::handle_read(
  const boost::system::error_code& e,
  std::size_t bytes_transferred)
{
  if (!e) {
    while (request_.size() > 0 && inbound.fromStream(request_)) {
      //bool result = ;
      //if (result) {
        //request_.consume(bytes_transferred);

        handle_inbound();
    }
        // read next message
        read();
        //strand_.post( boost::bind(&BaseConnection::read, shared_from_this()) );
      //} else {
      //  stop();
        //break;
      //}
    //}

  } else
    stop();
}

void BaseConnection::send(const Event& evt) {
  strand_.post(boost::bind(&BaseConnection::do_send, shared_from_this(), evt));
}

  void BaseConnection::do_send(Event &evt) {
    //std::cout << "outbound buffer has " << response_.size() << "bytes (expected 0)";

    boost::system::error_code ec;

    //response_.consume(response_.size());

    outbound = Event(evt);
    outbound.toStream(response_);

    size_t n = boost::asio::write(socket_, response_.data(), boost::asio::transfer_all(), ec);
    //std::cout << "sent " << n << "bytes of data, buffer now has " << response_.size() << "\n";
    /*this->async_write(outbound,
     boost::bind(&BaseConnection::handle_write, shared_from_this(),
     boost::asio::placeholders::error));*/

    if (!ec) {
      //std::cout << " - sent " << n << "bytes (out of" << response_.size() << "b)\n";
      response_.consume(n);
      //std::cout << " cleared response buf ( " << response_.size() << ")\n";
    } else
      stop();

  }

  void BaseConnection::handle_inbound() {
    // message is ready for dispatching
    dispatcher_.deliver(inbound);
  }

} // namespace Hax
