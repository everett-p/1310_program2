/*
*   Author: Everett Patterson, Robert J. Morriss
*   Date: 10/31/24
*   File: LinkedList.cpp
*   Purpose: Function definitions for LinkedList class for CSC 1310 105 Program 2
*/

#include "LinkedList.h"

// CONSTRUCTOR

template <typename L>
LinkedList<L>::LinkedList() 
{
    this->HEAD = NULL;
    this->TAIL = NULL;
}

// DESTRUCTOR

template <typename L>
LinkedList<L>::~LinkedList() { delete HEAD; }

// ADDING

template <typename L> // append function
void LinkedList<L>::append(L val)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (HEAD == NULL) 
    {
        HEAD = newNode; // If the list is empty, make newNode the head
        return;
    }
    ListNode<L>* temp = HEAD;
    while (temp->next) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

template <typename L> //prepend function
void LinkedList<L>::prepend(L val)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (!HEAD) 
    {
        HEAD = newNode; // If the list is empty, make newNode the head
    }
    ListNode<L>* temp = HEAD;
    newNode->next = HEAD;
    HEAD = newNode
    return;
}

template <typename L> //insert function
void LinkedList<L>::insert(L val, int index)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (!HEAD) 
    {
        HEAD = newNode; // If the list is empty, make newNode the head
        return;
    }
    ListNode<L>* temp = HEAD;
    int test = 0;

    // Traverse to the node just before the desired index
    while (temp != nullptr && test < index - 1) 
    {
        temp = temp->next;      // Move to the next node
        test++;         // Increment the current index
    }
    if (temp == nullptr)
    {
        cout << "OUT OF BOUNDS \n INSERTING AT END INSTEAD" << endl;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// SWAPPING

template <typename L>
void LinkedList<L>::swap(L& a, L& b) 
{
    L temp = a; 
    a = b;      
    b = temp;  
}

// REMOVING

template <typename L> //remove particular item
void LinkedList<L>::deleteItem(int index)
{
    int test = 0;
    ListNode<L>* temp = HEAD;
    ListNode<L>* temp2 = HEAD;
    while (temp != nullptr && test <= index) 
    {
        temp2 = temp;
        temp = temp->next;
        test++;         
    }
    if (temp == nullptr)
    {
        cout << "OUT OF BOUNDS \n FAILED TO DELETE ITEM" << endl;
        return;
    }
    temp2->next = temp->next;
    delete temp;
}

// ACCESSING

template <typename L> //get first item
ListNode<L>* LinkedList<L>::getHead()
{
    if (HEAD == NULL) 
    {
        cout << "List is empty." << endl;
        return;
    }
    return HEAD;
}

template <typename L> //get last item
ListNode<L>* LinkedList<L>::getTail()
{
    if (HEAD == NULL) 
    {
        cout << "List is empty." << endl;
        return;
    }
    ListNode<L>* temp = HEAD;
    ListNode<L>* temp2 = HEAD;
    temp2 = temp2->next;

    while (temp2 != nullptr)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    return temp;

}

template <typename L> //get particular item
L LinkedList<L>::getItem(int index)
{
    if (HEAD == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }

    int test = 0;
    ListNode<L>* temp = HEAD;
    while (temp != nullptr && test <= index-1) 
    {
        temp = temp->next;
        test++;         
    }
    if (temp == nullptr)
    {
        cout << "OUT OF BOUNDS \n GETTING END INSTEAD" << endl;
    }

    return temp->value;
}

// SORTING

/*
QuickSort
*/

template <typename L> //partition
ListNode<L>* LinkedList<L>::partition(ListNode<L>* low, ListNode<L>* high, bool upDown)
{
    L pivot = high->getData();
    ListNode<L>* i = low;

    for (ListNode<L>* j = low ; j <= high ; j->iterate())
    {
        if ((upDown && j->getData() <= pivot) || (!upDown && j->getData() >= pivot)) 
        {
            if (i != j) 
            {
                swap(i->getData(), j->getData());
            }
        i = i->iterate();
        }
    }
    swap(i->getData(), high->getData());
    return i;
}

template <typename L> //quicksortRUN
void LinkedList<L>::quicksortRUN(ListNode<L>* low, ListNode<L>* high, bool upDown)
{
    if (high != nullptr && low != high && low != high->iterate()) 
    {
        ListNode<L>* X = partition(low, high, upDown); 
        quicksortRUN(low, X->iterate(), upDown); 
        quicksortRUN(X->iterate(), high, upDown); 
    }
}

template <typename L> //quicksort
void LinkedList<L>::quickSort(bool upDown)
{
    ListNode<L>* high = HEAD;
    while (high && high->iterate() != nullptr) 
    {
        high = high->iterate();
    }
    quicksortRUN(HEAD, high, upDown);
}

// OPERATOR OVERLOADING

template <typename L>
ostream& operator<<(ostream& stream, const LinkedList<L>& list) 
{
    ListNode<L>* temp = list.HEAD; // Start from the head
    while (temp != nullptr)
    {
        int i = 1;
        cout << i <<":"<< endl;
        stream << temp->getData() << " "; // Output the data of each node
        temp = temp->iterate(); // Move to the next node
        i++;
    }
    return stream; // Return the stream
}