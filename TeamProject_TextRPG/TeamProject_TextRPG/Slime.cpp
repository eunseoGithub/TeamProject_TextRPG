#include "Slime.h"

Slime::Slime(int level)
{
	name = "ΩΩ∂Û¿”";
	isAlive = true;
	int maxHealth = level * 30;
	int minHealth = level * 20;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 10;
	int minAttack = level * 5;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
}

void Slime::Attack(Character& character)
{
	character.TakeDamage(attack);
}

