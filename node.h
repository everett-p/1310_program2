/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/28/24
*   File: node.h
*   Purpose: Header file for listNode class for CSC 1310 105 Program 2
*/


#ifndef NODE_H
#define NODE_H

template <typename L>
class ListNode
{
    private: 
        L value;
        ListNode<L> *next;
    public:

        // CONSTRUCTOR / DESTRUCTOR
        ListNode(L);
        ~ListNode();

        // GETTERS

        L getData();
        ListNode<L>* getNext();

        // SETTERS

        void setData(L val);
        void setNext(ListNode<L>* newNode);
};

#endif