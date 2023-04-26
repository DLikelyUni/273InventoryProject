#include "class.h"
#include <fstream>
#include<iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void inventory::addItem(vector<invItem>& data)
{
    invItem item;

    int quantity{ 0 }, day{ 0 }, month{ 0 }, year{ 0 };
    string name, type, location;
    bool check = false, ver = false ;

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
            ver = true;
        }
        else if (type == "frozen")
        {
            ver = true;
        }
        else if (type == "canned")
        {
            ver = true;
        }


    } while (ver == false);                                         //verified if user typed fresh, frozen or canned


    cout << "\nThe location it is to be stored : ";             //asks for location
    cin >> location;

    for (int i = 0; i < location.length(); i++)                            //Turns name of item to Lowercase
    {
        location[i] = tolower(location[i]);
    }



    while (day < 1 or day > 31)                                //Asks Expiration day
    {
        cout << "\nThe experation day : ";
        cin >> day;
    }
   
    while (month < 1 or month > 12)                             //Asks Expiration month
    {
        cout << "\nThe experation month : ";                                   
        cin >> month;
    }

    cout << "\nThe experation year : ";                           //Asks Expiration Year
    cin >> year;



    for (int i = 0; i < data.size(); i++)                                                     //If the user input matches any other stored data then it will
    {                                                                                           //update the old quantity by adding the new one
        if (name == data[i].nameIn and location == data[i].locationIn and type == data[i].typeIn 
            and day == data[i].dayIn and month == data[i].monthIn and year == data[i].yearIn)
        {
            data[i].quantityIn = data[i].quantityIn + quantity;
            check = true;
            cout << "\nData ammended\n";
        }
    }

    if (check == false)                                 //If it is new data, it will add it to the vectors
    {
        item.nameIn = name;
        item.quantityIn = quantity;
        item.typeIn = type;
        item.locationIn = location;
        item.dayIn = day;
        item.monthIn = month;
        item.yearIn = year;
        item.forDeletion = false;
        data.push_back(item);

        cout << "\nNew data added\n";
    }



    ofstream file("E:/Inventory.txt");         //opens and clears the file
    file << "";

    for (int i = 0; i < data.size(); i++)                                         //writes all data stored in vectors into a file
    {
        if (data[i].forDeletion == false)
        {
            file << " " << data[i].nameIn << " " << data[i].quantityIn << " " << data[i].typeIn << " " << data[i].locationIn
                << " " << data[i].dayIn << " " << data[i].monthIn << " " << data[i].yearIn << "\n";

        }
    }


    file.close();

    std::system("pause");
}