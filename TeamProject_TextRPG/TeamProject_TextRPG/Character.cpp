#include "Character.h"

Character::Character(string name)
{
	this->name = name;
	level = 1;
	maxhp = 200;
	hp = maxhp;
	attack = 30;

	experience = 0;
	gold = 0;

	isAlive = true;
}

void Character::PrintCharacterStatus()
{
	cout << "이름 : " << name << "\n레벨 : " << level << "\n체력 : " << hp << "\n공격력 : " << attack << endl;
}

//공격 하기
void Character::Attack(Monster& monster)
{
	monster.TakeDamage(attack);
}

//공격 받음
void Character::TakeDamage(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
		isAlive = false;
		Dead();
	}
	cout << name << "데미지를 입었습니다." << "남은 hp :" << hp << endl;
}

//죽음
void Character::Dead()
{
	cout << name << "죽었습니다." << endl;
}

//경험치
void Character::AddExperience(int amount)
{
	experience += amount;
	CheckLevelUp();
}

// 경험치 체크, 레벨업
void Character::CheckLevelUp()
{
	if (experience >= 100)
	{
		experience -= 100;
		LevelUp();
	}
}

void Character::LevelUp()
{
	level++;
	maxhp += 20;
	hp = maxhp;
	attack += 5;

	cout << name << "레벨 업! 현재 레벨 : " << level << endl;
}

//아이템 포션
void Character::DrinkPotion()
{
	cout << name << "아이템을 사용했습니다." << endl;
	Item* item = inventory.back();
	inventory.pop_back();
	item->Use();
}

void Character::Heal(int amount)
{
	hp += amount;
	if(hp>maxhp)
	{
		hp = maxhp;
	}
	cout << name << "HP가 회복되었습니다. 현재 HP : " << hp << endl;
}

void Character::AddTempAttack(int amount)
{
	attack += amount;
}

void Character::ResetTempAttack(int amount)
{
	attack -= amount;
}

//인벤토리
void Character::AddItem(Item* item)
{
	inventory.push_back(item);
}

vector<Item*>& Character::GetInventory()
{
	return inventory;
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
void Character::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}
