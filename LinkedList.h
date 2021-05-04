#pragma once
#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList {
  

  public:

    LinkedList() {
        this->first = NULL;
        this->last = this->first;
        this->current = this->first;
    }

    template <typename T>
    T* getFirst() {
      return this->first->data;
    }

    template <typename T>
    void insert(T* beforeValue, T* afterValue, T* dataToInsert) {
        if(this->first == NULL) {
            throw new exception("List is empty, use append()");
        }
        this->current = this->first;
        bool foundBefore = false;
        bool foundAfter = false;
        Node<T>* before;
        Node<T>* after;
        while(!foundBefore || !foundAfter && this->current != NULL) {
            if(this->current->data == beforeValue) {
                before = this->current;
                foundBefore = true;
            }
            if(this->current->data == afterValue) {
                after = this->current;
                foundAfter = true;
            }
          this->current = this->current->next;  
        }
        if(foundBefore && foundAfter) {
            Node<T>* newNode = new Node<T>;
            newNode->data = dataToInsert;
            before->next = newNode;
            newNode->next = after;
        }
        else {
            throw new exception("Could not find either beforeValue or afterValue to insert new data between");
        }
    }

    template <typename T>
    void append(T* data) {
        if(this->first == NULL) {
            this->first = new Node<T>;
            this->first->data = data;
            this->last = this->first;
            return;
        }
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        this->last->next = newNode;
        this->last = newNode;
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

    template <typename T>
    T* getLast() {
        if(this->last->next == null) {
            return this->last->data;
        }
    }

    void showAll() {
        this->current = this->first;
        while(this->current != NULL) {
            std::cout << *this->current->data << std::endl;
            this->current = this->current->next;
        }
    }

    bool Empty() {
        return this->first == NULL;
    }

    virtual ~LinkedList(){
        this->current = this->first;
        Node<T>* temp;
        while(this->current != NULL) {
            temp = this->current->next;
            delete(this->current);
            this->current = temp;
        }
    }

    private:
        
        template <typename T>
        struct Node {
            T* data;
            Node<T>* next = NULL;
         };

        Node<T>* first;
        
        Node<T>* current;

        Node<T>* last;
};
#endif// !LinkedList_H
