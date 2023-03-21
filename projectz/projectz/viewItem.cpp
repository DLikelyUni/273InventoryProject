#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::viewItem()
{
    inventory inv;

    fstream file;

    int filter{ -1 };
    string name, type, location, quantity;
    cout << "\n\n\t\t\t\t\tAll Items";

    file.open("E:/Inventory.txt", ios::in);     //opens file
    file >> name >> quantity >> type >> location;

        cout << "\n\nname\t\tquantity"
            << "\ttype\t\tlocation\n";

        while (!file.eof()) {                   //shows whole file
            cout << name << "\t\t" << quantity << "\t\t" << type << "\t\t" << location << "\n";
            file >> name >> quantity >> type >> location;
        }
        

        do {
            cout << "\n\n\nDo you wish to filter this view? (1=Yes) and (0=No) : ";             //Asks and checks input of user if they wish to filter the view
            cin >> filter;
        } while (filter < 0 && filter > 1);


        if (filter == 1)                                                                   //If the user wishes to filter the view, it runs the function to filter it
        {
            inv.filterView();
        }
     
     system("pause");
     
     file.close();
}