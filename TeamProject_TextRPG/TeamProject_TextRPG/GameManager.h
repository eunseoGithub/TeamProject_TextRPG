#pragma once
#include <vector>
#include "Monster.h"
#include "Character.h"
#include "Global.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"

class GameManager
{
public:
	GameManager();
	bool CreateCharacter();
	void GenerateMonster(int level);
	bool GamePlay();
	void Render();
private:
	void CharacterAct();
	void MonsterAct();
	const void DisplayInventory();
	void GameWin();
	void GameLose();
private:
	Character* character;
	Monster* currentMonster;
};

