#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
	Dragon(int level);
	void Attack(Character& character);
};
