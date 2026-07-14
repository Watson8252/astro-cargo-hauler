// Player head
#pragma once
#include <iostream>
#include "inventory.h"

using namespace std;

class Player {

private:

	string name_;
	double wallet_;
	Inventory inventory_;

public:

	// Constructor
	Player(
		const string& name,
		double wallet = 1000.00 // Default wallet amount OR can set to 0.00 and introduce a story element.
	);

	// Deconstructor
	~Player() = default;

	// Getters
	string getName() const;
	double getWallet();

	// Methods
	void addToWallet(double amount);
	void subtractFromWallet(double amount);
	void buy(const string& itemName, int quantity);
	void sell(const string& itemName, int quantity);
};
