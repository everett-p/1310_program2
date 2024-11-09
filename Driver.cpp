/*
*   Author: Robert J. Morriss
*   Date: 10/31/24
*   File: Driver.cpp
*   Purpose: Driver for 1310 105 Program 2
*/

#include "LinkedList.h"
#include "InvItem.h"
#include <fstream>

void mainMenu();
void addMenu(LinkedList<InvItem>&);
void removeMenu(LinkedList<InvItem>&);
void printMenu(LinkedList<InvItem>);
int enterChoice(int, int);

 int main() {
    LinkedList<InvItem> itemList;

    int choice;

    while (choice != 5) {
        mainMenu();
        choice = enterChoice(1, 5);

        switch(choice) {
            case 1:
                addMenu(itemList);
                break;
            case 2:
                removeMenu(itemList);
                break;
            case 3:
                itemList.quickSort(itemList.getHead());
                break;
            case 4:
                printMenu(itemList);
                break;
            default:
                break;
        }
    }
    cout << "\nGOODBYE!!" << endl;
    return 0;
}

void mainMenu() {
    cout << "****** MAIN MENU ******" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Sort List" << endl;
    cout << "4. Print" << endl;
    cout << "5. Exit Program" << endl;
}

void addMenu(LinkedList<InvItem>& itemList) {
    int choice, w, q, id;
    string n;
    float p;

    cout << "****** ADD MENU ******" << endl;
    cout << "1. Append New Item" << endl;
    cout << "2. Prepend New Item" << endl;
    cout << "3. Insert New Item" << endl;
    cout << "4. Cancel" << endl; 

    choice = enterChoice(1, 4);

    if (choice == 4) return; 

    cout << "What's the name of the new item?\nNAME: ";
    cin.ignore();
    getline(cin, n);

    cout << "What's the price of the new item?\nPRICE: $";
    cin >> p;

    cout << "What's the weight of the new item in oz.?\nWEIGHT: ";
    cin >> w;

    cout << "What's the quantity of stock of the new item?\nQUANTITY: ";
    cin >> q;

    cout << "What's the Bin ID of the new item?\nID: ";
    cin >> id;

    InvItem* newItem = new InvItem(n, p, w, q, id);

    switch (choice) {
        case 1:
            itemList.append(newItem);
            break;
        case 2:
            itemList.prepend(newItem);
            break;
        case 3:
            cout << "What index should the new item be inserted to? (0 - " << itemList.getCounter()  << ")" << endl;
            choice = enterChoice(0, itemList.getCounter());
            itemList.insert(newItem, choice);
            break;
        default:
            break;
    }
}

void removeMenu(LinkedList<InvItem>& itemList) {
    cout << "Which item would you like to remove?" << endl;
    for (int i = 0; i < itemList.getCounter(); i++) {
        cout << i + 1 << ". " << itemList.getItem(i)->getValue()->getName() << endl;
    }
    cout << "0. Cancel";
    int choice = enterChoice(0, itemList.getCounter());

    if (choice == 0) return;
    
    itemList.remove(choice - 1);
}

void printMenu(LinkedList<InvItem> itemList) {
    ofstream out;
    string fn;
    cout << "Where do you want to print?" << endl;
    cout << "1. Print to console" << endl;
    cout << "2. Print to file" << endl;
    cout << "3. Cancel" << endl;
    int choice = enterChoice(1, 3);

    switch (choice) {
        case 1:
            cout << itemList;
            break;
        case 2:
            cout << "What is the filename (example.txt)?" << endl;
            cin.ignore();
            getline(cin, fn);
            out.open(fn);
            out << itemList;
            out.close();
            break;
        default:
            break;
    }
}

int enterChoice(int lowerBound, int upperBound) {
    int choice;
    cout << "CHOICE: ";
    do {
        cin >> choice;
        if (choice < lowerBound || choice > upperBound) {
            cout << "INVALID CHOICE.. Please enter a number between " << lowerBound << " and " << upperBound << endl;
            cout << "CHOICE: ";
        }
    } while (choice < 1 || choice > 5);
    return choice;
}
