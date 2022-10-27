#pragma once
#ifndef Node_H
#define Node_H

template <typename T>
struct Node {
    T element;
    Node<T>* next = NULL;
};
#endif