#include "inventory.h"
#include <iostream>

using namespace std;

void Inventory::addItem(const string& name, int quantity) {
	if (quantity <= 0) return; // Check if quantity is nonzero positive integer.
	items_[name] += quantity;
}

bool Inventory::removeItem(const string& name, int quantity) {
	if (quantity <= 0) return false; // Check if quantity is nonzero positive integer.
	
	auto it = items_.find(name);

	// Check if item exists in inventory and if there is enough to be removed.
	if (it == items_.end() || it->second < quantity) {
		return false;
	}

	// Item exists and there is enough to be removed
	if (it->second > quantity) {
		it->second -= quantity;
	}

	// Item exists but will be dropped from inventory
	else {
		items_.erase(it);
	}

	return true;
}