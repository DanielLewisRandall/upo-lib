/*
Copyright (c) 2013, Daniel Randall
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

* Neither the name of the Universal Programming Organization nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// A circular queue class, restricted to sizes that are a power of 2.
// Uses in this program: real-time parsing, high-performance buffering.

#ifndef __UPO_LIB__CircularQueue__
#define __UPO_LIB__CircularQueue__

#include "upo-lib.h"

class CircularQueue
{
	public:
		uint32_t m_nEnqueues;  // total number of enqueue operations
		uint32_t m_nDequeues;  // total number of dequeue operations
		uint32_t m_nIndexMask; // Index Mask - a bitmask
		OBJECT** m_ppObjects;  // pointer to array of object pointers

		CircularQueue();

		~CircularQueue();

		void Reset();

		bool Init(uint32_t dwSize);

		OBJECT* Enqueue(OBJECT* pObject);

		OBJECT* Dequeue();

		OBJECT* Peek();

		uint32_t Size();
};

#endif /* defined(__UPO_LIB__CircularQueue__) */
