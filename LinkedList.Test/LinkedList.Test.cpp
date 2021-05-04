#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
		LinkedList::LinkedList<int>* linkedList;
	public:
		
		TEST_METHOD(Is_LinkedList_Empty)
		{
			this->linkedList = new LinkedList::LinkedList<int>;
			Assert::IsTrue(this->linkedList->Empty());
		}

		TEST_METHOD(LinkedList_Is_Not_Empty_After_Append) {
			this->linkedList = new LinkedList::LinkedList<int>;
			int* testPtr = 0;
			int testNum = 1;
			testPtr = &testNum;
			this->linkedList->append(testPtr);
			Assert::IsFalse(this->linkedList->Empty());
		}
	};
}
