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
	cout << name << "(??媛 " << damage << "留뚰겮 ?곕?吏瑜??낆뿀?듬땲??" << endl;
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
	}
}

void Monster::Dead()
{
	cout << name << "(??媛 二쎌뿀?듬땲??" << endl;
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
	cout << "   [ 紐ъ뒪??????李?]                         \n";
	cout << "===========================\n";
	cout << "?대쫫 : " << name << endl;
	cout << "怨듦꺽??: " << attack << endl;
	cout << "HP : " << health << endl;
	cout << "===========================\n";
}