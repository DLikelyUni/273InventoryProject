#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::removeItem() {
    
    inventory inv;

    fstream file, file1;                        
    int quantity, amount, count{ 0 };
    string name, type, location, item, area;                

    file1.open("E:/temporary.txt",                          //creates 2 files, 1 to read, the other to rewrite the correct part
        ios::app | ios::out);
    file.open("E:/Inventory.txt",
        ios::in);

    file >> name >> quantity >> type >> location;

        cout << "\nWhat item do you wish to remove? : ";                 //Asks user info on what they wish to remove
        cin >> item;
        cout << "\nHow many do you wish to remove? : ";
        cin >> amount;
        cout << "\nWhat location is it stored in? : ";
        cin >> area;


        for (int i = 0; i < item.length(); i++)                            //Turns input to Lowercase
        {
            item[i] = tolower(item[i]);
        }
        for (int i = 0; i < area.length(); i++)                            //Turns input to Lowercase
        {
            area[i] = tolower(area[i]);
        }
            
        while (!file.eof()) {

            if (name == item and location == area)              //if location and name match, all data is deleted
            {                
                
                if (amount < quantity)                          //This if statement checks if the amount entered is < the amount stored and ammends file if true
                {
                    quantity = quantity - amount;

                    cout << "\nData has been ammended\n";
                    
                    file1 << " " << name << " "
                        << quantity << " " << type
                        << " " << location << "\n";
                }
                else if (amount > quantity)                                 //If the amount entered>the amount stored; therefore no changes are made
                {
                    cout << "\nThe quantity is too high\n";
                    cout << " \nNo changes will be made\n\n\n\n";
                    file1 << " " << name << " "
                        << quantity << " " << type
                        << " " << location << "\n";
                }
                else                                                        // Tells user if the item has been deleted
                {
                    cout << "\nSuccesfuly Deleted\n";
                }
                count = 1;                                                  //If no data was ammended or deleted, the variable count will not change

            } else 
            {
                file1 << " " << name << " "                                 //rewrites all data into new file that does not match the criteria the user set
                    << quantity << " " << type
                    << " " << location << "\n";
            }

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
