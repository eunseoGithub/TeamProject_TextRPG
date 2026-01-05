#include "Monster.h"

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

void Monster::TakeTickDamage(int damage)
{
	if (isPoison == true)
	{
		health -= damage;
		if (health <= 0)
		{
			isAlive = false;
		}
		cout << name << "(이)가 " << damage << "만큼 독데미지를 입었습니다!" << endl;
		tickCount++;
	}
	if (tickCount >= 3)
	{
		isPoison = false;
	}
}

int Monster::GetIsPoison()
{
	return isPoison;
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

void Monster::PrintMonsterStatus()
{
	cout << "===========================\n";
	cout << "   [ 몬스터 스 텟 창 ]                         \n";
	cout << "===========================\n";
	cout << "이름 : " << name << endl;
	cout << "공격력 : " << attack << endl;
	cout << "HP : " << health << endl;
	cout << "===========================\n";
}