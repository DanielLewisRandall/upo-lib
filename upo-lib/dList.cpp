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

#include "dList.h"

dListElement::dListElement(OBJECT* pObject) // Element constructor
{
	m_pObject = pObject;
	m_pNext = NULL;
	m_pPrev = NULL;
}

dListElement* dListElement::getNext()
{
	return m_pNext;
}

dListElement* dListElement::getPrev()
{
	return m_pPrev;
}

// sets head/tail pointers when element added to empty list
void dList::newEnds(dListElement* pNewElement)
{
	if (!m_pHead) // if the Head element is NULL,
	{
		m_pHead = pNewElement; // set the Head element equal to the new element
	}
	
	if (!m_pTail) // if the Tail element is NULL,
	{
		m_pTail = pNewElement; // set the Tail element equal to the new element
	}
}

// updates head/tail pointers when an element is removed
void dList::fixEnds(dListElement* pRemElement)
{
	if (pRemElement) // if the removed element is NULL,
	{
		if (pRemElement == m_pHead) // if the removed element was the head element,
		{
			// the next element is now the head element
			m_pHead = pRemElement->m_pNext;
		}
		
		if (pRemElement == m_pTail) // if the removed element was the tail element,
		{
			// the prev element is now the tail element
			m_pTail = pRemElement->m_pPrev;
		}
	}
	
	if (!m_pHead) // if the Head element is NULL,
	{
		m_pTail = NULL; // set the Tail element to NULL
	}
	
	if (!m_pTail) // if the Tail element is NULL,
	{
		m_pHead = NULL; // set the Head element to NULL
	}
}

uint32_t dList::getCount()
{
	return m_nCount;
}

dListElement* dList::getHead()
{
	return m_pHead;
}

dListElement* dList::getTail()
{
	return m_pTail;
}

dList::dList() // dList constructor
{
	m_nCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}

dList::~dList() // dList destructor
{
	while (m_pHead) // while the Head element is not NULL,
	{
		RemoveHead(); // Remove elements
	}
}

dListElement* dList::AddHead(OBJECT* pObject)
{
	return InsertBefore(m_pHead, pObject);
}

dListElement* dList::InsertBefore(dListElement* pElement, OBJECT* pObject)
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not insert
	}
	
	dListElement* pNewElement = new dListElement(pObject); // create a new element
	
	if (pNewElement) // if the new element was allocated,
	{
		if (pElement) // if the ref element is not NULL,
		{
			pNewElement->m_pNext = pElement; // uptate the next of the new element
			pElement->m_pPrev = pNewElement; // uptate the prev of the ref element
		
			if (pElement == m_pHead) // if the ref element was the head element,
			{
				m_pHead = pNewElement; // the new element is now the head element
			}
		}
		
		newEnds(pNewElement); // set head/tail pointers if NULL

		m_nCount++;
	}
	
	return pElement; // return the new element pointer
}

dListElement* dList::InsertAfter(dListElement* pElement, void* pObject)
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not insert
	}
	
	dListElement* pNewElement = new dListElement(pObject); // create a new element
	
	if (pNewElement) // if the new element was allocated,
	{
		if (pElement) // if the ref element is not NULL,
		{
			pElement->m_pNext = pNewElement; // uptate the next of the ref element
			pNewElement->m_pPrev = pElement; // uptate the prev of the new element
		
			if (pElement == m_pTail) // if the ref element was the tail element,
			{
				m_pTail = pNewElement; // the new element is now the tail element
			}
		}
		
		newEnds(pNewElement); // set head/tail pointers if NULL

		m_nCount++;
	}
	
	return pElement; // return the new element pointer
}

dListElement* dList::AddTail(OBJECT* pObject) // AddTail function
{
	return InsertAfter(m_pTail, pObject);
}

OBJECT* dList::RemoveHead()
{
	return Remove(m_pHead);
}

OBJECT* dList::RemoveTail()
{
	return Remove(m_pTail);
}

OBJECT* dList::Remove(dListElement* pElement)
{
	if (pElement) // if the element is not NULL,
	{
		if (pElement->m_pPrev) // if the prev element is not NULL,
		{
			// point next of prev at next element:
			pElement->m_pPrev->m_pNext = pElement->m_pNext;
		}
		
		if (pElement->m_pNext) // if the next element is not NULL,
		{
			// point prev of next at prev element:
			pElement->m_pNext->m_pPrev = pElement->m_pPrev;
		}
		
		// update head/tail pointers (if necessary):
		fixEnds(pElement);
		
		// get the object pointer from the element
		OBJECT* pObject = pElement->m_pObject;
		
		m_nCount--;
		
		delete pElement; // delete the element
		
		return pObject; // return the object pointer
	}
	else // if the element is NULL,
	{
		return NULL; // return NULL, as the List is empty
	}
}
