/*
*   Author: Robert J. Morriss
*   Date: 10/22/2024
*   File: InvItem.h
*   Purpose: Header file for CSC 1310 Program 2 Data Class
*/

#ifndef INVITEM_H
#define INVITEM_H

#include <iostream>
using namespace std;
class InvItem {
    private:
        string name;
        int price, // USD
            weight, // lbs. / oz.
            unitPrice, // ¢/oz.
            quantity,
            binID; // Stored id for organization in listing
    public:
        // Constructors and Destructors

        InvItem();
        InvItem(string);
        InvItem(string, int);
        InvItem(string, int, int, int, int);
        ~InvItem();

        // Getters
        string getName();
        int getPrice();
        int getWeight();
        int getUnitPrice();
        int getQuantity();
        int getID();

        // Setters

        void setName(string);
        void setPrice(int);
        void setWeight(int);
        void setUnitPrice(int);
        void setQuantity(int);
        void setID(int);
};

#endif