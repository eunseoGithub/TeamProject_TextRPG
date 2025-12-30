#include "Goblin.h"

Goblin::Goblin(int level)
{
	name = "고블린";
	isAlive = true;
	int maxHealth = level * 30;
	int minHealth = level * 20;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 10;
	int minAttack = level * 5;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
}

string Goblin::GetName()
{
	return name;
}

int Goblin::GetHealth()
{
	return health;
}

int Goblin::GetAttack()
{
	return attack;
}

void Goblin::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0) 
	{
		isAlive = false;
	}

	cout << name << "(이)가 " << damage << "만큼 데미지를 입었습니다!" << endl;
}

void Goblin::Attack(Character& character)
{
	//character.TakeDamage(attack);
}

void Goblin::Dead()
{
	cout << name << "(이)가 죽었습니다!" << endl;
}

bool Goblin::GetIsAlive()
{
	return isAlive;
}

void Goblin::SetIsAlive(bool alive)
{
	isAlive = alive;
}