// =================================================================
//
// File: priority_queue.h
// Author: Ricardo Navarro Gómez - A01708825
// Date: 23/10/2022
//
// =================================================================

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"
#include "header.h"
#include "heap.h"

// =================================================================
// Definition of the Priority_queue class
// =================================================================
template <class T>
class Priority_queue: public Heap{
public:
    Priority_queue(uint);
    ~Priority_queue();
    bool empty() const;
    uint size() const;
    void push(T);
    T top();
    void pop();
};

// =================================================================
// Constructor. Initializes the maximum size of the heap and creates
// the array.
//
// @param sze, the maximum size of the heap.
// =================================================================
template <class T>
Priority_queue<T>::Priority_queue(uint sze){
    Heap(sze);
}

// =================================================================
// Destructor. Free used dynamic memory.
//
// =================================================================
template <class T>
Priority_queue<T>::~Priority_queue(){
    ~Heap(sze);
}

// =================================================================
// Returns if the heap is empty or not.
//
// @returns True is the amount of elements is 0 (empty). False,
//					otherwise.
// @complexity O(n)
// =================================================================
template <class T>
bool Priority_queue<T>::empty() const{
    return (nothing());
}

// =================================================================
// Returns the number of elements in the heap
//
// @returns the number of elements in the heap.
// @complexity O(n)
// =================================================================
template <class T>
uint Priority_queue<T>::size() const{
    return (dimension());
}

// =================================================================
// Add an element to the heap. It is placed, initially, as the
// rightmost blade. Afterwards, it is verified if he is less than
// the father. If that is the case, it is exchanged. This process is
// repeated until the correct position is reached.
//
// @param val, the element to be added.
// @throws Overflow, if the heap is full.
// @complexity O(log(n))
// =================================================================
template <class T>
void Priority_queue<T>::push(T){
    insert(T);
}

// =================================================================
// Returns the root of the tree.
// 
// @returns, the value that is in the root of the tree
// @complexity O(n)
// =================================================================
template <class T>
T Priority_queue<T>::top(){
    return (data[0]);
}

// =================================================================
// Remove the root of the tree. The rightmost sheet is placed as a
// temporary successor. The tree is rearranged using the pushDown
// method.
//
// @returns, in this case, the minimum element in the heap.
// @complexity O(log(n))
// =================================================================
template <class T>
void Priority_queue<T>::pop(){
    remove();
}
#endif /* PRIORITY_QUEUE_H */