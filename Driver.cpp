#include "LinkedList.h"
#include "invitem.h"
#include <iostream>

using namespace std;

int printMenu();
void addItem();
void editItem();
void deleteItem();
void iterate();
void print();

int main()
{
    LinkedList<InvItem> list;
    ListNode<InvItem> listPointer = list.getHead();
    int menuChoice = printMenu();
    do{
        switch(menuChoice)
        {
            case 1:
                print();
                break;
            case 2:
                addItem();
                break;
            case 3:
                editItem();
                break;
            case 4:
                deleteItem();
                break;
        }
    }while(menuChoice != 5);

    return 0;
}

int printMenu()
{
    int a = 0;
    cout << "*** WHAT WOULD YOU LIKE TO DO? ***\n";
    cout << "\t1) PRINT Full INVENTORY \n\t2) ADD NEW ITEM \n\t3) EDIT ITEM \n\t4) DELETE ITEM \n\t5) EXIT SYSTEM\n";
    cin >> a;
    while(a<1 || a>5)
    {
        cout << "Please Enter a Number 1-5. ";
        cin >> a;
    }
    return a;  
};

template<typename L>
void addItem(LinkedList<L> val)
{
    int b = 0;
    cout << "Where would you like to add an Item?\n";
    cout << "\t1) Add at the front \n\t2) Add at the end \n\t3) Add in a particlular place \n\t4) Go back";
    cin >> b;

    switch (b)
    {
        case 1:
            LinkedList<L>::prepend(val);
            break;
        case 2:
            LinkedList<L>::append(val);
            break;
        case 3:
            int z;
            cout << "Where would you like to add the item? ";
            cin >> z;
            LinkedList<L>::insert(val, z);
            break;
        case 4:
            return;
            break;
        

    }

};

template<typename L>
void editItem(LinkedList<L> val)
{
    cout << endl;
};

void deleteItem()
{

};

void iterate()
{
    int choice;
    cout << "Which Direction Would You Like to Iterate?\n1. Previous Item\n2. Next Item";
    cin >> choice;
    while(choice<1 || choice>2)
    {
        cout << "Please Enter Either 1 or 2. ";
        cin >> choice;
    }

};

template<typename L>
void print()
{
    ListNode<L>* nodePtr = LinkedList<L>::getHead();
    while(nodePtr != NULL)
    {
        cout << "Item Name:\t" << LinkedList<L>::getName() << endl;
        cout << "Item ID:\t" << LinkedList<L>::getID() << endl;
        cout << "Item Price:\t$" << LinkedList<L>::getPrice() << endl;
        cout << "Item weight:\t" << LinkedList<L>::getWeight() << "oz." << endl;
        cout << "Item Unit Price:\t$" << LinkedList<L>::getUnitPrice() << endl;
        cout << "Item Quantity:\t" << LinkedList<L>::getQuantity() << endl;
        nodePtr = nodePtr->next;
    }

};