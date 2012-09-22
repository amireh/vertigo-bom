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

#ifndef H_HAX_NETWORK_MANAGER_H
#define H_HAX_NETWORK_MANAGER_H

#include <iostream>
#include <boost/thread.hpp>

#include "Hax/Hax.hpp"
#include "Hax/Connection.hpp"

namespace Hax {

	struct Event;

	/*! \class NetworkManager
	 *	\brief
	 *	Handles connections and sockets and streaming of game data over the network.
	 *	This class also intercepts all events meant to be sent to the server and
	 *	does the actual sending
	 */
	class NetworkManager {

	public:
		static NetworkManager* getSingletonPtr();
    static NetworkManager& getSingleton();
		virtual ~NetworkManager();

		/*! \brief
		 *	initiates connection to the master server, result of the attempt
		 *	is handled by connAccepted() and connFailed()
		 */
		bool connect();

		/*! \brief
		 *	dispatches a "Logout" event to all the local modules so they can
		 *	wrap up their work, then severes the connection with the MS
		 */
		bool disconnect();

    void send(const Event&);

    bool isConnected() const;

	protected:
    void doConnect();

		/*! \brief
		 *	uses dispatchEvent() method to broadcast an incoming event
		 */
		void onInbound(const Event&);

    void onSyncGameData(const Event&);

		log4cpp::Category	*mLog;

		bool fOnline;

	private:
		static NetworkManager* mInstance;
		NetworkManager();

    Connection_ptr conn_;
    std::string mHost;

    boost::asio::io_service& io_service_;
    boost::asio::io_service::work work_;
    boost::asio::deadline_timer timer_;
    boost::thread* poller_;

	};
}

#endif
