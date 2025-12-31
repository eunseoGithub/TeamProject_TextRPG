#include "Slime.h"

Slime::Slime(int level)
{
	name = "슬라임";
	isAlive = true;
	int maxHealth = level * 30;
	int minHealth = level * 20;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 10;
	int minAttack = level * 5;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
}

string Slime::GetName()
{
	return name;
}

int Slime::GetHealth()
{
	return health;
}

int Slime::GetAttack()
{
	return attack;
}

void Slime::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		isAlive = false;
	}

	cout << name << "(이)가 " << damage << "만큼 데미지를 입었습니다!" << endl;
}

void Slime::Attack(Character& character)
{
	character.TakeDamage(attack);
}

void Slime::Dead()
{
	cout << name << "(이)가 죽었습니다!" << endl;
}

bool Slime::GetIsAlive()
{
	return isAlive;
}

void Slime::SetIsAlive(bool alive)
{
	isAlive = alive;
}