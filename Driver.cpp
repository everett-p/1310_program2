#include "LinkedList.h"
#include "invitem.h"
#include <iostream>

using namespace std;

int printMenu();
template <typename L> void addItem(LinkedList<L>*);
template <typename L> void editItem(LinkedList<L>*);
template <typename L> void deleteItems(LinkedList<L>*);
template <typename L> void iterate(LinkedList<L>*);

int main()
{
    LinkedList<InvItem>* list;
    int menuChoice;
    do{
        menuChoice = printMenu();
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
    string name;
    float price;
    int weight, quantity, id;
    InvItem* newItem;


    cout << "Where would you like to add the Item?\n";
    cout << "\t1) Add at the front \n\t2) Add at the end \n\t3) Add in a particlular place \n\t4) Go back";
    cin >> b;

    if (b != 4) {
        cout << "\nWhat's the name of the Item?\nNAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "\nHow much is the item?\nPRICE: $";
        cin >> price;
        cout << "\nHow much does the item weigh?\nWEIGHT oz.: ";
        cin >> weight;
        cout << "\nHow many are in stock?\nQUANTITY: ";
        cin >> quantity;
        cout << "\nWhat's the items Bin ID?\nID: ";
        cin >> id;

        newItem = new InvItem(name, price, weight, quantity, id);
    }

    switch (b)
    {
        case 1:
            list->prepend(newItem);
            break;
        case 2:
            list->append(newItem);
            break;
        case 3:
            int z;
            cout << "Where would you like to add the item? (0 - " << list->getCounter() << ")" << endl;
            cin >> z;
            list->insert(newItem, z);
            break;
        case 4:
            return;
            break;
    }

};

template<typename L>
void editItem(LinkedList<L>* list)
{
    string n;
    float p;
    int w, q, id;
    int choice;
    InvItem* edit;

    cout << "Which Item would you like to modify?" << endl;
    for (int i = 0; i < list->getCounter(); i++) {
        cout << i << ". " <<list->getItem(i)->getData()->getName() << endl;
    }
    do {
        cout << "CHOICE ";
        cin >> choice;
    } while (choice < 1 || choice >= list->getCounter());
    edit = list->getItem(choice)->getData();

    while (choice != 6) {
        cout << "NOW EDITING: " << edit->getName();
        cout << "CURRENT:" << endl;
        cout << edit << endl;
        cout << "What would you like to chance?" << endl;
        cout << "1. Name\n2. Price\n3. Weight\n4. Quantity\n5. ID\n6. Exit" << endl;
        do {
            cout << "CHOICE: ";
            cin >> choice;
        } while (choice < 1 || choice > 6);

        switch (choice) {
            case 1:
                cout << "What's the new Name?\nNAME: ";
                cin.ignore();
                getline(cin, n);
                edit->setName(n);
                break;
            case 2:
                cout << "What's the new Price?\nPRICE: ";
                cin >> p;
                edit->setPrice(p);
                break;
            case 3:
                cout << "What's the new Weight?\nWEIGHT: ";
                cin >> w;
                edit->setWeight(w);
                break;
            case 4:
                cout << "What's the new Quantity?\nQUANTITY: ";
                cin >> q;
                edit->setQuantity(q);
                break;
            case 5:
                cout << "What's the new Bin ID?\nID: ";
                cin >> id;
                edit->setID(id);
                break;
            default:
                break;
        }
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

