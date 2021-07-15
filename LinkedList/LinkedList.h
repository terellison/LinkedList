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
      return this->first->element;
    }

    // TODO: Add insertBefore() and insertAfter(), splice(), concatenate(), reverse(), toArray(), remove(), removeAll()
    // overload append to take in another list

    template <typename T>
    void append(T* element) {
        ++this->count;
        if(this->first == NULL) {
            this->first = new Node<T>;
            this->first->element = element;
            this->last = this->first;
            return;
        }
        Node<T>* newNode = new Node<T>;
        newNode->element = element;
        this->last->next = newNode;
        this->last = newNode;
    }


    T* getLast() {
        return this->last->element;
    }

    void print() {
        this->current = this->first;
        while(this->current != NULL) {
            std::cout << *this->current->element << std::endl;
            this->current = this->current->next;
        }
    }

    bool isEmpty() {
        return this->first == NULL;
    }

    /// <summary>
    /// Insert an element before the first occurrence of another element
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="before">Element to insert the new element before</param>
    /// <param name="element">New element to insert</param>
    template <typename T>
    void insertBefore(T* before, T* element) {
        Node<T>* newNode = new Node<T>;
        newNode->element = element;
        if(*this->first->element == *before) {
            newNode->next = this->first;
            this->first = newNode;
            return;
        }
        this->current = this->first->next;
        if(this->contains(*element)) { // NOTE: Relies on contains changing current as part of search
            newNode->next = this->current;
            this->current->next = newNode;
            ++this->count;
            return;
        }
        else {
            delete newNode;
            throw new NodeNotFoundException("Could not find element to insert new element before");
        }
    }

    // TODO: Write test for insertAfter
    /// <summary>
    /// Insert an element before the first occurence of another element
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="after">Element to insert the new element after</param>
    /// <param name="element">New element to insert</param>
    template <typename T>
    void insertAfter(T* after, T*element) {
        if(this->contains(*element)) {
            Node<T>* newNode = new Node<T>;
            newNode->element = element;
            newNode->next = this->current->next;
            this->current->next = newNode;
            return;
        }
        else {
            throw new NodeNotFoundException("Could not find element to insert new element after");
        }
    }

    int size() {
        return this->count;
    }

    /// <summary>
    /// Returns whether the list contains the specified element
    /// </summary>
    /// <typeparam name="T">Element to search for</typeparam>
    template <typename T>
    bool contains(T element) {
        this->current = this->first;
        while(this->current != NULL) {
            if(*this->current->element == element)
                return true;
            this->current = this->current->next;
        }
        return false;
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
            T* element = NULL;
            Node<T>* next = NULL;
         };
        
        int count;

        Node<T>* first;
        
        Node<T>* current;

        Node<T>* last;
};
#endif// !LinkedList_H
}
