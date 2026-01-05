#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	int bonusAttack;

public:
	AttackBoost(int bonus = 10);

	string GetName() const override;
	void Use(Character& character) override;
};