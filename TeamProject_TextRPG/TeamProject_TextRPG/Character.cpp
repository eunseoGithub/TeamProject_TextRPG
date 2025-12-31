#include "Character.h"

Character::Character(string name)
{
	this->name = name;
	level = 1;
	hp = 100;
	attack = 10;
}

void Character::PrintCharacterStatus()
{
	cout << "이름 : " << name << "레벨 : " << level << "체력 : " << hp << "공격력 : " << attack << endl;
}

string Character::GetName()
{
	return name;
}
int Character::GetLevel()
{
	return level;
}
int Character::GetHp()
{
	return hp;
}
int Character::GetMaxHp()
{
	return maxhp;
}
int Character::GetAttack()
{
	return attack;
}
int Character::GetExperience()
{
	return experience;
}
int Character::GetGold()
{
	return gold;
}
int Character::GetInventory()
{
	return inventory;
}
bool Character::GetIsAlive()
{
	return isAlive;
}


void Character::SetName(string name)
{
	this->name = name;
}
void Character::SetHp(int hp)
{
	this->hp = hp;
}
void Character::SetMaxHp(int maxhp)
{
	this->maxhp = maxhp;
}
void Character::SetAttack(int attack)
{
	this->attack = attack;
}
void Character::SetExperience(int experience)
{
	this->experience = experience;
}
void Character::SetGold(int gold)
{
	this->gold = gold;
}
void Character::SetInventory(int inventory)
{
	this->inventory = inventory;
}
void Character::TakeDamage(int damage)
{
	this->damage = damage;

	hp = hp - damage;
	if (hp <= 0)
	{
		isAlive = false;
	}
	cout << name << "데미지를 입었습니다." << "남은 hp :" << hp << endl;
}

void Character::Attack(Monster& monster)
{
	//monster.TakeDamage
    // (attack)
}

void Character::LevelUp()
{
	level += 1;
}

void Character::Dead()
{
	cout << name << "이 죽었습니다" << endl;
}

void Character::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}
