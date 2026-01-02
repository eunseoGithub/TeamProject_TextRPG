#pragma once
#include <vector>
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
#include "Shop.h"
#include "GameUtils.h"

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
	void PrintTotalMonster()const;
	bool HandleMonsterDefeat();
	bool HandleCharacterDefeat();
	void DeleteMember();
	bool VisitShop();
private:
	Character* character;
	Monster* currentMonster;
	vector<string> totalMonster;
	Shop* shopManager;
};

