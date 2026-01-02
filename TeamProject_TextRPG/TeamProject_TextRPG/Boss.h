#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(int level);
	void Attack(Character& character);
	bool IsBoss() const override { return true; }
};
