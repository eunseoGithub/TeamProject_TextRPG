#pragma once
#include "Character.h"
class Magician : public Character
{
public:
	Magician(string name);

	void Attack(Monster& monster) override;
};

