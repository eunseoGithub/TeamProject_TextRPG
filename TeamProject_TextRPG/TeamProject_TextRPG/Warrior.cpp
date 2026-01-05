#include "Warrior.h"

Warrior::Warrior(string name) : Character(name)
{
	maxhp = 250;
	hp = maxhp;
	attack = 35;
}

void Warrior::Attack(Monster& monster)
{
	monster.TakeDamage(attack);
}