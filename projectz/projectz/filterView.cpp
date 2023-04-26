#include "class.h"
#include <iostream>
#include <fstream>

using namespace std;

void inventory::filterView(vector<invItem>& data)
{

    int num{ 0 }, userInt{ 0 };
    string userInput;
    bool ver = false, notFound = true;                  //used for verification 

    //Menu

    cout << "\n\n\n\n How would you like to filter the list?\n ";

    cout << "\nBy location :: 1";
    cout << "\nType of food :: 2";
    cout << "\nAbove a quantity value :: 3";
    cout << "\nBelow a quantity value:: 4";

    do {
        cout << "\n \n Enter a number corresponding to a function : \n";
        cin >> num;
    } while (num < 1 or num > 4);


    switch (num)
    {
    case 1:

        cout << "\nWhat location do you wish to filter by? : ";                  //Asks the user what location they wish to filter by
        cin >> userInput;

        for (int i = 0; i < userInput.length(); i++)                            //Turns input to Lowercase
        {
            userInput[i] = tolower(userInput[i]);
        }

        cout << "\n\nHere is the filtered list \n\n";

        
        //Outputs headers
        cout << "\n\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
        cout << "----------------------------------------------------------------------------\n";

        for (int i = 0; i < data.size(); i++)                   //Outputs all data that matches the location the user inputed                                             
        {                                                                                           
            if (userInput == data[i].locationIn and data[i].forDeletion == false)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
                    << data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n";
               
                notFound = false;           //Sets notFound to False if the location the user enetered matches one from the file
            }
        }


        //If location user inputted does not match any in the file, this message apears
        if (notFound == true)
        {
            cout << "\nThe location you entered does not match any inside the file\n";
        }
        break;


    case 2:
        do {
            cout << "\nWhat type of food do you wish to filter by? (fresh/frozen/canned) : ";       //asks for type of item
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

        //Outputs headers
        cout << "\n\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
        cout << "----------------------------------------------------------------------------\n";


        for (int i = 0; i < data.size(); i++)                   //Outputs all data that matches the type the user inputed        
        {
            if (userInput == data[i].typeIn and data[i].forDeletion == false)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
                    << data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n";
            }
        }
        break;


    case 3:

        while (userInt < 1)
        {
            cout << "\nWhat is the lowest quantity value? : ";                  //Asks the user what the lowest quantity they wish to filter by
            cin >> userInt;
        }


        cout << "\n\nHere is the filtered list \n\n";

        //Outputs headers
        cout << "\n\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
        cout << "----------------------------------------------------------------------------\n";



        for (int i = 0; i < data.size(); i++)                   //Outputs all data that is equal to or greater than the quantity the user inputed                                        
        {
            if (userInt <= data[i].quantityIn and data[i].forDeletion == false)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
                    << data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n";

            }
        }

        break;


    case 4:


        while (userInt < 1)
        {
            cout << "\nWhat is the highets quantity value? : ";                  //Asks the user what the highest quantity they wish to filter by
            cin >> userInt;
        }


        cout << "\n\nHere is the filtered list \n\n";

        //Outputs headers
        cout << "\n\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
        cout << "----------------------------------------------------------------------------\n";

        for (int i = 0; i < data.size(); i++)                   //Outputs all data that is equal to or less than the quantity the user inputed                                            
        {
            if (userInt >= data[i].quantityIn and data[i].forDeletion == false)
            {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
                    << data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n";

            }
        }

        break;
    }
}