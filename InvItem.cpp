/*
*   Author: Robert J. Morriss
*   Date: 10/22/2024
*   File: InvItem.cpp
*   Purpose: Function definition for CSC 1310 Program 2 Data Class
*/

#include "InvItem.h"

// Constructors

InvItem::InvItem() {
    this->name = "";
    this->price = 0.00;
    this->weight = 0;
    this->quantity = 0;
    this->binID = 0;
    this->unitPrice = calcUnitPrice();
}

InvItem::InvItem(string n) {
    this->name = n;
    this->price = 0.00;
    this->weight = 0;
    this->quantity = 0;
    this->binID = 0;
    this->unitPrice = calcUnitPrice();
}

InvItem::InvItem(string n, int ID) {
    this->name = n;
    this->price = 0.00;
    this->weight = 0;
    this->quantity = 0;
    this->binID = ID;
    this->unitPrice = calcUnitPrice();
}

InvItem::InvItem(string n, float p, int w, int q, int ID) {
    this->name = n;
    this->price = p;
    this->weight = w;
    this->quantity = q;
    this->binID = ID;
    this->unitPrice = calcUnitPrice();
}

// Getters 

string InvItem::getName() { return this->name; }
float InvItem::getPrice() { return this->price; }
int InvItem::getWeight() { return this->weight;}
int InvItem::getUnitPrice() { return this->unitPrice; }
int InvItem::getQuantity() { return this->quantity; }
int InvItem::getID() { return this->binID; }

// Setters

void InvItem::setName(string n) { this->name = n; }
void InvItem::setPrice(float p) { this->price = p; }
void InvItem::setWeight(int w) { this->weight = w;}
void InvItem::setQuantity(int q) { this->quantity = q; }
void InvItem::setID(int ID) { this->binID = ID; }
void InvItem::updateUnitPrice() { this->unitPrice = calcUnitPrice(); }

// Operator Overloading

ostream& operator<<(ostream& output, const InvItem& item) {
    output << "\n******************** ITEM: " << item.name << " ********************" << endl;
    output << "\tPRICE: $" << item.price << endl;
    output << "\tWEIGHT: " << (item.weight / 16) << "lbs. " << (item.weight % 16) << "oz." << endl;
    output << "\tUNIT PRICE: " << item.unitPrice << endl;
    output << "\tQUANTITY: " << item.quantity << endl;
    return output;
}
bool operator<(const InvItem& item1, const InvItem& item2) { return item1.binID < item2.binID; }
bool operator>(const InvItem& item1, const InvItem& item2) { return item1.binID > item2.binID; }
bool operator==(const InvItem& item1, const InvItem& item2) { return item1.binID == item2.binID; }
bool operator<=(const InvItem& item1, const InvItem& item2) { return !(item1.binID > item2.binID); }
bool operator>=(const InvItem& item1, const InvItem& item2) { return !(item1.binID < item2.binID); }