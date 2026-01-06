#pragma once
#include "Global.h"
#include "Monster.h"
#include "Item.h"
#include <vector>

class Item;
class Monster;
class Shop;
// 현재 캐릭터 소멸시 아이템 소멸을 위해 혜율이 캐릭터 파트 수정합니다.

class Character
{
public:
	Character(string name);
	~Character();

	void SetShop(Shop* shop);

	void PrintCharacterStatus();

	virtual void Attack(Monster& monster);
	void TakeDamage(int damage);
	void Dead();

	void LevelUp();
	void CheckLevelUp();
	void AddExperience(int amount);

	void Heal(int amount);
	void AddTempAttack(int amount);
	void ResetTempAttack();
	void DrinkPotion(int index, Monster& monster);
	void PotionAttack(Monster& monster, int damage);
	void AddGold(int amount);

	void AddItem(Item* item);
	vector<Item*>& GetInventory();

	int GetLevel();
	bool GetIsAlive();
	int GetGold();

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
	string jobType;
	Shop* shop = nullptr;
};
