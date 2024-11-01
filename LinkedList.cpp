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
LinkedList<L>::~LinkedList() { delete HEAD; delete TAIL; }

// ADDING

template <typename L> // append function
void LinkedList<L>::append(L val)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (isEmpty()) 
    {
        HEAD = newNode; // If the list is empty, make newNode the head
    }
    else
    {
        ListNode<L>* temp = HEAD;
        while (temp->getNext() != NULL) 
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template <typename L> //prepend function
void LinkedList<L>::prepend(L val)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (isEmpty()) 
    {
        HEAD = newNode; // If the list is empty, make newNode the head
    } 
    else 
    {
        newNode->setNext(HEAD);
        HEAD = newNode
    }
}

template <typename L> //insert function
void LinkedList<L>::insert(L val, int index)
{
    ListNode<L>* newNode = new ListNode<L>(val);
    if (isEmpty())
    {
        HEAD = newNode; // If the list is empty, make newNode the head
    }
    else 
    {
        ListNode<L>* temp = HEAD;
        int test = 0;

        // Traverse to the node just before the desired index
        while (temp != NULL && test < index - 1) 
        {
            temp = temp->getNext();      // Move to the next node
            test++;         // Increment the current index
        }
        if (temp == NULL)
        {
            cout << "OUT OF BOUNDS \n INSERTING AT END INSTEAD" << endl;
        }
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }
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
    while (temp != NULL && test <= index) 
    {
        temp2 = temp;
        temp = temp->getNext();
        test++;         
    }
    if (temp == NULL)
    {
        cout << "OUT OF BOUNDS \n FAILED TO DELETE ITEM" << endl;
    }
    else
    {
        temp2->setNext(temp->getNext());
        temp->setNext(NULL);
        delete temp;
    }
}

// ACCESSING

template <typename L>
bool LinkedList<L>::isEmpty() { return HEAD == NULL; }

// If get*() function is called assume list is not empty. In driver, call isEmpty() before get*()

template <typename L> //get first item
L LinkedList<L>::getHead() { return HEAD->getData(); }

template <typename L> //get last item
L LinkedList<L>::getTail()
{ return TAIL->getData(); }

template <typename L> //get particular item
L LinkedList<L>::getItem(int index)
{
    int test = 0;
    ListNode<L>* temp = HEAD;
    while (temp != NULL && test <= index-1) 
    {
        temp = temp->getNext();
        test++;         
    }
    if (temp == NULL)
    {
        cout << "OUT OF BOUNDS \n GETTING END INSTEAD" << endl;
    }
    return temp->getData();
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
    while (temp != NULL)
    {
        int i = 1;
        cout << i <<":"<< endl;
        stream << temp->getData() << " "; // Output the data of each node
        temp = temp->iterate(); // Move to the next node
        i++;
    }
    return stream; // Return the stream
}