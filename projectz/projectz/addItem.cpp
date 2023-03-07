#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;
        
void inventory::addItem() {                                     //This function is to add items
    
    fstream file;
   
    int quantity{ 0 }, ver{ 0 };
    string name, type, location;
   
    cout << "\n\n\t\t\t\t New Item";                             //title

    cout << "\n\n Name of Item : ";                              //asks for name of item
    cin >> name;

    for (int i = 0; i < name.length(); i++)                            //Turns name of item to Lowercase
    {
        name[i] = tolower(name[i]);
    }
    
    while (quantity < 1) {                                      //asks for quantity and checks if its in range
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


        if (type == "fresh")                                    //This verifies the users input
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



                                                                //Need to add a function to see if all data matches, then it just adds the quantity to the file



    file.open("E:/Inventory.txt",                              //stored in text file all data
        ios::out | ios::app);
    file << " " << name << " "
        << quantity << " " << type
        << " " << location << "\n";
    file.close();
}
