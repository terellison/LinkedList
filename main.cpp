#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int>* list = new LinkedList<int>;
	if(!list->Empty()) {
		throw;
	}
	int* ptr = 0;
	int testOne = 1;
	ptr = &testOne;
	list->append(ptr);
	int testTwo = 2;
	ptr = &testTwo;
	list->append(ptr);
	list->showAll();
	std::cout << "Destroying linked list..." << std::endl;
	list->~LinkedList();
	system("pause");
  return 0;
}