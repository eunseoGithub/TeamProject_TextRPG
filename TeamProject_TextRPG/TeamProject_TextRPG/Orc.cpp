#include "Orc.h"

Orc::Orc(int level)
{
	name = "오크";
	isAlive = true;
	int maxHealth = level * 30;
	int minHealth = level * 20;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 10;
	int minAttack = level * 5;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
}

string Orc::GetName()
{
	return name;
}

int Orc::GetHealth()
{
	return health;
}

int Orc::GetAttack()
{
	return attack;
}

void Orc::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		isAlive = false;
	}

	cout << name << "(이)가 " << damage << "만큼 데미지를 입었습니다!" << endl;
}

void Orc::Attack(Character& character)
{
	character.TakeDamage(attack);
}

void Orc::Dead()
{
	cout << name << "(이)가 죽었습니다!" << endl;
}

bool Orc::GetIsAlive()
{
	return isAlive;
}

void Orc::SetIsAlive(bool alive)
{
	isAlive = alive;
}