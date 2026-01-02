#pragma once
#include "Monster.h"

class Ghost : public Monster
{
public:
	Ghost(int level);
	void Attack(Character& character);
};
