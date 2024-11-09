/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/28/24
*   File: LinkedList.h
*   Purpose: Header for LinkedList Class for CSC 1310 105 Program 2
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include <iostream>

template <typename T>
class LinkedList {
    private:
        ListNode<T>* HEAD;
        ListNode<T>* TAIL;

        int counter;

        void quickSortHelper(ListNode<T>*, ListNode<T>*);
        ListNode<T>* partition(ListNode<T>*, ListNode<T>*);
        void swap(T&, T&);
    public:
        LinkedList();
        ~LinkedList();

        void append(T*);
        void prepend(T*);
        void insert(T*, int);

        void remove(int);

        bool isEmpty();
        ListNode<T>* getHead();
        ListNode<T>* getTail();
        ListNode<T>* getItem(int);
        int getCounter();

        ListNode<T>* quickSort(ListNode<T>*);

        friend ostream& operator<<(ostream& output, const LinkedList<T>& list)  {
            ListNode<T>* traverse = list.HEAD;
            output << "\nPrinting all " << list.counter << " Items in list" << endl;
            while (traverse != NULL) {
                output << "\n" << *traverse << endl;
                traverse = traverse->getNext();
            }
            return output;
        }
};

#endif