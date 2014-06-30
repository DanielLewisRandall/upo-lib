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

// tests for library classes/code.


#include <iostream>

// NOTE:
//  including template class implementation files
//  to prevent compiler errors:
#include "../../upo-lib/List.h"
#include "../../upo-lib/List.cpp"
#include "../../upo-lib/Queue.h"
#include "../../upo-lib/Queue.cpp"
#include "../../upo-lib/Stack.h"
#include "../../upo-lib/Stack.cpp"
#include "../../upo-lib/SquareArray.h"
#include "../../upo-lib/SquareArray.cpp"

int g_tests = 0;
int g_passd = 0;

#define LE_STRING (const char*)pLE->m_pObject

// reports on a numeric test:
void reportNT(
	const char* fnm,
	uint32_t got,
	uint32_t exp)
{
	g_tests++;
	
	if (got == exp)
	{
		g_passd++;
		
		std::cout << "PASS: "<< (fnm ? fnm : "NULL") << " == " << exp << "\n";
	}
	else
	{
		std::cout << "FAIL: "<< (fnm ? fnm : "NULL") << " == " << got << "\n";
	}
}

// reports on an OBJECT test:
void report(
	const char* fnm,
	const char* got,
	const char* exp)
{
	g_tests++;
	
	const char* cGot = got;
	const char* cExp = exp;
	
	if (got == exp)
	{
		g_passd++;
		
		std::cout << "PASS: "<< (fnm ? fnm : "NULL") << " == " << (cExp ? cExp : "NULL") << "\n";
	}
	else
	{
		std::cout << "FAIL: "<< (fnm ? fnm : "NULL") << " == " << (cGot ? cGot : "NULL") << "\n";
	}
}

// reports on a list element test:
void reportLE(
  const char* fnm,
  ListElement<const char>* pLE,
	const char* exp)
{
	if (exp)
	{
		report(fnm, pLE->m_pObject, exp);
	}
	else
	{
		report(fnm, NULL, exp);
	}
}

