#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
		LinkedList::LinkedList<int>* linkedList;

		void Load() {
			for(int i = 0; i < 10; i++) {
				this->linkedList->append(new int(i));
			}
		}

		void Teardown() {
			delete this->linkedList;
		}
	public:
		TEST_METHOD(Test_Load) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Load();
			Assert::IsTrue(this->linkedList->size() == 10);
			Assert::IsTrue(this->linkedList->getLast() == 9);
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
			linkedList->insertBefore(*ptrTwo, ptr);
			Assert::IsTrue(this->linkedList->getFirst() == *ptr);
			Teardown();
		}

		TEST_METHOD(Size_Correct_After_Append) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Load();
			Assert::IsTrue(this->linkedList->size() == 10);
			Teardown();
		}

		TEST_METHOD(Contains_Element_After_Append) {
			this->linkedList = new LinkedList::LinkedList<int>;
			this->linkedList->append(new int(7));
			Assert::IsTrue(this->linkedList->contains(7));
			Teardown();
		}

		TEST_METHOD(Empty_List_Does_Not_Contain_Element) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Assert::IsFalse(this->linkedList->contains(7));
			Teardown();
		}

		TEST_METHOD(Does_Not_Contain_Element_Not_Inserted) {
			this->linkedList = new LinkedList::LinkedList<int>;
			Load();
			Assert::IsFalse(this->linkedList->contains(300));
			Teardown();
		
		}

		TEST_METHOD(Insert_Five_After_Eight) {
			this->linkedList = new LinkedList::LinkedList<int>;
			for(int i = 1; i < 4; i++) {
				this->linkedList->append(new int(i));
			}
			this->linkedList->append(new int(8));
			this->linkedList->insertAfter(8,new int(5));
			Assert::IsTrue(this->linkedList->size() == 5);
			Assert::IsTrue(this->linkedList->getLast() == 5);
		}

		TEST_METHOD(Reverse_List) {
			this->linkedList = new LinkedList::LinkedList<int>;
			for(int i = 1; i < 5; i++) {
				this->linkedList->append(new int(i));
			}
			LinkedList::LinkedList<int>* reversedList = this->linkedList->reverse();
			Assert::IsTrue(reversedList->getFirst() == 4);
			Teardown();
		}

		TEST_METHOD(To_Array) {
			const int SIZE = 5;
			this->linkedList = new LinkedList::LinkedList<int>;
			for(int i = 0; i < SIZE; i++) {
				this->linkedList->append(new int(i));
			}
			int* arr = this->linkedList->toArray();
			bool match = false;
			for(int i = 0; i < SIZE; i++) {
				match = (i == *(arr + i));
			}
			Assert::IsTrue(match);
			Teardown();
		}

		TEST_METHOD(Remove_Middle_Element) {
			this->linkedList = new LinkedList::LinkedList<int>;
			for(int i = 1; i < 4; i++) {
				this->linkedList->append(new int(i));
			}
			this->linkedList->remove(new int(2));
			Assert::IsTrue(this->linkedList->size() == 2);
		}
	};
}
