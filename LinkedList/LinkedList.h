#include "Exception.h"
#include <iostream>
#include <array>
#pragma once
namespace LinkedList {
#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList {
  

  public:

    LinkedList() {
        this->first = NULL;
        this->last = this->first;
        this->current = this->first;
        this->count = 0;
    }

    T* getFirst() {
      return this->first->item;
    }

    // TODO: Add insertBefore() and insertAfter(), splice(), concatenate(), reverse(), toArray(), remove(), removeAll()
    // overload append to take in another list

    template <typename T>
    void append(T* item) {
        ++this->count;
        if(this->first == NULL) {
            this->first = new Node<T>;
            this->first->item = item;
            this->last = this->first;
            return;
        }
        Node<T>* newNode = new Node<T>;
        newNode->item = item;
        this->last->next = newNode;
        this->last = newNode;
    }

    template <typename T>
    bool contains(T* item) {
      Node<T>* current = this->first;
      bool found = false;
      while(!found && current->next != nullptr) {
        if(current->item == item) {
          found = true;
        }
        current = current->next;
      }
      return found;
    }

    T* getLast() {
        return this->last->item;
    }

    void print() {
        this->current = this->first;
        while(this->current != NULL) {
            std::cout << *this->current->item << std::endl;
            this->current = this->current->next;
        }
    }

    bool isEmpty() {
        return this->first == NULL;
    }

    /// <summary>
    /// Insert an item before the first occurrence of another item
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="before">Item to insert the new item before</param>
    /// <param name="item">New item to insert</param>
    template <typename T>
    void insertBefore(T* before, T* item) {
        Node<T>* newNode = new Node<T>;
        newNode->item = item;
        if(*this->first->item == *before) {
            newNode->next = this->first;
            this->first = newNode;
            return;
        }
        bool found = false;
        this->current = this->first->next;
        Node<T>* previous = new Node<T>;
        while(!found && this->current->next != NULL) {
            if(*this->current->item == *item) {
                found = true;
                break;
            }
            previous = this->current;
            this->current = this->current->next;
        }
        if(found) {
            newNode->next = this->current;
            previous->next = newNode;
        }
        else {
            delete previous;
            throw new NodeNotFoundException("Could not find item to insert new item before");
        }
        delete previous;
    }

    int size() {
        return this->count;
    }

    virtual ~LinkedList(){
        this->current = this->first;
        Node<T>* temp;
        while(this->current != NULL) {
            temp = this->current->next;
            delete this->current;
            this->current = temp;
        }
    }

    private:
        
        template <typename T>
        struct Node {
            T* item;
            Node<T>* next = NULL;
         };
        
        int count;

        Node<T>* first;
        
        Node<T>* current;

        Node<T>* last;
};
#endif// !LinkedList_H
}
