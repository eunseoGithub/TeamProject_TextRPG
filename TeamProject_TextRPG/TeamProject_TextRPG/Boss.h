#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(int level);
	string GetName() override;
	int GetHealth() override;
	int GetAttack() override;
	void TakeDamage(int damage) override;
	void Attack(Character& character) override;
	void Dead() override;
	bool GetIsAlive() override;
	void SetIsAlive(bool alive) override;
private:
	string name;
	int health;
	int attack;
	bool isAlive;
};
