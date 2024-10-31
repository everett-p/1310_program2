/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/31/24
*   File: LinkedList.cpp
*   Purpose: Function definitions for LinkedList class for CSC 1310 105 Program 2
*/

#include "LinkedList.h"


// PRIVATE

template <typename L>
void LinkedList<L>::append(L val)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (!head) 
    {
        head = newNode; // If the list is empty, make newNode the head
        return;
    }
    ListNode<L>* temp = head;
    while (temp->next) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}