#include "Demon.h"
#include "GameUtils.h"
Demon::Demon(int level)
{
	name = "마왕";
	isAlive = true;
	int maxHealth = level * 45;
	int minHealth = level * 30;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 15;
	int minAttack = level * 8;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;
	isBoss = true;
	cout << "주변의 빛이 모두 사라지고 차가운 정적이 흐릅니다..." << endl;
	GameUtils::WaitMs(300);
	cout << "어둠 속에서 붉게 빛나는 두 눈이 당신을 향합니다." << endl;
	GameUtils::WaitMs(300);
	cout << "[" << name << "] : " << "작은 빛조차 허락되지 않는 이곳이 바로 네 무덤이다." << endl;
	GameUtils::WaitMs(300);
}

void Demon::Attack(Character& character)
{
	character.TakeDamage(attack);
}
