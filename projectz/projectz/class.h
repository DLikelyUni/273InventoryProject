#pragma once
#include <string>
#include<vector>

using namespace std;

class invItem {
public:
	string nameIn;
	int quantityIn{ 0 };
	string typeIn;
	string locationIn;
	int dayIn{ 0 };
	int monthIn{ 0 };
	int yearIn{ 0 };
};

class inventory {
public:
	void addItem(vector<invItem>& data);
	void removeItem(vector<invItem>& data);
	void viewItem(vector<invItem>& data);
	void alertMessage();
	void filterView(vector<invItem>& data);
};


