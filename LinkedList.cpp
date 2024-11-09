/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/31/24
*   File: LinkedList.cpp
*   Purpose: Function definitions for LinkedList class for CSC 1310 105 Program 2
*/
#include "LinkedList.h"
#include "InvItem.h"
#include <iostream>

// CONSTRUCTOR / DESTRUCTOR

template <typename T> LinkedList<T>::LinkedList() { HEAD = NULL; TAIL = NULL; counter = 0; }
template <typename T> LinkedList<T>::~LinkedList() { delete HEAD; }

// ADDING

template <typename T>
void LinkedList<T>::append(T* value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    if (isEmpty()) {
        this->HEAD = newNode;
        this->TAIL = newNode;
    } else {
        this->TAIL->setNext(newNode);
        this->TAIL = newNode;
    }
    counter++;
}

template <typename T>
void LinkedList<T>::prepend(T* value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    if (isEmpty()) {
        this->HEAD = newNode;
        this->TAIL = newNode;
    } else {
        newNode->setNext(HEAD);
        this->HEAD = newNode;
    }
    counter++;
}

template <typename T>
void LinkedList<T>::insert(T* value, int index) {
    if (index > this->counter - 1) {
        append(value);
    } else {
        ListNode<T>* newNode = new ListNode<T>(value);
        ListNode<T>* traverse = HEAD;
        for (int i = 0; i < index - 1; i++) {
            traverse = traverse->getNext();
        }
        newNode->setNext(traverse->getNext());
        traverse->setNext(newNode);
    }
    counter++;
}

// REMOVING

template <typename T>
void LinkedList<T>::remove(int index) {
    ListNode<T>* outNode;
    ListNode<T>* prior;

    if (index >= this->counter) {
        cout << "INDEX OUT OF RANGE..." << endl;
    } else {
        outNode = HEAD;
        for (int i = 0; i < index; i++) {
            prior = outNode;
            outNode = outNode->getNext();
        }
        if (prior == NULL) {
            HEAD = outNode->getNext();
            outNode->setNext(NULL);
        } else {
            prior->setNext(outNode->getNext());
            outNode->setNext(NULL);
        }
        delete outNode;
    }
    this->counter--;
}

// ACCESSING

template <typename T> bool LinkedList<T>::isEmpty() { return HEAD == NULL; }
template <typename T> int LinkedList<T>::getCounter() { return this->counter; }
template <typename T> ListNode<T>* LinkedList<T>::getHead() { return HEAD; }
template <typename T> ListNode<T>* LinkedList<T>::getTail() { return TAIL; }
template <typename T> ListNode<T>* LinkedList<T>::getItem(int index) {
    ListNode<T>* outNode = HEAD;

    if (index >= this->counter) {
        cout << "INDEX OUT OF RANGE...\nRETURNING HEAD NODE" << endl;
        return outNode;
    } else {
        for (int i = 0; i < index; i++) {
            outNode = outNode->getNext();
        }
        return outNode;
    }
}

// QUICKSORT

template <typename T>
ListNode<T>* LinkedList<T>::quickSort(ListNode<T>* head) {
    ListNode<T>* tail = TAIL;

    quickSortHelper(head, tail);
    return head;
}

// PRIVATE QUICKSORT HELPERS

template <typename T>
void LinkedList<T>::quickSortHelper(ListNode<T>* head, ListNode<T>* tail) {
    if (head == NULL || head == TAIL) {
        return;
    }

    ListNode<T>* pivot = partition(head, tail);

    quickSortHelper(head, pivot);

    quickSortHelper(pivot->getNext(), tail);
}

template <typename T>
ListNode<T>* LinkedList<T>::partition(ListNode<T>* head, ListNode<T>* tail) {
    ListNode<T>* pivot = head;
    
    ListNode<T>* pre = head;
    ListNode<T>* curr = head;

    while (curr != tail->getNext()) {
        if (curr->getValue() < pivot->getValue()) {
            swap(*curr->getValue(), *pre->getNext()->getValue());

            pre = pre->getNext();
        }

        curr = curr->getNext();
    }

    swap(*pivot->getValue(), *pre->getValue());

    return pre;
}

template <typename T>
void LinkedList<T>::swap(T& item1, T& item2) {
    T temp = item1;
    item1 = item2;
    item2 = temp;
}

template LinkedList<InvItem>::LinkedList();
template LinkedList<InvItem>::~LinkedList();

template void LinkedList<InvItem>::append(InvItem*);
template void LinkedList<InvItem>::prepend(InvItem*);
template void LinkedList<InvItem>::insert(InvItem*, int);

template void LinkedList<InvItem>::remove(int);

template bool LinkedList<InvItem>::isEmpty();
template int LinkedList<InvItem>::getCounter();
template ListNode<InvItem>* LinkedList<InvItem>::getHead();
template ListNode<InvItem>* LinkedList<InvItem>::getTail();
template ListNode<InvItem>* LinkedList<InvItem>::getItem(int index);

template ListNode<InvItem>* LinkedList<InvItem>::quickSort(ListNode<InvItem>*);
template void LinkedList<InvItem>::quickSortHelper(ListNode<InvItem>*, ListNode<InvItem>*);
template ListNode<InvItem>* LinkedList<InvItem>::partition(ListNode<InvItem>*, ListNode<InvItem>*);
template void LinkedList<InvItem>::swap(InvItem&, InvItem&);