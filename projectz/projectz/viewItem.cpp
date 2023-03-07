#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::viewItem()
{
    inventory inv;

    fstream file;

    int quantity{ 0 };
    string name, type, location, filter;
    cout << "\n\n\t\t\t\t\tAll Items";

    file.open("E:/Inventory.txt", ios::in);     //opens file
    file >> name >> quantity >> type >> location;

        cout << "\n\nname\t\tquantity"
            << "\ttype\t\tlocation\n";

        while (!file.eof()) {                   //shows whole file
            cout << name << "\t\t" << quantity << "\t\t" << type << "\t\t" << location << "\n";
            file >> name >> quantity >> type >> location;
        }

        system("pause");
           

      
        

     file.close();
}