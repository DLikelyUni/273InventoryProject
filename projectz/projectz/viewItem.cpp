#include "class.h"
#include <fstream>
#include<iostream>

using namespace std;

void inventory::viewItem(vector<invItem>& data)
{
    inventory inv;

    invItem item;

    int filter{ -1 };

    //Outputs headers
    cout << "\n\n\t\t\t\t\tAll Items";
    cout << "\n\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
    cout << "----------------------------------------------------------------------------\n";
       
        

        //Outputs all data stored in the vectors in a neat display
        for (int i = 0; i < data.size(); i++)                                                     
        {                                                                                           
            if (data[i].forDeletion == false) {
                cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
                    << data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n";
            }
        }
        

        do {
            cout << "\n\n\nDo you wish to filter this view? (1=Yes) and (0=No) : ";             //Asks and checks input of user if they wish to filter the view
            cin >> filter;
        } while (filter < 0 && filter > 1);


        if (filter == 1)                                                                   //If the user wishes to filter the view, it runs the function to filter it
        {
            inv.filterView(data);
        }
     
     system("pause");
    
}