#pragma once
#include "Monster.h"

class Golem : public Monster
{
public:
	Golem(int level);
	void Attack(Character& character);
};
