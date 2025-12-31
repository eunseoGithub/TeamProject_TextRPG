#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc(int level);
	void Attack(Character& character);
};
