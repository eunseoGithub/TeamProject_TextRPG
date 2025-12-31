#include "Monster.h"

Monster::Monster(int level){}

string Monster::GetName()
{
	return name;
}

int Monster::GetHealth()
{
	return health;
}

int Monster::GetAttack()
{
	return attack;
}

void Monster::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		isAlive = false;
	}
	cout << name << "(이)가 " << damage << "만큼 데미지를 입었습니다!" << endl;
}

void Monster::Dead()
{
	cout << name << "(이)가 죽었습니다!" << endl;
}

bool Monster::GetIsAlive()
{
	return isAlive;
}

void Monster::SetIsAlive(bool alive)
{
	isAlive = alive;
}