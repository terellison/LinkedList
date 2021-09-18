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

    T getFirst() {
      return *this->first->element;
    }

    /* TODO: Add splice(), concatenate(), removeAll()
     * overload append to take in another list
     */

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


    T getLast() {
        return *this->last->element;
    }

    void print() {
        Node<T>* current = this->first;
        while(current != NULL) {
            std::cout << *current->element << std::endl;
            current = current->next;
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
    void insertBefore(T before, T* element) {
        Node<T>* newNode = new Node<T>;
        newNode->element = element;
        if(*this->first->element == before) {
            newNode->next = this->first;
            this->first = newNode;
            return;
        }
        Node<T>* current = this->find(before);
        if(current != NULL) {
            newNode->next = current;
            current->next = newNode;
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
    void insertAfter(T after, T*element) {
        if(this->contains(after)) {
            if(after == *this->last->element) {
                this->append(element);
                return;
            }
            Node<T>* newNode = new Node<T>;
            Node<T>* afterPtr = this->find(*element);
            newNode->element = element;
            newNode->next = afterPtr->next;
            afterPtr->next = newNode;
            ++this->count;
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

    /// <summary>
    /// Returns an array of type <typeparam name="T"></>
    /// </summary>
    /// <returns></returns>
    T* toArray() {
        T* result = new T[this->count];
        Node<T>* current = this->first;
        for(int i = 0; i < this->count; i++) {
            *(result + i) = *current->element;
            current = current->next;
        }
        return result;
    }

    LinkedList<T>* reverse() {
        LinkedList<T>* newList = new LinkedList<T>;
        this->_reverse();
        newList->operator=(this);
        this->_reverse();
        return newList;
    }

    /// <summary>
        /// Removes the first occurence of the specified element
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="element">Element to be removed</param>
        template <typename T>
        void remove(T* element) {
            if(!this->contains(*element)) {
                throw new NodeNotFoundException("Could not find the specified element");
            }
            Node<T>* current = this->first;
            Node<T>* next = current->next;
            Node<T>* previous = NULL;
            while(current != NULL) {
                if(*current->element == *element && current == this->first) {
                    this->first = next;
                    delete current;
                    break;
                }
                else if(*current->element == *element && current == this->last) {
                    this->last = next;
                    delete current;
                    break;
                }
                else if(*current->element == *element) {
                    previous->next = next;
                    delete current;
                    break;
                }
                previous = current;
                current = next;
                next = current->next;
            }
            --this->count;
        }

    void operator = (const LinkedList<T>* other) {
        this->~LinkedList();
        Node<T>* current = other->first;
        while(current != NULL) {
            this->append(current->element);
            current = current->next;
        }
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
        Node<T>* current = this->first;
        Node<T>* temp;
        while(current != NULL) {
            temp = current->next;
            delete current;
            --this->count;
            current = temp;
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

        // TODO: Get this down to a two pointer implementation
        void _reverse() {
            Node<T>* current = NULL;
            Node<T>* previous = NULL;
            Node<T>* next = NULL;
            previous = this->first;
            current = this->first->next;
            next = current->next;
            previous->next = NULL;
            current->next = previous;
            previous = current;
            current = next;
            while(current != NULL) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            this->last = this->first;
            this->first = previous;
        }

        /// <summary>
        /// Returns a pointer to the first instance of the specified element
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="element">Element to be found</param>
        /// <returns></returns>
        template <typename T>
        Node<T>* find(T& element) {
            if(*this->first->element == element) {
                return this->first;
            }
            Node<T>* current = this->first->next;
            bool found = false;
            while(current != NULL) {
                if(*current->element == element) {
                    return current;
                }
                current = current->next;
            }
            if(!found) {
                return NULL;
            }
        }
};
#endif// !LinkedList_H
}
