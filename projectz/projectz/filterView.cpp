#include "class.h"
#include <iostream>
#include <fstream>

using namespace std;

void inventory::filterView()
{
    inventory inv;

    fstream file;
    int num, ver{ 0 };
    string name, quantity, type, location, userInput;

    file.open("E:/Inventory.txt", ios::in);     //opens file
    file >> name >> quantity >> type >> location;

    cout << "\n\n How would you like to filter the list?\n\n ";

    cout << "\nBy location :: 1";
    cout << "\nType of food :: 2";
    cout << "\nDate ascending :: 3";
    cout << "\nDate descending :: 4";

    do {
        cout << "\n \n Enter a number corresponding to a function : \n";
        cin >> num;
    } while (num < 1 or num > 4);


    switch (num)
    {
    case 1:

        cout << "\nWhat location do you wish to filter by?\n";
        cin >> userInput;

        for (int i = 0; i < userInput.length(); i++)                            //Turns input to Lowercase
        {
            userInput[i] = tolower(userInput[i]);
        }

        cout << "\n\nHere is the filtered list \n\n";

        while (!file.eof()) {

            if (userInput == location)
            {
                cout << name << "\t\t" << quantity << "\t\t" << type << "\t\t" << location << "\n";
            }
            file >> name >> quantity >> type >> location;
        }
        break;


    case 2:
        do {
            cout << "\nWhat type of food do you wish to filter by? (fresh/frozen/canned)\n";       //asks for type of item
            cin >> userInput;

            for (int i = 0; i < userInput.length(); i++)                            //Turns input to Lowercase
            {
                userInput[i] = tolower(userInput[i]);
            }

            if (userInput == "fresh")                                    //This verifies the users input
            {
                ver = 1;
            }
            else if (userInput == "frozen")
            {
                ver = 1;
            }
            else if (userInput == "canned")
            {
                ver = 1;
            }

        } while (ver != 1);                                         //verification if user typed fresh, frozen or canned


        cout << "\n\nHere is the filtered list \n\n";

        while (!file.eof()) 
        {

            if (userInput == type)
            {
                cout << name << "\t\t" << quantity << "\t\t" << type << "\t\t" << location << "\n";
            }
            file >> name >> quantity >> type >> location;
        }
        break;





    case 3:
        break;
    case 4:
        break;


    }
}