#pragma once
#include <vector>
#include "GameUtils.h"
#include "Global.h"

#include "Monster.h"
#include "Character.h"

#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "PoisonPotion.h"
#include "FirePotion.h"
#include "Shop.h"

#include "StageManager.h"

#include "Warrior.h"
#include "Magician.h"
class GameManager
{
public:
	GameManager();
	bool CreateCharacter();
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
	StageManager stageManager;
};

