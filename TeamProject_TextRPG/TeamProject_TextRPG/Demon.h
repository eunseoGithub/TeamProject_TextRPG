#pragma once
#include "Monster.h"

class Demon : public Monster
{
public:
	Demon(int level);
	void Attack(Character& character);
};
