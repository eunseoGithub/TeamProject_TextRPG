#include "Dragon.h"

Dragon::Dragon(int level)
{
	name = "드래곤";
	isAlive = true;
	int maxHealth = level * 45;
	int minHealth = level * 30;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 15;
	int minAttack = level * 8;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;

	cout << "...쿵. ...쿵! ...쿵!!!" << endl;
	cout << "지면이 흔들리며 거대한 그림자가 당신을 집어삼킵니다." << endl;
	cout << "최종 보스 [" << name << "]가 위압적인 모습으로 나타났습니다!" << endl;
	cout << "[" << name << "] : 감히 내 영역에 발을 들인 대가는... 오직 타오르는 죽음뿐이다." << endl;
}

void Dragon::Attack(Character& character)
{
	character.TakeDamage(attack);
}
