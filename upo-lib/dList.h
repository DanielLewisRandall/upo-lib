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

// NOTE: the classes in this file have not been unit tested, yet!

#ifndef __UPO_LIB__dList__
#define __UPO_LIB__dList__

#include "upo-lib.h"

class dListElement // represents a double-linked List Element
{
	friend class dList;
	
	private:
		dListElement* m_pNext; // pointer to the Next element
		dListElement* m_pPrev; // pointer to the Previous element

	public:
		OBJECT* m_pObject; // pointer to an Object
		
		dListElement(OBJECT* pObject); // Element constructor
		
		dListElement* getNext(); // get pointer to next element
		
		dListElement* getPrev(); // get pointer to previous element
};

class dList // represents a double-linked List
{
	private:
		uint32_t m_nCount;
		dListElement* m_pHead; // pointer to the Head element
		dListElement* m_pTail; // pointer to the Tail element
		
		// sets head/tail pointers when element added to empty list
		void newEnds(dListElement* pNewElement);

		// updates head/tail pointers when an element is removed
		void fixEnds(dListElement* pNewElement);

	public:
		uint32_t getCount(); // get count of elements
		
		dListElement* getHead(); // get pointer to the Head element
	
		dListElement* getTail();  // get pointer to the Tail element
		
		dList(); // dList constructor
		
		~dList(); // dList destructor
		
		dListElement* AddHead(OBJECT* pObject);
		
		dListElement* InsertBefore(dListElement* pElement, OBJECT* pObject);
		
		dListElement* InsertAfter(dListElement* pElement, OBJECT* pObject);
		
		dListElement* AddTail(OBJECT* pObject);

		OBJECT* RemoveHead();

		OBJECT* RemoveTail();

		OBJECT* Remove(dListElement* pElement);
};

#endif /* defined(__UPO_LIB__dList__) */
