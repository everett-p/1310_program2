/*
*   Author: Robert J. Morriss
*   Date: 10/22/2024
*   File: InvItem.cpp
*   Purpose: Function definition for CSC 1310 Program 2 Data Class
*/

#include "InvItem.h"

// Constructors / Destructor

InvItem::InvItem() {
    
}

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