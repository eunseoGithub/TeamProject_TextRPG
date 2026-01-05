#pragma once
#include "Global.h"
#include "Monster.h"
#include "Item.h"
#include <vector>
#include <cstdarg>
#include <type_traits>
#include <utility>

class Item;
class Monster;
class Character
{
public:
	Character(string name);

	//상태 출력
	void PrintCharacterStatus();

	virtual void Attack(Monster& monster);
	void TakeDamage(int damage);
	void Dead();

	//경험치 / 레벨
	void LevelUp();
	void CheckLevelUp();
	void AddExperience(int amount);

	//아이템 효과
	void Heal(int amount);
	void AddTempAttack(int amount);
	void ResetTempAttack();
	void DrinkPotion(int index, Monster& monster);
	void PotionAttack(Monster& monster, int damage);
	void AddGold(int amount);

	//인벤토리
	template<typename ItemImpl, class... Args>
	std::enable_if_t <std::is_base_of_v<Item, ItemImpl>>
	AddItem(Args&&... args)
	{
		Item* item = new ItemImpl(std::forward<Args>(args)...);
		inventory.push_back(item);
	}
	void AddItem(Item* item);
	vector<Item*>& GetInventory();

	int GetLevel();
	bool GetIsAlive();
	int GetGold();

	void SetIsAlive(bool isAlive);

protected:

	string name;

	int level;
	int hp;
	int maxhp;
	int attack;

	int experience;
	int gold;
	int bonusAttack;

	vector<Item*> inventory;

	bool isAlive;
	
};

