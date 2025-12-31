#pragma once
#include"Global.h"
#include "Character.h"

class Monster
{
public:
	virtual string GetName() = 0;
	virtual int GetHealth() = 0;
	virtual int GetAttack() = 0;
	virtual void TakeDamage(int damage) = 0;
	virtual void Attack(Character& character) = 0;
	virtual void Dead() = 0;
	virtual bool GetIsAlive() = 0;
	virtual void SetIsAlive(bool alive) = 0;
};

