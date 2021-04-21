#include "LinkedList.h"
template <typename T>
LinkedList<T>::LinkedList() {
  this->head = new Node<T>();
  this->head->data = new T;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() {
  return this->head;
}

template <typename T>
void LinkedList<T>::insert(Node<T>* nodeToInsert) {
  Node<T>* currentNode = this->head;
  while(currentNode->next != nullptr) {
    currentNode = currentNode->next;
  }
  currentNode->next = nodeToInsert;
}

template <typename T>
bool LinkedList<T>::find(T* data) {
  Node<T>* current = this->head;
  bool found = false;
  while(!found && current->next != nullptr) {
    if(current->data == data) {
      found = true;
    }
    current = current->next;
  }
  return found;
}

