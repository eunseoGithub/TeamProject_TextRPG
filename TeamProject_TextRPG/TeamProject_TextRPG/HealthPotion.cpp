#include "HealthPotion.h"
#include <iostream>

HealthPotion::HealthPotion(int heal)
	: healAmount(heal)
{
}

std::string HealthPotion::GetName() const
{
	return "체력 포션 (+ 50)";
}

void HealthPotion::Use(Character& character)
{
	character.Heal(healAmount);
	std::cout << "체력 포션을 사용했습니다.\n\n";
}