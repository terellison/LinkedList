#include "Node.h"
template <typename T>
class LinkedList {
  private:
  Node<T>* head;
  public:
  Node<T>* getHead();
  void insert(Node<T>* nodeToInsert);
  bool find(T* data);
  LinkedList();
};