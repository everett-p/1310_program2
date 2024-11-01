/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/28/24
*   File: LinkedList.h
*   Purpose: Header for LinkedList Class for CSC 1310 105 Program 2
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename L>
class LinkedList
{
    private:
    
        ListNode<L>* HEAD;
        ListNode<L>* TAIL;

    public:

        // CONSTRUCTOR

        LinkedList();

        // DESTRUCTOR

        ~LinkedList();

        // ADDING

        void append(L);
        void prepend(L);
        void insert(L, int);

        // SWAPPING

        void swap(L&, L&);

        // REMOVING

        void deleteItem(int);

        // ACCESSING

        ListNode<L>* getHead();
        ListNode<L>* getTail();
        L getItem(int);

        // SORTING

        /*
        QuickSort
        */
        ListNode<L>* partition(ListNode<L>*, ListNode<L>*, bool);
        void quicksortRUN(ListNode<L>*, ListNode<L>*, bool);
        void quickSort(bool upDown);

        // OPERATOR OVERLOADING

        friend ostream& operator<<(ostream& stream, const List<L>& list);



};


#endif