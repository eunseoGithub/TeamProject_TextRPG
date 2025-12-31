#include "Troll.h"

Troll::Troll(int level)
{
	name = "트롤";
	isAlive = true;
	int maxHealth = level * 30;
	int minHealth = level * 20;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 10;
	int minAttack = level * 5;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
}

string Troll::GetName()
{
	return name;
}

int Troll::GetHealth()
{
	return health;
}

int Troll::GetAttack()
{
	return attack;
}

void Troll::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0) 
	{
		isAlive = false;
	}

	cout << name << "(이)가 " << damage << "만큼 데미지를 입었습니다!" << endl;
}

void Troll::Attack(Character& character)
{
	character.TakeDamage(attack);
}

void Troll::Dead()
{
	cout << name << "(이)가 죽었습니다!" << endl;
}

bool Troll::GetIsAlive()
{
	return isAlive;
}

void Troll::SetIsAlive(bool alive)
{
	isAlive = alive;
}