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

#include "SquareArray.h"


template <class C>
SquareArray<C>::SquareArray()
{
	m_ppObjects = NULL;
}

template <class C>
SquareArray<C>::~SquareArray()
{
	Reset();
}

template <class C>
void SquareArray<C>::Reset()
{
	// free array of object pointers:
	if (m_ppObjects)
	{
		delete [] m_ppObjects;
	}

	m_nSize = 0;
	m_ppObjects = NULL;
}

template <class C>
bool SquareArray<C>::Init(
	uint32_t nSize)
{
	// allow object re-use:
	Reset();

	m_nSize = nSize;
	
	// verify size is not zero:
	if (m_nSize == 0)
	{
		return false;
	}

	// allocate the object pointer array:
	m_ppObjects = new C*[m_nSize * m_nSize];

	// will return true only if all of the above succeeded:
	return (m_ppObjects != NULL);
}

template <class C>
C* SquareArray<C>::Get(
   uint32_t x,
   uint32_t y)
{
   return m_ppObjects[Index(x, y)];
}

template <class C>
C* SquareArray<C>::Get(
   xy coords)
{
   return Get(coords.x, coords.y);
}

template <class C>
void SquareArray<C>::Set(
   uint32_t x,
   uint32_t y,
   C* pValue)
{
   m_ppObjects[Index(x, y)] = pValue;
}

template <class C>
void SquareArray<C>::Set(
   xy coords,
   C* pValue)
{
   Set(coords.x, coords.y, pValue);
}

template <class C>
void SquareArray<C>::Move(
   uint32_t tx,
   uint32_t ty,
   uint32_t fx,
   uint32_t fy)
{
	Set(tx, ty, Get(fx, fy));
}

template <class C>
void SquareArray<C>::Move(
   xy to_coords,
   xy fr_coords)
{
	Move(to_coords.x, to_coords.y, fr_coords.x, fr_coords.y);
}

template <class C>
uint32_t SquareArray<C>::Index(
   uint32_t x,
   uint32_t y)
{
   // convert x, y to linear index:
   return (x + (m_nSize * y));
}

template <class C>
void SquareArray<C>::Rotate(
   DIR dir)
{
   // variables table:
   // current strip: strip
   // current cell on strip: cell
   // length of strip: length
   // cell at end of strip: end
   
   uint32_t end = (m_nSize - 1);

   // each iteration of this loop represents a strip;
   // each pass will reduce the length of the strip by 2 cells:
   for (uint32_t length = m_nSize, strip = 0; length > 1; length -= 2, strip++)
   { 
      // each iteration of this loop represents a cell on the strip;
      // the last cell is skipped to avoid repeats:
      for (uint32_t cell = strip; cell < ((length + strip) - 1); cell++)
      {
				xy cells[4];
				
				// set up the coordinates for the current cell in each quadrant:
				cells[QUAD_A].x = strip;
				cells[QUAD_A].y = cell;
				
				cells[QUAD_B].x = cell;
				cells[QUAD_B].y = end - strip;
				
				cells[QUAD_C].x = end - strip;
				cells[QUAD_C].y = end - cell;
				
				cells[QUAD_D].x = end - cell;
				cells[QUAD_D].y = strip;

				 // save value of quadrant A cell:
         C* pCellA = Get(cells[QUAD_A]);

				 if (dir == CW)
         {
            // set quadrant A cell to value of quadrant D cell:
            Move(cells[QUAD_A], cells[QUAD_D]);
           
            // set quadrant D cell to value of quadrant C cell:
            Move(cells[QUAD_D], cells[QUAD_C]);

            // set quadrant C cell to value of quadrant B cell:
            Move(cells[QUAD_C], cells[QUAD_B]);

            // set quadrant B cell to value of quadrant A cell:
            Set(cells[QUAD_B], pCellA);
         }
         else
         {
            // set quadrant A cell to value of quadrant B cell:
            Move(cells[QUAD_A], cells[QUAD_B]);
           
            // set quadrant B cell to value of quadrant C cell:
            Move(cells[QUAD_B], cells[QUAD_C]);
           
            // set quadrant C cell to value of quadrant D cell:
            Move(cells[QUAD_C], cells[QUAD_D]);

            // set quadrant D cell to value of quadrant A cell:
            Set(cells[QUAD_D], pCellA);
         }
      }            
   }
}






