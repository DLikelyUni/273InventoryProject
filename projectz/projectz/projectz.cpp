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

    invItem item;
    fstream file;

    vector<invItem> data;

    string name, quantity, type, location, day, month, year;

    file.open("E:/Inventory.txt", ios::in);                                                //opens file
    file >> name >> quantity >> type >> location >> day >> month >> year;

    while (!file.eof()) {                                                                 //Stores all data from file into multiple vectors
        item.nameIn = name;
        item.quantityIn = stoi(quantity);
        item.typeIn = type;
        item.locationIn = location;
        item.dayIn = stoi(day);
        item.monthIn = stoi(month);
        item.yearIn = stoi(year);
        item.forDeletion = false;
        data.push_back(item);

        file >> name >> quantity >> type >> location >> day >> month >> year;
    }
    file.close();

    inv.alertMessage(data);

    do {
        int num{ -1 };
       
        //Asking user what function they want to do

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