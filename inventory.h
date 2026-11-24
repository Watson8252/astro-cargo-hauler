#pragma once

#include <string>
#include <map>

using namespace std;

class Inventory {
private:
	map<string, int> items_;

public:

	//Basic
	void addItem(const string& name, const int quantity);
	bool removeItem(const string& name, const int quantity);
};