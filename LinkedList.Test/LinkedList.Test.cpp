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
			for(int i = 0; i < 200; i++) {
				ptr = new int(i);
				this->linkedList->append(ptr);
			}
		}

		void Teardown() {
			delete this->linkedList;
		}
	public:
		TEST_METHOD(Test_Load) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Load();
			Assert::IsTrue(this->linkedList->size() == 200);
			Assert::IsTrue(*this->linkedList->getLast() == 199);
			Teardown();
		}
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
			testPtr = new int(testNum);
			this->linkedList->append(testPtr);
			Assert::IsFalse(this->linkedList->isEmpty());
			Teardown();
		}

		TEST_METHOD(Insert_Four_Before_Zero) {
			this->linkedList = new LinkedList::LinkedList<int>;
			int* ptr = 0;
			for(int i = 0; i < 4; i++) {
				ptr = new int(i);
				this->linkedList->append(ptr);
			}
			int before = 0;
			int* ptrTwo = new int(before);
			ptr = new int(4);
			linkedList->insertBefore(ptrTwo, ptr);
			Assert::IsTrue(*this->linkedList->getFirst() == *ptr);
			Teardown();
		}

		TEST_METHOD(Size_Correct_After_Append) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Load();
			Assert::IsTrue(this->linkedList->size() == 200);
			Teardown();
		}

	};
}
