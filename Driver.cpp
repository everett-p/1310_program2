#include "LinkedList.h"
#include "invitem.h"
#include <iostream>

using namespace std;

int printMenu();
template <typename L> void addItem(LinkedList<L>*);
template <typename L>void editItem(LinkedList<L>*);
template <typename L>void deleteItems(LinkedList<L>*);
template <typename L>void iterate(LinkedList<L>*);

int main()
{
    LinkedList<InvItem>* list;
    int menuChoice = printMenu();
    do{
        switch(menuChoice)
        {
            case 1:
                cout << list;
                break;
            case 2:
                addItem(list);
                break;
            case 3:
                editItem(list);
                break;
            case 4:
                deleteItems(list);
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
void addItem(LinkedList<L>* list)
{
    int b = 0;
    cout << "Where would you like to add an Item?\n";
    cout << "\t1) Add at the front \n\t2) Add at the end \n\t3) Add in a particlular place \n\t4) Go back";
    cin >> b;

    switch (b)
    {
        case 1:
            list->prepend(list);
            break;
        case 2:
            list->append(list);
            break;
        case 3:
            int z;
            cout << "Where would you like to add the item? ";
            cin >> z;
            list->insert(list, z);
            break;
        case 4:
            return;
            break;
    }

};

template<typename L>
void editItem(LinkedList<L>* list)
{
    int  ID, weight, quantity;
    string name;
    float price;
    ListNode<L>* currentItem;
    currentItem = list->getHead();
    while (currentItem != list->getTail())
    {
        if(currentItem->getID() == list->getID())
        {
            cout << "Enter new item details.\n1. Item Name: ";
            cin >> name;
            currentItem->getData()->setName(name);
            cout << "2. Item ID: ";
            cin >> ID;
            currentItem->getData()->setID(ID);
            cout << "3. Item Price: ";
            cin >> price;
            currentItem->getData()->setPrice(price);
            cout << "3. Item Weight: ";
            cin >> weight;
            currentItem->getData()->setWeight(weight);
            cout << "5. Item Quantity: ";
            cin >> quantity;
            currentItem->getData()->setQuantity(quantity);
            cout << "6. Unit Price: ";
            currentItem->getData()->setUnitPrice();
        }
        else
            currentItem->getNext();
    }
};

template <typename L>
void deleteItems(LinkedList<L>* list)
{
    int itemNum;
    cout << "Which item would you like to delete? ";
    cin >> itemNum;
    list->deleteItem(itemNum);
};

template <typename L>
void iterate(LinkedList<L>* list)
{
    int choice;
    cout << "Which Direction Would You Like to Iterate?\n1. Previous Item\n2. Next Item";
    cin >> choice;
    while(choice<1 || choice>2)
    {
        cout << "Please Enter Either 1 or 2. ";
        cin >> choice;
    }
    ListNode<L>* iteratorPtr = list->getHead();
    ListNode<L>* tempPtr = iteratorPtr;

    while(iteratorPtr != list)
    {
        tempPtr = iteratorPtr;
        iteratorPtr->getNext();
    }
    if(choice == 1)
        iteratorPtr = tempPtr;
    else
        iteratorPtr->getNext();
};

