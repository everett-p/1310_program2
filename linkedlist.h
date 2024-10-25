#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename L>
class List
{
    private:
        struct Node
        {
            L value;
            struct Node *next;
            Node(L val) : value(val), next(nullptr) {}
        };

        Node * head;

        //append function
        void append(L val)
        {
            Node* newNode = new Node(val);
            if (!head) 
            {
                head = newNode; // If the list is empty, make newNode the head
                return;
            }
            Node* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
            return;
        }

        //prepend function
        void prepend(L val)
        {
            Node* newNode = new Node(val);
            if (!head) 
            {
                head = newNode; // If the list is empty, make newNode the head
            }
            Node* temp = head;
            newNode->next = head;
            head = newNode
            return;
        }

        //insert function
        void insert(L val, int index)
        {
            Node* newNode = new Node(val);
            if (!head) 
            {
                head = newNode; // If the list is empty, make newNode the head
                return;
            }
            Node* temp = head;
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

        //get first item
        L getHead()
        {
            if (head == nullptr) 
            {
                cout << "List is empty." << endl;
                return;
            }
            return head->value;
        }

        //get last item
        L getBack()
        {
            if (head == nullptr) 
            {
                cout << "List is empty." << endl;
                return;
            }
            Node* temp = head;
            Node* temp2 = head;
            temp2 = temp2->next;

            while (temp2 != nullptr)
            {
                temp = temp->next;
                temp2 = temp2->next;
            }

            return temp->value;

        }

        //get particular item
        L getItem(int index)
        {
            if (head == nullptr) 
            {
                cout << "List is empty." << endl;
                return;
            }

            int test = 0;
            Node* temp = head;
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

        //remove particular item
        void deleteItem(int index)
        {
            int test = 0;
            Node* temp = head;
            Node* temp2 = head;
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

        //quicksort







    public:

        List() : head(nullptr) {} // Constructor

};


#endif