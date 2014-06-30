/*
Copyright (c) 2014, Daniel Randall
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

#ifndef __UPO_LIB__SquareArray__
#define __UPO_LIB__SquareArray__

#include <iostream>
#include "upo-lib.h"

struct xy
{
		uint32_t x;
		uint32_t y;
};

enum QUAD
{
	QUAD_A,
	QUAD_B,
	QUAD_C,
	QUAD_D,
	QUADS_COUNT
};

template <class C>
class SquareArray // represents a square, 2-dimensional array
{
	private:
		uint32_t m_nSize;
		C** m_ppObjects;  // pointer to array of object pointers
		
	public:
		
		SquareArray();
		
		~SquareArray();
		
		void Reset();

		bool Init(
			uint32_t nSize);
		
		C* Get(
			 uint32_t x,
			 uint32_t y);

		C* Get(
			 xy coords);

		void Set(
			 uint32_t x,
			 uint32_t y,
			 C* pValue);

		void Set(
			 xy coords,
			 C* pValue);

		void Move(
			 uint32_t tx,
			 uint32_t ty,
			 uint32_t fx,
			 uint32_t fy);

		void Move(
			 xy to_coords,
			 xy fr_coords);

		uint32_t Index(
			 uint32_t x,
			 uint32_t y);
		
		void Rotate(
			DIR dir);
};


#endif /* defined(__UPO_LIB__SquareArray__) */
