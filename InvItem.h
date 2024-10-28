/*
*   Author: Robert J. Morriss
*   Date: 10/22/2024
*   File: InvItem.h
*   Purpose: Header file for CSC 1310 Program 2 Data Class
*/

#ifndef INVITEM_H
#define INVITEM_H

#include <fstream>
#include <iostream>
using namespace std;
class InvItem {
    private:
        string name;
        float price, // in $
              unitPrice; // ¢/oz.
        int weight, // in oz.
            quantity,
            binID; // Stored id for organization in listing

        // Helpers
        float calcUnitPrice() { return weight / (price * 100); }
    public:
        // Constructors and Destructors

        InvItem();
        InvItem(string);
        InvItem(string, int);
        InvItem(string, float, int, int, int);
        ~InvItem(){}

        // Getters
        string getName();
        float getPrice();
        int getWeight();
        float getUnitPrice();
        int getQuantity();
        int getID();

        // Setters

        void setName(string);
        void setPrice(float);
        void setWeight(int);
        void setQuantity(int);
        void setID(int);
        void updateUnitPrice();

        // Operator Overloading

        friend ostream& operator<<(ostream&, const InvItem&);
        friend bool operator<(const InvItem&, const InvItem&);
        friend bool operator>(const InvItem&, const InvItem&);
        friend bool operator==(const InvItem&, const InvItem&);
        friend bool operator<=(const InvItem&, const InvItem&);
        friend bool operator>=(const InvItem&, const InvItem&);

};

#endif