#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList<int>* list = new LinkedList<int>();
  cout << list->getHead()->data << endl;
  Node<int>* newNode = new Node<int>();
  *newNode->data = 1;
  list->insert(newNode);
  newNode = list->getHead()->next;
  cout << newNode->data;
  
  return 0;
}