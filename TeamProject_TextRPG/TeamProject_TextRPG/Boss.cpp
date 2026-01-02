#include "Boss.h"

Boss::Boss(int level)
{
	name = "보스";
	isAlive = true;
	int maxHealth = level * 45;
	int minHealth = level * 30;
	health = rand() % (maxHealth - minHealth + 1) + minHealth;

	int maxAttack = level * 15;
	int minAttack = level * 8;
	attack = rand() % (maxAttack - minAttack + 1) + minAttack;

	cout << "\"보스몬스터\"가 등장했습니다." << endl;

	// 연출을 추가할 경우(각 대사마다 시간차)
	/*cout << "...쿵. ...쿵! ...쿵!!!" << endl;
	cout << "어디선가 거대한 발자국 소리가 들려옵니다." << endl;
	cout << "최종 보스 [" << name << "]가 앞을 등장했습니다!" << endl;
	cout << "["<< name << "] : 내 앞을 가로막은 대가는... 오직 죽음뿐이다." << endl;*/
}

void Boss::Attack(Character& character)
{
	character.TakeDamage(attack);
}
