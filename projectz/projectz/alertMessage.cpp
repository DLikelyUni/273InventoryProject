#include "class.h"
#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

bool checkDate(tm currentDate, tm bbd) //date comparrison between item bbd and current date
{
	if (currentDate.tm_year > bbd.tm_year) { //compares years
		return true;
	}
	else if (currentDate.tm_year == bbd.tm_year) { //if same as current year compares months
		if (currentDate.tm_mon > bbd.tm_mon) {
			return true;
		}
		else if (currentDate.tm_mon == bbd.tm_mon) { //if the same month as current month compares date
			if (currentDate.tm_mday > bbd.tm_mday) {
				return true;
			}
			else {
				return false; //returns as being in date
			}
		}
	}

}

void inventory::alertMessage(vector<invItem>&data)
	{
		time_t currentTime;
		time(&currentTime); //initializes time_t variable and fetches current date/time from system
		struct tm* asDate;
		struct tm bbd = { 0 };

		asDate = localtime(&currentTime); //points asdate to tm struct of the current date

		cout << "\t\t\tFood items out of Date\n";
		cout << "\nname\t\tquantity\ttype\t\tlocation\tExpiry Date\n";
		cout << "----------------------------------------------------------------------------\n";

		for (int i = 0; i < data.size(); i++) { //loops through inventory
			bbd.tm_year = data[i].yearIn - 1900;
			bbd.tm_mon = data[i].monthIn - 1;
			bbd.tm_mday = data[i].dayIn;
			bool outOfDate = checkDate(*asDate, bbd); //derefrence and passing tm values to checkdate
			if (outOfDate == true) {

				//outputs to user any out of date items
				cout << data[i].nameIn << "\t\t" << data[i].quantityIn << "\t\t" << data[i].typeIn << "\t\t" << data[i].locationIn << "\t\t"
					<< data[i].dayIn << "/" << data[i].monthIn << "/" << data[i].yearIn << "\n"; 
			}
		}

		cout << "\n\n";					//Creates space between the end of this output to the start of the menu
		return;
	}