// Player class implementation

#include "player.h"

using namespace std;

Player::Player(const string& name, double wallet) : name_(name), wallet_(wallet) {}

	string Player::getName() const { return name_; }
	double Player::getWallet() { return wallet_; }
	void Player::addToWallet(double amount) { wallet_ += amount; }
	void Player::subtractFromWallet(double amount) { wallet_ -= amount; }
	void Player::buy(const string& itemName, int quantity) { inventory_.addItem(itemName, quantity); }
	void Player::sell(const string& itemName, int quantity) { inventory_.removeItem(itemName, quantity); }

	//Player renderer
	Element Player::render() const {
		return vbox({
			text(name_) | bold,
			text("Wallet: " + to_string(wallet_)),
			separator(),
			text("Current Ship: Random ship name")
		});
	}
