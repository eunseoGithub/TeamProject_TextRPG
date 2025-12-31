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
	// character.AddTempAttack(bonusAttack); // 수정해야 함
	std::cout << "공격력이 증가하였습니다.\n";
}