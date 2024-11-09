/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/28/24
*   File: ListNode.h
*   Purpose: Header file for listNode class for CSC 1310 105 Program 2
*/
#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <typename T>
class ListNode {
    private:
        T* value;
        ListNode<T>* next;
    public:
        ListNode(T*);
        ~ListNode();

        T* getValue();
        ListNode<T>* getNext();

        void setValue(T*);
        void setNext(ListNode<T>*);
};

#endif