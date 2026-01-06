#include "Warrior.h"

Warrior::Warrior(string name) : Character(name)
{
	maxhp = 350;
	hp = maxhp;
	attack = 35;
}

void Warrior::Attack(Monster& monster)
{
	monster.TakeDamage(attack);
}