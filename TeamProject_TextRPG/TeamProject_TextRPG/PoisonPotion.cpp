#include "PoisonPotion.h"
#include "Monster.h"

PoisonPotion::PoisonPotion(int dmg)
	: Item(ItemType::PoisonPotion), damage(dmg)
{
}

string PoisonPotion::GetName() const
{
	return "독 포션 (투척)";
}

void PoisonPotion::Use(Character& character)
{
	cout << "독 포션을 투척했습니다! (" << damage << "데미지)\n";
}