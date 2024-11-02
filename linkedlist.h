/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/28/24
*   File: LinkedList.h
*   Purpose: Header for LinkedList Class for CSC 1310 105 Program 2
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ListNode.h"

using namespace std;

template <typename L>
class LinkedList
{
    private:
    
        ListNode<L>* HEAD;
        ListNode<L>* TAIL;

        int counter;

        // QUICKSORT HELPERS

        ListNode<L>* partition(ListNode<L>*, ListNode<L>*, bool);
        void quicksortRUN(ListNode<L>*, ListNode<L>*, bool);

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

        bool isEmpty();
        ListNode<L>* getHead();
        ListNode<L>* getTail();
        ListNode<L>* getItem(int);
        int getCounter();

        // SORTING
        
        void quickSort(bool upDown);

        // OPERATOR OVERLOADING

        friend ostream& operator<<(ostream& stream, const LinkedList<L>& list);



};


#endif