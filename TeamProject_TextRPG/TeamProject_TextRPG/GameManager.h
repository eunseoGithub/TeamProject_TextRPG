#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "Monster.h"
#include "Character.h"
#include "Global.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "Boss.h"
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
	void Render()const;
private:
	void CharacterAct();
	void MonsterAct();
	void DisplayInventory()const;
	void GameWin();
	void GameLose();
	void ClearScreen()const;
	void PrintTotalMonster()const;
	bool HandleMonsterDefeat();
	bool HandleCharacterDefeat();
	void DeleteMember();
private:
	Character* character;
	Monster* currentMonster;
	vector<string> totalMonster;
};

