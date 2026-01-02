#include "AttackBoost.h"
#include <iostream>

AttackBoost::AttackBoost(int bonus)
	: bonusAttack(bonus)
{
}

std::string AttackBoost::GetName() const
{
	return "공격력 증가 (+ 10)";
}

void AttackBoost::Use(Character& character)
{
	character.AddTempAttack(bonusAttack); 
	std::cout << "공격력이 증가하였습니다.\n\n";
}