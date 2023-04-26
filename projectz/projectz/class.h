#pragma once
#include <string>
#include<vector>

using namespace std;

//Creates variable types
class invItem {
public:
	string nameIn;
	int quantityIn{ 0 };
	string typeIn;
	string locationIn;
	int dayIn{ 0 };
	int monthIn{ 0 };
	int yearIn{ 0 };
	bool forDeletion;
};

//Class of all the functions and connecting all the .cpp files together
class inventory {
public:
	void addItem(vector<invItem>& data);
	void removeItem(vector<invItem>& data);
	void viewItem(vector<invItem>& data);
	void alertMessage(vector<invItem>& data);
	void filterView(vector<invItem>& data);
};