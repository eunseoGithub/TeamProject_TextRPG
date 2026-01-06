#pragma once
#include "Item.h"

class PoisonPotion : public Item
{
private:
	int damage;

public:
	PoisonPotion(int dmg = 30);

	string GetName() const override;
	void Use(Character& character) override;
};