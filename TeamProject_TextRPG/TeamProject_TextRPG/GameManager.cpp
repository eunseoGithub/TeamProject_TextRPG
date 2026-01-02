#include "GameManager.h"

static void WaitMs(int ms) {
	this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void GameManager::ClearScreen() const
{
	system("cls");
}

GameManager::GameManager()
{
	srand(time(NULL));
	character = nullptr;
	currentMonster = nullptr;
}

void GameManager::GenerateMonster(int level)
{
	Monster* randMonster;
	if (character->GetLevel() % 10 == 0)
	{
		randMonster = new Boss(level);
	}
	else
	{
		int randType = rand() % 4;

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
	}
	if (randMonster == nullptr)
	{
		cout << "몬스터 생성에 오류가 발생했습니다." << endl;
	}
	currentMonster = randMonster;
	if (currentMonster != nullptr)
	{
		totalMonster.push_back(currentMonster->GetName());
	}
}

bool GameManager::GamePlay()
{
	GenerateMonster(character->GetLevel());
	
	while (true)
	{
		CharacterAct();
		WaitMs(300);

		if(!HandleMonsterDefeat())
			break;
		
		MonsterAct();
		WaitMs(300);
		
		if(!HandleCharacterDefeat())
			return false;
		
		WaitMs(300);
		
	}
	character->ResetTempAttack();
	return true;
}

void GameManager::DisplayInventory()const
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
	cout << "  [ 새로운 모험가 생성 ]                 \n";
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
	if (rand() % 10 < 8)
	{
		character->Attack(*currentMonster);
	}
	else
	{
		character->DrinkPotion();
	}
	WaitMs(300);
	Render();
}
//
//void MonsterTickDamage()
//{
//	if (monster->GetIsPoison() == true)
//	{
//		character->PoisonAttack(monster,character->GetLevel() *5);
//	}
//}

void GameManager::MonsterAct()
{
	currentMonster->Attack(*character);
	WaitMs(300);
	Render();
}

void GameManager::Render() const
{
	ClearScreen();
	DisplayInventory();
	character->PrintCharacterStatus();
	if (currentMonster != nullptr)
	{
		currentMonster->PrintMonsterStatus();
	}
}

void GameManager::GameWin()
{
	cout << "게임에서 승리했습니다." << endl;
	PrintTotalMonster();
	DeleteMember();
}

void GameManager::GameLose()
{
	cout << "게임에서 패배했습니다." << endl;
	PrintTotalMonster();
	DeleteMember();
}

void GameManager::PrintTotalMonster() const
{
	if (totalMonster.empty())
	{
		cout << "잡은 몬스터가 없습니다." << endl;
		return;
	}
	cout << "\n===========================\n";
	cout << "  [ 싸운 몬스터 목록 ]                 \n";
	cout << "===========================\n";
	int index = 1;
	for (auto& mon : totalMonster)
	{
		cout << index++ << ". " << mon << endl;
	}
}

bool GameManager::HandleMonsterDefeat()
{
	if (currentMonster == nullptr)
	{
		return false;
	}
	if (!currentMonster->GetIsAlive())
	{
		currentMonster->Dead();
		character->AddExperience(100);
		WaitMs(300);
		int randomGold = rand() % 11 + 10;
		character->AddGold(randomGold);

		if (rand() % 10 < 3)
		{
			Item* item = (rand() % 2 == 0) ? (Item*)new AttackBoost() : (Item*)new HealthPotion();
			character->AddItem(item);
		}
		delete currentMonster;
		currentMonster = nullptr;
		return false;
	}
	return true;
}

bool GameManager::HandleCharacterDefeat()
{
	if (!character->GetIsAlive())
	{
		character->Dead();
		GameLose();
		WaitMs(300);
		return false;
	}
	/*if (character->GetLevel() >= 10)
	{
		GameWin();
		return false;
	}*/
	return true;
}

void GameManager::DeleteMember()
{
	if (currentMonster != nullptr)
	{
		delete currentMonster;
		currentMonster = nullptr;
	}
	if (character != nullptr)
	{
		delete character;
		character = nullptr;
	}
}