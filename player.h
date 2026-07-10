// Player header file
#include <iostream>

class Player {

private:

	std::string name_;
	double wallet_;

public:

	// Constructor
	Player(const std::string& name, double wallet = 0.00);

	// Deconstructor
	~Player() = default;

	// Getters
	std::string getName() const;
	double getWallet();

	// Methods
	void addToWallet(double amount);
	void subtractFromWallet(double amount);
};
