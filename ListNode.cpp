/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/31/24
*   File: node.cpp
*   Purpose: Function definitions for listNode class for CSC 1310 105 Program 2
*/

#include "ListNode.h"

// CONSTRUCTOR / DESTRUCTOR

template <typename L>
ListNode<L>::ListNode(L val) {
    this->value = val;
    this->next = NULL;
} 
template <typename L> ListNode<L>::~ListNode() { delete this->next; } // chains deletes for easy clean-up; REMOVE FROM LIST BEFORE DELETE IF NOT CLEARING LIST

// GETTERS

template <typename L> L ListNode<L>::getData() { return this->value; }
template <typename L> ListNode<L>* ListNode<L>::getNext() { return this->next; }

// SETTERS

template <typename L> void ListNode<L>::setData(L val) { this->value = val; }
template <typename L> void ListNode<L>::setNext(ListNode<L>* newNode) { this->next = newNode; } 