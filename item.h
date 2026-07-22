#pragma once

#include <string>

using namespace std;

// Item types will define where the items come from
enum class ItemType {
	Raw,
	Industrial,
	Manufactured,
	Agricultural,
	Biological
};

// Item hazard will define how the item will need to be transported
// hazards will also determine
enum class ItemHazard {
	None,
	Radioactive,
	Biohazard,
	Explosive
};

enum class ItemRarity {
	Common,
	Uncommon,
	Rare,
	Precious, // This one might not be necessary
	Luxury,
	Unique
};

struct Item {
	string name;
	string description;
	ItemType itemType;
	ItemHazard itemHazard;
	ItemRarity itemRarity;
	double price;
	double volume;

	bool IsHazardous() const { return itemHazard != ItemHazard::None; }
};