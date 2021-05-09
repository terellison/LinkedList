#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
		LinkedList::LinkedList<int>* linkedList;

		void Load() {
			int* ptr = 0;
			for(int i = 1; i < 200; i++) {
				ptr = &i;
				this->linkedList->append(ptr);
			}
		}

		void Teardown() {
			delete this->linkedList;
		}
	public:
		
		TEST_METHOD(Is_LinkedList_Empty)
		{
			this->linkedList = new LinkedList::LinkedList<int>;
			Assert::IsTrue(this->linkedList->isEmpty());
			Teardown();
		}

		TEST_METHOD(LinkedList_Is_Not_Empty_After_Append) {
			this->linkedList = new LinkedList::LinkedList<int>;
			int* testPtr = 0;
			int testNum = 1;
			testPtr = &testNum;
			this->linkedList->append(testPtr);
			Assert::IsFalse(this->linkedList->isEmpty());
			Teardown();
		}


	};
}
