#pragma once
#include "Global.h"
#include "Character.h"
#include "Monster.h"

class Character;
class Monster;
enum class ItemType
{
	HealthPotion = 0,
	AttackBoost = 1,
	FirePotion = 2,
	PoisonPotion = 3
};


class Item 
{
protected:
	ItemType type;

public:
	Item(ItemType t) : type(t) {}
	virtual ~Item() = default;

	ItemType GetType() const
	{
		return type;
	}

	virtual string GetName() const = 0;
	virtual void Use(Character& character) {}
	virtual void Use(Monster& monster) {}
};