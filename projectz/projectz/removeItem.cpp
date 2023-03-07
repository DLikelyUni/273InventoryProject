#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::removeItem() {
    
    fstream file, file1;                        
    int quantity, count{ 0 };
    string name, type, location, item, area;                

    file1.open("E:/temporary.txt",                          //creates 2 files, 1 to read, the other to rewrite the correct part
        ios::app | ios::out);
    file.open("E:/Inventory.txt",
        ios::in);

        cout << "\nWhat item do you wish to remove?\n";
        cin >> item;
        cout << "\nWhat location is it stored in?\n";
        cin >> area;


        for (int i = 0; i < item.length(); i++)                            //Turns input to Lowercase
        {
            item[i] = tolower(item[i]);
        }
        for (int i = 0; i < area.length(); i++)                            //Turns input to Lowercase
        {
            area[i] = tolower(area[i]);
        }

        file >> name >> quantity >> type >> location;
            
        while (!file.eof()) {

            if (name == item and location == area) {                //if location and name match, all data is deleted
                cout << "\nSuccesfuly Deleted\n";
                count = 1;
            } else
                file1 << " " << name << " "
                << quantity << " " << type
                << " " << location << "\n";

            file >> name >> quantity >> type >> location;
        }

        if (count != 1)                                         //Message if could not find item to delete
        {
            cout << "\nCould not find the item to delete\n";
        } 

    system("pause");

    file.close();                                               //stores and renames new file of all data not wanting to get rid off
    file1.close();

    remove("E:/Inventory.txt");
    rename("E:/temporary.txt", "E:/Inventory.txt");
}
