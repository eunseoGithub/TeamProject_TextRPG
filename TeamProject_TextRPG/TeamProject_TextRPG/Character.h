#pragma once
#include "Global.h"
#include "Monster.h"
class Character
{
public:
	Character(string name);

	void PrintCharacterStatus();
	void LevelUp();

	string  GetName();
	int GetLevel();
	int GetHp();
	int GetMaxHp();
	int GetAttack();
	int GetExperience();
	int GetGold();
	int GetInventory();
	bool GetIsAlive();

	void SetName(string name);
	void SetHp(int hp);
	void SetMaxHp(int maxhp);
	void SetAttack(int attack);
	void SetExperience(int experience);
	void SetGold(int gold);
	void SetInventory(int inventory);
	void Attack(Monster& monster);
	void TakeDamage(int damage);
	void SetIsAlive(bool isAlive);

	void Dead();

private:

	string name;
	int level;
	int hp;
	int maxhp;
	int attack;
	int experience;
	int gold;
	int inventory;
	int damage;
	int dead;
	bool isAlive;
};

