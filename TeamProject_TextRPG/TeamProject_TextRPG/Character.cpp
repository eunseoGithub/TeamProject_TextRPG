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
	bonusAttack = 0;
	isAlive = true;
}

void Character::PrintCharacterStatus()
{
	cout << "===========================\n";
	cout << "   [ 캐 릭 터 스 텟 창 ]                         \n";
	cout << "===========================\n";
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "HP : " << hp << "/" << maxhp << endl;
	cout << "공격력 : " << attack << endl;
	cout << "보유 골드 : " << gold << endl;
	cout << "===========================\n";
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
	cout << name << "이(가) 데미지를 입었습니다." << "남은 hp :" << hp << endl;
}

//죽음
void Character::Dead()
{
	cout << name << "이(가) 죽었습니다." << endl;
}

//경험치
void Character::AddExperience(int amount)
{
	experience += amount;
	CheckLevelUp();
}

void Character::AddGold(int amount)
{
	gold += amount;
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

	cout << name << "***레벨 업! 현재 레벨 : " << level  << "***" << endl;
}

//아이템 포션
void Character::DrinkPotion()
{
	cout << name << "이(가) 아이템 사용을 시도합니다." << endl;
	if (inventory.empty())
	{
		cout << name << "이(가) 사용할 아이템이 없습니다." << endl << endl;
		return;
	}
	cout << name << "이(가) 아이템을 사용했습니다." << endl;
	Item* item = inventory.back();
	inventory.pop_back();
	item->Use(*this);
	
	delete item;
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
	bonusAttack = amount;
	attack += amount;
}

void Character::ResetTempAttack()
{
	if (bonusAttack != 0)
	{
		attack -= bonusAttack;
		bonusAttack = 0;
	}
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

int Character::GetLevel()
{
	return level;
}

bool Character::GetIsAlive()
{
	return isAlive;
}

