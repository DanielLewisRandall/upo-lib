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

// NOTE:
//  always include template class implementation files
//  to prevent compiler errors:
#include "dList.h"
#include "dList.cpp"


template <class C>
class TreeBranch // represents a Tree Branch
{
	public:
		dList<TreeBranch<C>> m_Branches;

		C* m_pObject;

		TreeBranch(C* pObject);
		
		~TreeBranch();
		
		// utility for accessing list element as a TreeBranch pointer:
		static TreeBranch<C>* asBranch(dListElement<TreeBranch<C>>* pElement);
		
		// utility for creating a new branch for the branch list:
		static TreeBranch<C>* newBranch(C* pObject);
};


template <class C>
inline TreeBranch<C>* TreeBranch<C>::asBranch(
	dListElement<TreeBranch<C>>* pElement)
{
	return (pElement) ? pElement->m_pObject : NULL;
}

template <class C>
inline TreeBranch<C>* TreeBranch<C>::newBranch(C* pObject)
{
	return new TreeBranch<C>(pObject);
}

template <class D>
class Tree // represents a Tree
{
	private:
		TreeBranch<D>* m_pTrunk;
		
	public:
		TreeBranch<D>* getTrunk();
		
		Tree(D* pObject);
		
		~Tree();
};


#endif /* defined(__UPO_LIB__Tree__) */
