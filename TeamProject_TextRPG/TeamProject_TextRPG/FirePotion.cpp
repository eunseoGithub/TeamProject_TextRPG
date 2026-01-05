#include "FirePotion.h"
#include "Monster.h"

FirePotion::FirePotion(int dmg)
	: Item(ItemType::FirePotion), damage(dmg)
{
}

string FirePotion::GetName() const
{
	return "화염 포션 (투척)";
}

void FirePotion::Use(Monster& monster)
{
	monster.TakeDamage(damage);
	cout << "화염 포션을 투척했습니다! (" << damage << "데미지)\n";
}