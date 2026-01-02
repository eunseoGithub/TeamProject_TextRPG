#pragma once
#include "Monster.h"

class Medusa : public Monster
{
public:
	Medusa(int level);
	void Attack(Character& character);
};
