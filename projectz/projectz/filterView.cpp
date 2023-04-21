#include "class.h"
#include <iostream>
#include <fstream>

using namespace std;

void inventory::filterView(vector<invItem>& data)
{

    int num;
    string userInput;
    bool ver = false;



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

        for (int i = 0; i < data.size(); i++)                                                    
        {                                                                                           
            if (userInput == data[i].locationIn)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\n";

            }
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
                ver = true;
            }
            else if (userInput == "frozen")
            {
                ver = true;
            }
            else if (userInput == "canned")
            {
                ver = true;
            }

        } while (ver == false);                                         //verification if user typed fresh, frozen or canned


        cout << "\n\nHere is the filtered list \n\n";

        for (int i = 0; i < data.size(); i++)
        {
            if (userInput == data[i].typeIn)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\n";

            }
        }
        break;


    case 3:




        break;
    case 4:
        break;


    }
}