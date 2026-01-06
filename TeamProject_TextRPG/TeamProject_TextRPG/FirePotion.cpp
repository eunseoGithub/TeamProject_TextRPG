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

void FirePotion::Use(Character& character, Monster& monster)
{
	int damage = character.GetLevel() * 20;
	cout << "화염 포션을 투척했습니다! (" << damage << "데미지)\n";
	character.PotionAttack(monster, damage);
	
}