int main(int argc, const char * argv[])
{
	static const char schars[]   = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const char alpha[]   = "ALPHA";
	static const char bravo[]   = "BRAVO";
	static const char charlie[] = "CHARLIE";
	static const char delta[]   = "DELTA";
	static const char echo[]    = "ECHO";
	static const char foxtrot[] = "FOXTROT";
	
	static const char getcount[] = "getCount()";

	std::cout << "Testing List:\n\n";
	
	static const char addhead[] = "AddHead()";
	static const char addtail[] = "AddTail()";
	static const char removehead[] = "RemoveHead()";
	static const char gethead[] = "getHead()";
	static const char gettail[] = "getTail()";
	
	List<const char> list;
	
	std::cout << "list should be empty:\n";
	
	reportNT(getcount, list.getCount(), 0);
	report(removehead, list.RemoveHead(), NULL);
	reportLE(gethead, list.getHead(), NULL);
	reportLE(gettail, list.getTail(), NULL);
	
	std::cout << "add some items:\n";
	
	reportLE(addhead, list.AddHead(alpha),   alpha);
	reportLE(addhead, list.AddHead(bravo),   bravo);
	reportLE(addhead, list.AddHead(charlie), charlie);
	reportLE(addtail, list.AddTail(delta),   delta);
	reportLE(addtail, list.AddTail(echo),    echo);
	reportLE(addtail, list.AddTail(foxtrot), foxtrot);
	
	std::cout << "list should have 6 elements:\n";
	
	reportNT(getcount, list.getCount(), 6);
	reportLE(gethead, list.getHead(), charlie);
	reportLE(gettail, list.getTail(), foxtrot);
	
	std::cout << "remove all items:\n";
	
	report(removehead, list.RemoveHead(), charlie);
	report(removehead, list.RemoveHead(), bravo);
	report(removehead, list.RemoveHead(), alpha);
	report(removehead, list.RemoveHead(), delta);
	report(removehead, list.RemoveHead(), echo);
	report(removehead, list.RemoveHead(), foxtrot);
	
	std::cout << "list should be empty (again):\n";
	
	reportNT(getcount, list.getCount(), 0);
	report(removehead, list.RemoveHead(), NULL);
	reportLE(gethead, list.getHead(), NULL);
	reportLE(gettail, list.getTail(), NULL);
	
	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "Testing Queue:\n\n";
	
	static const char enqueue[] = "Enqueue()";
	static const char dequeue[] = "Dequeue()";
	static const char getfront[] = "getFront()";
	static const char getback[] = "getBack()";
	
	Queue<const char> queue;
	
	std::cout << "queue should be empty:\n";
	
	reportNT(getcount, queue.getCount(), 0);
	report(dequeue, queue.Dequeue(), NULL);
	reportLE(getfront, queue.getFront(), NULL);
	reportLE(getback, queue.getBack(), NULL);
	
	std::cout << "enqueue some items:\n";
	
	reportLE(enqueue, queue.Enqueue(alpha),   alpha);
	reportLE(enqueue, queue.Enqueue(bravo),   bravo);
	reportLE(enqueue, queue.Enqueue(charlie), charlie);
	reportLE(enqueue, queue.Enqueue(delta),   delta);
	reportLE(enqueue, queue.Enqueue(echo),    echo);
	reportLE(enqueue, queue.Enqueue(foxtrot), foxtrot);
	
	std::cout << "queue should have 6 elements:\n";
	
	reportNT(getcount, queue.getCount(), 6);
	reportLE(getfront, queue.getFront(), alpha);
	reportLE(getback, queue.getBack(), foxtrot);
	
	std::cout << "dequeue all items:\n";
	
	report(dequeue, queue.Dequeue(), alpha);
	report(dequeue, queue.Dequeue(), bravo);
	report(dequeue, queue.Dequeue(), charlie);
	report(dequeue, queue.Dequeue(), delta);
	report(dequeue, queue.Dequeue(), echo);
	report(dequeue, queue.Dequeue(), foxtrot);
	
	std::cout << "queue should be empty (again):\n";
	
	reportNT(getcount, queue.getCount(), 0);
	report(dequeue, queue.Dequeue(), NULL);
	reportLE(getfront, queue.getFront(), NULL);
	reportLE(getback, queue.getBack(), NULL);
	
	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "Testing Stack:\n\n";
	
	Stack<const char> stack;
	
	static const char f_push[] = "Push()";
	static const char f_pop[] = "Pop()";
	static const char gettop[] = "getTop()";
	static const char getbottom[] = "getBottom()";
	
	std::cout << "stack should be empty:\n";
	
	reportNT(getcount, stack.getCount(), 0);
	report(f_pop, stack.Pop(), NULL);
	reportLE(gettop, stack.getTop(), NULL);
	reportLE(getbottom, stack.getBottom(), NULL);
	
	std::cout << "push some items:\n";
	
	reportLE(f_push, stack.Push(alpha),   alpha);
	reportLE(f_push, stack.Push(bravo),   bravo);
	reportLE(f_push, stack.Push(charlie), charlie);
	reportLE(f_push, stack.Push(delta),   delta);
	reportLE(f_push, stack.Push(echo),    echo);
	reportLE(f_push, stack.Push(foxtrot), foxtrot);
	
	std::cout << "stack should have 6 elements:\n";
	
	reportNT(getcount, stack.getCount(), 6);
	reportLE(gettop, stack.getTop(), foxtrot);
	reportLE(getbottom, stack.getBottom(), alpha);

	std::cout << "dequeue all items:\n";
	
	report(f_pop, stack.Pop(), foxtrot);
	report(f_pop, stack.Pop(), echo);
	report(f_pop, stack.Pop(), delta);
	report(f_pop, stack.Pop(), charlie);
	report(f_pop, stack.Pop(), bravo);
	report(f_pop, stack.Pop(), alpha);
	
	std::cout << "stack should be empty (again):\n";
	
	reportNT(getcount, stack.getCount(), 0);
	report(f_pop, stack.Pop(), NULL);
	reportLE(gettop, stack.getTop(), NULL);
	reportLE(getbottom, stack.getBottom(), NULL);
	
	std::cout << "\n";
	std::cout << "\n";
	
	for (int32_t size = 2; size <= 6; size++)
	{
		std::cout << "Testing SquareArray (size = " << size << "):\n\n";
		
		SquareArray<const char> squareArrayOne;
		SquareArray<const char> squareArrayTwo;
		
		squareArrayOne.Init(size);
		squareArrayTwo.Init(size);
		
		int32_t val = 0;
		
		for (int32_t row = 0; row < size; row++)
		{
				for (int32_t col = 0; col < size; col++)
				{
						squareArrayOne.Set(row, col, &schars[val]);
						squareArrayTwo.Set(row, col, &schars[val++]);
				}
		}
		
		for (int32_t row = 0; row < size; row++)
		{
				for (int32_t col = 0; col < size; col++)
				{
						const char* cellValue = squareArrayOne.Get(row, col);
						std::cout << *cellValue << " ";
				}
				
				std::cout << '\n';
		}
		
		std::cout << "\nrotated clockwise:\n\n";
		
		squareArrayOne.Rotate(CW);
		
		for (int32_t row = 0; row < size; row++)
		{
				for (int32_t col = 0; col < size; col++)
				{
						const char* cellValue = squareArrayOne.Get(row, col);
						std::cout << *cellValue << " ";
				}
				
				std::cout << '\n';
		}
		
		std::cout << "\nrotated counter-clockwise:\n\n";
		
		squareArrayOne.Rotate(CCW);
		
		for (int32_t row = 0; row < size; row++)
		{
				for (int32_t col = 0; col < size; col++)
				{
						const char* cellValue = squareArrayOne.Get(row, col);
						std::cout << *cellValue << " ";
				}
				
				std::cout << '\n';
		}

		g_tests++;
		
		int32_t matches = 0;
			
		for (int32_t row = 0; row < size; row++)
		{
				for (int32_t col = 0; col < size; col++)
				{
						matches +=
							(squareArrayOne.Get(row, col) == squareArrayTwo.Get(row, col)) ?
							1 : 0;
				}
		}
		
		if (matches == (size * size))
		{
				g_passd++;
				std::cout << "\nPASS: arrays match.\n\n";
		}
		else
		{
				std::cout << "\nFAIL: arrays do not match.\n\n";
		}
	}
	
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Tests:  "<< g_tests << "\n";
	std::cout << "Passed: "<< g_passd << "\n\n";
	
	return 0;
}

