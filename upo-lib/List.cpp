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

#include "List.h"

ListElement::ListElement(OBJECT* pObject) // Element constructor
{
	m_pObject = pObject;
	m_pNext = NULL;
}

ListElement* ListElement::getNext()
{
	return m_pNext;
}

uint32_t List::getCount()
{
	return m_nCount;
}

ListElement* List::getHead()
{
	return m_pHead;
}

ListElement* List::getTail()
{
	return m_pTail;
}

List::List() // List constructor
{
	m_nCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}

List::~List() // List destructor
{
	while (m_pHead) // while the Head element is not NULL,
	{
		RemoveHead(); // Remove elements
	}
}

ListElement* List::AddHead(OBJECT* pObject) // AddHead function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not Push
	}
	
	ListElement* pElement = new ListElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pHead) // if the Head element is not NULL,
		{
			pElement->m_pNext = m_pHead; // uptate the next pointer of the new element
		}
		
		m_pHead = pElement; // place the new element at the Head of the List
		
		if (!m_pTail) // if the Tail element is NULL,
		{
			m_pTail = m_pHead; // set the Tail element equal to the Head element
		}
	
		m_nCount++;
	}
	
	return pElement; // return the new element pointer
}

ListElement* List::AddTail(OBJECT* pObject) // AddTail function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not add tail
	}
	
	ListElement* pElement = new ListElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pTail) // if the Tail element is not NULL,
		{
			m_pTail->m_pNext = pElement; // uptate the next pointer of the Tail element
		}
		
		m_pTail = pElement; // place the new element at the Tail of the List
		
		if (!m_pHead) // if the Head element is NULL,
		{
			m_pHead = m_pTail; // set the Head element equal to the Tail element
		}
	
		m_nCount++;
	}
	
	return pElement; // return the new element pointer
}

OBJECT* List::RemoveHead() // RemoveHead function
{
	ListElement* pElement = m_pHead; // get the element at the Head of the List
	
	if (pElement) // if the element is not NULL,
	{
		m_pHead = m_pHead->m_pNext; // point the Head element at the next element
		
		if (!m_pHead) // if the Head element is NULL,
		{
			m_pTail = NULL; // set the Tail element to NULL
		}
		
		OBJECT* pObject = pElement->m_pObject; // get the object pointer from the element
		
		m_nCount--;
		
		delete pElement; // delete the element
		
		return pObject; // return the object pointer
	}
	else // if the element is NULL,
	{
		return NULL; // return NULL, as the List is empty
	}
}
