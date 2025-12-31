#include "GameManager.h"

GameManager::GameManager()
{
	srand(time(NULL));
	character = nullptr;
	currentMonster = nullptr;
}

void GameManager::GenerateMonster(int level)
{
	int randType = rand() % 4;
	Monster* randMonster;
	switch (randType)
	{
	case troll:
		randMonster = new Troll(level);
		break;
	case orc:
		randMonster = new Orc(level);
		break;
	case slime:
		randMonster = new Slime(level);
		break;
	case goblin:
		randMonster = new Goblin(level);
		break;
	default:
		randMonster = nullptr;
	}
	if (randMonster == nullptr)
	{
		cout << "몬스터 생성에 오류가 발생했습니다." << endl;
	}
	currentMonster = randMonster;
}

bool GameManager::GamePlay()
{
	GenerateMonster(character->GetLevel());
	while (true)
	{
		CharacterAct();
		MonsterAct();
		if (!character->GetIsAlive())
		{
			character->Dead();
			GameLose();
			return false;
		}
		if (!currentMonster->GetIsAlive())
		{
			currentMonster->Dead();
			character->AddExperience(50);
			
			int randomGold = rand() % 11 + 10;
			character->SetGold(character->GetGold() + randomGold);

			if (rand() % 10 < 3)
			{
				Item* item;
				if (rand() % 2 == 0)
				{
					item = new AttackBoost();
				}
				else
				{
					item = new HealthPotion();
				}
				character->AddItem(item);
			}

			currentMonster = nullptr;
			break;
		}
		if (character->GetLevel() >= 10)
			return true;
	}
	return true;
}

const void GameManager::DisplayInventory()
{
	const vector<Item*>& inventory = character->GetInventory();

	cout << "\n===========================\n";
	cout << "      [ 인 벤 토 리 ]                         \n";
	cout << "===========================\n";
	if (inventory.empty())
	{
		cout << "보유 중인 아이템이 없습니다.\n";
	}
	else
	{
		int index = 1;
		for (auto& item : character->GetInventory())
		{
			cout << index++ << ". " << item->GetName() << endl;
		}
	}
	cout << "===========================\n";
}

bool GameManager::CreateCharacter()
{
	cout << "\n===========================\n";
	cout << "     [ 새로운 모험가 생성 ]                 \n";
	cout << "===========================\n";
	cout << "캐릭터의 이름을 정해주세요 : ";
	string name;
	cin >> name;
	character = new Character(name);
	if (character == nullptr)
	{
		cout << "캐릭터 생성에 실패하였습니다. 게임을 종료합니다." << endl;
		return false;
	}
	return true;
}


void GameManager::CharacterAct()
{
	if (rand() % 2 == 0)
	{
		character->Attack(*currentMonster);
	}
	else
	{
		character->DrinkPotion();
	}
}
void GameManager::MonsterAct()
{
	currentMonster->Attack(*character);
}
void GameManager::Render()
{
	DisplayInventory();
	character->PrintCharacterStatus();
}

void GameManager::GameWin()
{
	cout << "게임에서 승리했습니다." << endl;
}

void GameManager::GameLose()
{
	cout << "게임에서 패배했습니다." << endl;
}