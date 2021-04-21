#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList {
  

  public:

    LinkedList() {}

    template <typename T>
    T* getFirst() {
      return this->head->data;
    }

    template <typename T>
    void insert(Node<T>* nodeToInsert) {
      Node<T>* currentNode = this->first;
      while(currentNode->next != nullptr) {
        currentNode = currentNode->next;
      }
      currentNode->next = nodeToInsert;
    }

    template <typename T>
    bool find(T* data) {
      Node<T>* current = this->first;
      bool found = false;
      while(!found && current->next != nullptr) {
        if(current->data == data) {
          found = true;
        }
        current = current->next;
      }
      return found;
    }

    virtual ~LinkedList(){}

    private:
        
        template <typename T>
        struct Node {
            T* data;
            Node<T>* next = nullptr;
         };

        Node<T>* first;
        
        Node<T>* current;
};
#endif// !LinkedList_H
