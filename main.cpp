#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int>* list = new LinkedList<int>;
	if(!list->Empty()) {
		throw;
	}
	int* ptrOne = 0; 
	int* ptrTwo = 0;
	int* ptrThree = 0;
	int testOne = 1;
	ptrOne = &testOne;
	list->append(ptrOne);
	int testTwo = 2;
	ptrOne = &testTwo;
	list->append(ptrOne);
	int testThree = 3;
	ptrOne = &testOne;
	ptrTwo = &testTwo;
	ptrThree = &testThree;
	list->insert(ptrOne,ptrTwo,ptrThree);
	list->showAll();
	std::cout << "Destroying linked list..." << std::endl;
	list->~LinkedList();
	system("pause");
  return 0;
}