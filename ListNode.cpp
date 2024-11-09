/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/31/24
*   File: node.cpp
*   Purpose: Function definitions for listNode class for CSC 1310 105 Program 2
*/

#include "ListNode.h"
#include "InvItem.h"

template <typename T> ListNode<T>::ListNode(T* value) { this->value = value; }
template <typename T> ListNode<T>::~ListNode() { delete this->next; }

template <typename T> T* ListNode<T>::getValue() { return this->value; }
template <typename T> ListNode<T>* ListNode<T>::getNext() { return this->next; }

template <typename T> void ListNode<T>::setValue(T* value) { this->value = value; }
template <typename T> void ListNode<T>::setNext(ListNode<T>* newNode) { this->next = newNode; }

template ListNode<InvItem>::ListNode(InvItem* value);
template ListNode<InvItem>::~ListNode();

template InvItem* ListNode<InvItem>::getValue();
template ListNode<InvItem>* ListNode<InvItem>::getNext();

template void ListNode<InvItem>::setValue(InvItem* value);
template void ListNode<InvItem>::setNext(ListNode<InvItem>* newNode);