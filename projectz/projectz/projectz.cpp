#include <iostream>
#include "class.h"


using namespace std;

int main()
{

    inventory inv;
    bool exit = false;          //creates infinite loop of menu
    inv.alertMessage();


    do {
        int num{ -1 };
       

        cout << "\nAdd an Item :: 1";
        cout << "\nRemove an Item :: 2";
        cout << "\nView an Item :: 3";
        cout << "\nEnd program :: 0";

        while (num < 0 or num > 3) {
            cout << "\n \n Enter a number corresponding to a function : \n";
            cin >> num;
        }
        switch (num) {

        case 0:
            exit = true;            // breaks infinite loop
            break;

        case 1:                     //function to add items
            inv.addItem();
            break;

        case 2:
            inv.removeItem();       //function to remove items
            break;

        case 3:
            inv.viewItem();         //function to view items
            break;

        default:
            cout << "Not in Range";
        }

    } while (exit == false);
}