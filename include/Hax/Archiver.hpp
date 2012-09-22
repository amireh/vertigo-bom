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

#ifndef H_HAX_ARCHIVER_H
#define H_HAX_ARCHIVER_H

#include "Hax/Hax.hpp"

#include "lzma/LzmaEnc.h"
#include "lzma/LzmaDec.h"
#include "lzma/LzmaLib.h"
#include "lzma/Types.h"

#include <vector>

namespace Hax {

	/** @class Archiver
	 *	@brief
	 *	Provides compression and decompression services using Lzma and BZip2.
	 */
	class Archiver {
	public:

		Archiver();
		~Archiver();

    // encode & decode to file
    static int decodeLzma(const char* src, const char* dest);
    static int encodeLzma(const char* src, const char* dest, UInt64 *srcSize=0, UInt64 *destSize=0);

    // in-memory encode & decode
    static int encodeLzma(std::vector<unsigned char> &outBuf, const std::vector<unsigned char> &inBuf);
    static int decodeLzma(std::vector<unsigned char> &outBuf, const std::vector<unsigned char> &inBuf, UInt64 srcSize);

	protected:

	};
}

#endif
