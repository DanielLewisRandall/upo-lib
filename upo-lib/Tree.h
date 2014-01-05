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

#ifndef __UPO_LIB__Tree__
#define __UPO_LIB__Tree__

#include "dList.h"

class TreeBranch // represents a Tree Branch
{
	public:
		dList m_Branches;

		OBJECT* m_pObject;

		TreeBranch(OBJECT* pObject);
		
		~TreeBranch();
		
		// utility for accessing the branch object in a dListElement:
		static TreeBranch* asBranch(dListElement* pElement);
		
		// utility for accessing an object pointer as a TreeBranch pointer:
		static TreeBranch* asBranch(OBJECT* pObject);
		
		// utility for creating a new branch for the branch list:
		static TreeBranch* newBranch(OBJECT* pObject);
};

inline TreeBranch* TreeBranch::asBranch(dListElement* pElement)
{
	return (pElement) ? asBranch(pElement->m_pObject) : NULL;
}

inline TreeBranch* TreeBranch::asBranch(OBJECT* pObject)
{
	return reinterpret_cast<TreeBranch*>(pObject);
}

inline TreeBranch* TreeBranch::newBranch(OBJECT* pObject)
{
	return new TreeBranch(pObject);
}

class Tree // represents a Tree
{
	private:
		TreeBranch* m_pTrunk;
		
	public:
		TreeBranch* getTrunk();
		
		Tree(OBJECT* pObject);
		
		~Tree();
};


#endif /* defined(__UPO_LIB__Tree__) */
