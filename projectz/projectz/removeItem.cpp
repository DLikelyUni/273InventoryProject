#include "class.h"
#include <fstream>
#include<iostream>
#include <vector>


using namespace std;

void inventory::removeItem(vector<invItem>& data) {
       
    invItem item;


    int amount{ 0 }, j{ 0 };
    string name, type, location, food, area;
    bool check = false;           


        cout << "\nWhat item do you wish to remove? : ";                 //Asks user info on what they wish to remove
        cin >> food;
        cout << "\nHow many do you wish to remove? : ";
        cin >> amount;
        cout << "\nWhat location is it stored in? : ";
        cin >> area;


        for (int i = 0; i < food.length(); i++)                            //Turns input to Lowercase
        {
            food[i] = tolower(food[i]);
        }
        for (int i = 0; i < area.length(); i++)                            //Turns input to Lowercase
        {
            area[i] = tolower(area[i]);
        }
            

        while (j < data.size()) {


            //if what the user inputted matches any data in the file, it will be amended or deleted
            if (food == data[j].nameIn and area == data[j].locationIn)             
            {

                if (amount < data[j].quantityIn)                          //This if statement checks if the amount entered is < the amount stored and ammends file if true
                {
                    data[j].quantityIn = data[j].quantityIn - amount;
                    cout << "\nData has been ammended\n";
                }

                else if (amount > data[j].quantityIn)                                 //If the amount entered>the amount stored; therefore no changes are made
                {
                    cout << "\nThe quantity is too high\n";
                    cout << " No changes will be made\n\n\n\n";
                }

                else                                                        // Tells user if the item has been deleted
                {

                    cout << "\nSuccesfuly Deleted\n";

                   data[j].forDeletion = true;                      //Set object attribute so it would not be written back to file


                }

                check = true;                                  //Used to send message after loop if could not find what item the user wanted to delete
            }

            
            j++;
        }

        if (check == false)                                         //Message if could not find item to delete
        {
            cout << "\nCould not find the item to delete\n";
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
        

    system("pause");
}