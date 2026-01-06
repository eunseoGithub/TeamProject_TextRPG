#pragma once
#include "Monster.h"

class Ogre : public Monster
{
public:
	Ogre(int level);
	void Attack(Character& character);
};
