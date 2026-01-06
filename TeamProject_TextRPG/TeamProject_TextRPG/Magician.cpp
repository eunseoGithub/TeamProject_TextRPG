#include "Magician.h"

Magician::Magician(string name) : Character(name)
{
	maxhp = 250;
	hp = maxhp;
	attack = 50;
	jobType = "Magician";
}

void Magician::Attack(Monster& monster)
{
	monster.TakeDamage(attack);
}