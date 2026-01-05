#pragma once
#include "Item.h"

class FirePotion : public Item
{
private:
	int damage;

public:
	FirePotion(int dmg = 50);

	string GetName() const override;
	void Use(Monster& monster) override;
};