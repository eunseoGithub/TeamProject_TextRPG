#pragma once
#include"Global.h"
#include "Character.h"
class Character;
class Monster
{
public:
	Monster(){}
	string GetName();
	int GetHealth();
	int GetAttack();
	void TakeDamage(int damage);
	virtual void Attack(Character& character) = 0;
	void Dead();
	bool GetIsAlive();
	void SetIsAlive(bool alive);
	virtual ~Monster() = default;
	void PrintMonsterStatus();
	virtual bool IsBoss() const { return false; }
protected:
	string name;
	int health;
	int attack;
	bool isAlive;
};