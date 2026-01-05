#include "Magician.h"

Magician::Magician(string name) : Character(name)
{
	maxhp = 150;
	hp = maxhp;
	attack = 50;
}

void Magician::Attack(Monster& monster)
{
	monster.TakeDamage(attack);
}