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
	void Attack(Monster& monster);
	void TakeDamage(int damage);
	void Dead();

	//경험치 / 레벨
	void LevelUp();
	void CheckLevelUp();
	void AddExperience(int amount);

	//아이템 효과
	void Heal(int amount);
	void AddTempAttack(int amount);
	void ResetTempAttack(int amount);

	void DrinkPotion();

	//인벤토리
	void AddItem(Item* item);
	vector<Item*>& GetInventory();

	//getter
	string  GetName();
	int GetLevel();
	int GetHp();
	int GetMaxHp();
	int GetAttack();
	int GetExperience();
	int GetGold();
	bool GetIsAlive();

	//setter
	void SetName(string name);
	void SetHp(int hp);
	void SetMaxHp(int maxhp);
	void SetAttack(int attack);
	void SetExperience(int experience);
	void SetGold(int gold);
	void SetIsAlive(bool isAlive);

private:

	string name;

	int level;
	int hp;
	int maxhp;

	int attack;

	int experience;
	int gold;
	int item;
	
	vector<Item*> inventory;
	bool isAlive;
};

