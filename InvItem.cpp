/*
*   Author: Robert J. Morriss
*   Date: 10/22/2024
*   File: InvItem.cpp
*   Purpose: Class definition for CSC 1310 Program 2 Data Class
*/

#include "InvItem.h"
#include <iostream>
using namespace std;

class InvItem {
    private:
        string name;
        int price,
            unitPrice,
            quantity,
            binID;
    public:
        InvItem();
        ~InvItem();
};