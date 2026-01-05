#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion(int heal)
	: Item(ItemType::HealthPotion), healAmount(heal) {
}

string HealthPotion::GetName() const
{
	return "체력 포션 (+ 50)";
}

void HealthPotion::Use(Character& character)
{
	character.Heal(healAmount);
	cout << "체력 포션을 사용했습니다.\n";
}