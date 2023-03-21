#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::addItem() {                                     //This function is to add items

    fstream file, file1;

    int quantity{ 0 }, ver{ 0 };
    string name, type, location;

    cout << "\n\n\t\t\t\t New Item";                             //title

    cout << "\n\n Name of Item : ";                              //asks for name of item
    cin >> name;

    for (int i = 0; i < name.length(); i++)                            //Turns name of item to Lowercase
    {
        name[i] = tolower(name[i]);
    }

    while (quantity < 1) {                                      //asks for quantity and checks if its above 0, if not repears question until done so
        cout << "\nThe amount you wish to store : ";
        cin >> quantity;
    }

    do {
        cout << "\nType of food (fresh, frozen or canned): ";       //asks for type of item
        cin >> type;


        for (int i = 0; i < type.length(); i++)                            //Turns input to Lowercase
        {
            type[i] = tolower(type[i]);
        }


        if (type == "fresh")                                    //This verifies the users input to one of 3 types of food
        {
            ver = 1;
        }
        else if (type == "frozen")
        {
            ver = 1;
        }
        else if (type == "canned")
        {
            ver = 1;
        }


    } while (ver != 1);                                         //verification if user typed fresh, frozen or canned


    cout << "\nThe location it is to be stored : ";             //asks for location
    cin >> location;


    string nameIn, typeIn, locationIn;
    int quantityIn, alert{ 0 };

    //Need to add a function to see if all data matches, then it just adds the quantity to the file


    file1.open("E:/temporary.txt",                          //creates 2 files, 1 to read, the other to rewrite the correct part
        ios::app | ios::out);
    file.open("E:/Inventory.txt",
        ios::in);


    file >> nameIn >> quantityIn >> typeIn >> locationIn;

    while (!file.eof()) {

        if (name == nameIn and location == locationIn and type == typeIn) {                //if location and name match, all data is deleted
            quantityIn += quantity;
            alert = 1;
        }
        file1 << " " << nameIn << " "
            << quantityIn << " " << typeIn
            << " " << locationIn << "\n";

        file >> nameIn >> quantityIn >> typeIn >> locationIn;
    }

    system("pause");

    if (alert != 1)
    {
        file1 << " " << name << " "
            << quantity << " " << type
            << " " << location << "\n";
    }

    file.close();                                               //stores and renames new file of all data not wanting to get rid off
    file1.close();

    remove("E:/Inventory.txt");
    rename("E:/temporary.txt", "E:/Inventory.txt");
}