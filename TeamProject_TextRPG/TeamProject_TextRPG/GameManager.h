#pragma once
#include "Monster.h"
#include "Character.h"

class GameManager
{
public:
	GameManager();
	Monster* GenerateMonster(int level);
	void Battle(Character* character);
	const void DisplayInventory(const Character* const character);
private:
	
};

