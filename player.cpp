// Player class implementation

#include "player.h"

Player::Player(const std::string& name, double wallet) : name_(name), wallet_(wallet) {}

	std::string Player::getName() const { return name_; }
	double Player::getWallet() { return wallet_; }
	void Player::addToWallet(double amount) { wallet_ += amount; }
	void Player::subtractFromWallet(double amount) { wallet_ -= amount; }