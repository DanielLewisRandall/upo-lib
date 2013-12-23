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

#include "Tree.h"

TreeBranch::TreeBranch(OBJECT* pObject) : m_Branches()
{
	m_pObject = pObject;
}

TreeBranch::~TreeBranch()
{
	while (getBranchCount())
	{
		TreeBranch* pBranch = (TreeBranch*)RemoveBranch();
		
		if (pBranch)
		{
			delete pBranch;
		}
	}
}

// adds a branch to the tail of the branch list:
TreeBranch* TreeBranch::AddBranch(OBJECT* pObject)
{
	TreeBranch* pBranch = new TreeBranch(pObject); // create a new branch
	
	ListElement* pElement = m_Branches.AddTail(pBranch);
	
	return (pElement) ? (TreeBranch*)pElement->m_pObject : NULL;
}

// removes the head branch and returns its object pointer:
OBJECT* TreeBranch::RemoveBranch()
{
	return m_Branches.RemoveHead();
}

// get pointer to next branch:
ListElement* TreeBranch::getNextBranch(ListElement* pElement)
{
	return pElement->getNext();
}

// get count of child branches:
uint32_t TreeBranch::getBranchCount()
{
	return m_Branches.getCount();
}

TreeBranch* Tree::getTrunk()
{
	return m_pTrunk;
}

Tree::Tree(OBJECT* pObject)
{
	m_pTrunk = new TreeBranch(pObject);
}

Tree::~Tree()
{
	if (m_pTrunk)
	{
		delete m_pTrunk;
	}
}


