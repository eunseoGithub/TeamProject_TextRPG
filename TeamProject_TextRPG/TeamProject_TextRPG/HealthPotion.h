#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	int healAmount;

public:
	HealthPotion(int heal = 50);

	std::string GetName() const override;
	void Use(Character& character) override;
};

