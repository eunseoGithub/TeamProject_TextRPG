#pragma once
#include "Global.h"
#include "Monster.h"
#include "Item.h"
#include <vector>
class Item;
class Monster;
class Character
{
public:
	Character(string name);

	//상태 출력
	void PrintCharacterStatus();

	//전투
	virtual void Attack(Monster& monster);
	void TakeDamage(int damage);
	void Dead();

	//경험치 / 레벨
	void LevelUp();
	void CheckLevelUp();
	void AddExperience(int amount);

	//아이템 효과
	void Heal(int amount);
	void AddTempAttack(int amount);
	void ResetTempAttack();
	void DrinkPotion(int index, Monster& monster);
	void PotionAttack(Monster& monster, int damage);
	void AddGold(int amount);

	//인벤토리
	void AddItem(Item* item);
	vector<Item*>& GetInventory();

	int GetLevel();
	bool GetIsAlive();

	void SetIsAlive(bool isAlive);

protected:

	string name;

	int level;
	int hp;
	int maxhp;
	int attack;

	int experience;
	int gold;
	int bonusAttack;

	vector<Item*> inventory;

	bool isAlive;
	
};

