#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost(int bonus)
	: Item(ItemType::AttackBoost), bonusAttack(bonus)
{
}

string AttackBoost::GetName() const
{
	return "공격력 증가 (+ 10)";
}

void AttackBoost::Use(Character& character)
{
	character.AddTempAttack(bonusAttack); 
	cout << "공격력이 증가하였습니다.\n";
}