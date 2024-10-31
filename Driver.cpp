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
    List<InvItem> list;



    return 0;
}

int printMenu()
{
    int a = 0;
    cout << "*** WHAT WOULD YOU LIKE TO DO? ***\n";
    cout << "\t1) PRINT Full INVENTORY \n\t2) ADD NEW ITEM \n\t3) EDIT ITEM \n\t4) DELETE ITEM \n\t5) EXIT SYSTEM\n";
    cin >> a;
    return a;  
};

void addItem()
{
    int b = 0;
    cout << "Where would you like to add an Item?\n";
    cout << "\t1) Add at the front \n\t2) Add at the end \n\t3) Add in a particlular place \n\t4) Go back";
    cin >> b;

    switch (b)
    {
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            return;
            break;
        

    }

};

void editItem()
{

};

void editItem()
{

};

void deleteItem()
{

};

void iterate()
{

};