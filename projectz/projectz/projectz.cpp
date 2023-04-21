#include <iostream>
#include "class.h"
#include<fstream>
#include<vector>
#include<string>


using namespace std;

int main()
{


    inventory inv;
    bool exit = false;          //creates infinite loop of menu
   // inv.alertMessage();


    do {
        inventory inv;
        invItem item;
        fstream file;

        vector<invItem> data;
       
        string name, quantity, type, location, day, month, year;

        file.open("E:/Inventory.txt", ios::in);
        file >> name >> quantity >> type >> location >> day >> month >> year;

        while (!file.eof()) {    
            item.nameIn = name;
            item.quantityIn = stoi(quantity);
            item.typeIn = type;
            item.locationIn = location;
            item.dayIn = stoi(day);
            item.monthIn = stoi(month);
            item.yearIn = stoi(year);
            data.push_back(item);

            file >> name >> quantity >> type >> location >> day >> month >> year;
       }

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
            inv.addItem(data);
            break;

        case 2:
            inv.removeItem(data);       //function to remove items
            break;

        case 3:
            inv.viewItem(data);         //function to view items
            break;

        default:
            cout << "Not in Range";
        }

    } while (exit == false);

    
}