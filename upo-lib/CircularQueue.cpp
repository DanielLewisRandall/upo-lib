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

#include "CircularQueue.h"


template <class C>
CircularQueue<C>::CircularQueue()
{
	m_ppObjects = NULL;
}

template <class C>
CircularQueue<C>::~CircularQueue()
{
	Reset();
}

template <class C>
void CircularQueue<C>::Reset()
{
	// free array of object pointers:
	if (m_ppObjects)
	{
		delete [] m_ppObjects;
	}

	m_nEnqueues = 0;
	m_nDequeues = 0;
	m_nIndexMask = 0;
	m_ppObjects = NULL;
}

template <class C>
bool CircularQueue<C>::Init(uint32_t dwSize)
{
	// allow object re-use:
	Reset();

	// verify size is not zero:
	if (dwSize == 0)
	{
		return false;
	}

	// calculate the bit mask:
	m_nIndexMask = dwSize - 1;

	// verify size is a power of 2:
	if (dwSize & (m_nIndexMask))
	{
		return false;
	}

	// allocate the queue object pointers:
	m_ppObjects = new C*[dwSize];

	// will return true only if all of the above succeeded:
	return (m_ppObjects != NULL);
}

// enqueue function:
template <class C>
C* CircularQueue<C>::Enqueue(C* pObject)
{
	// check for overflow:
	if (Size() > m_nIndexMask)
	{
		return NULL;
	}

	// calculate the enqueue index:
	uint32_t nEnqueueIndex = (m_nEnqueues & m_nIndexMask);

	// set the object pointer value:
	*(m_ppObjects + nEnqueueIndex) = pObject;

	// increment enqueue count:
	m_nEnqueues++;

	return pObject;
}

// dequeue function:
template <class C>
C* CircularQueue<C>::Dequeue()
{
	// get the object pointer value:
	C* pObject = Peek();

	// increment dequeue count (if no peek error):
	if (pObject != NULL)
	{
		m_nDequeues++;
	}

	return pObject;
}

template <class C>
C* CircularQueue<C>::Peek()
{
	// check for underflow:
	if (Size() == 0)
	{
		return NULL;
	}

	// calculate the dequeue index:
	uint32_t nDequeueIndex = (m_nDequeues & m_nIndexMask);

	// return the object pointer value:
	return *(m_ppObjects + nDequeueIndex);
}

// returns the distance between m_nDequeues and m_nEnqueues
// (the size of the actual queue contents):
template <class C>
uint32_t CircularQueue<C>::Size()
{
	if (m_nDequeues < m_nEnqueues)
	{
		return (m_nEnqueues - m_nDequeues);
	}
	else
	{
		return (m_nDequeues - m_nEnqueues);
	}
}
