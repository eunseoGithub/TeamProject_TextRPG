#include "GameManager.h"

inline std::string WStringToUTF8(const std::wstring& wstr)
{
	if (wstr.empty()) return {};

	// WideCharToMultiByte는 "문자 수" 기준이므로, wstr.size()를 int로 캐스팅
	int srcLen = static_cast<int>(wstr.size());

	// 필요한 바이트 수 계산 (널문자 제외)
	int needed = ::WideCharToMultiByte(
		CP_UTF8,
		0,
		wstr.data(),
		srcLen,
		nullptr,
		0,
		nullptr,
		nullptr
	);

	std::string out;
	out.resize(needed);

	// writable 버퍼는 &out[0]가 가장 호환성이 좋음
	::WideCharToMultiByte(
		CP_UTF8,
		0,
		wstr.data(),
		srcLen,
		&out[0],
		needed,
		nullptr,
		nullptr
	);

	return out;
}

GameManager::GameManager()
{
	srand(time(NULL));
	character = nullptr;
	currentMonster = nullptr;
	shopManager = new Shop();
}

bool GameManager::GamePlay()
{
	currentMonster = stageManager.RequestNextMonster(character->GetLevel());
	if (!currentMonster)
	{
		cout << "몬스터 생성에 오류가 발생했습니다." << endl;
		return false;
	}
	totalMonster.push_back(currentMonster->GetName());

	while (true)
	{
		CharacterAct();
		GameUtils::WaitMs(500);
		
		if(currentMonster->GetIsPoison())
			currentMonster->TakeTickDamage(character->GetLevel() * 5);
		
		if(!HandleMonsterDefeat())
			break;
		
		MonsterAct();
		GameUtils::WaitMs(500);
		
		if(!HandleCharacterDefeat())
			return false;
		
		GameUtils::WaitMs(500);
		
	}
	character->ResetTempAttack();
	if (VisitShop())
	{
		shopManager->ShowMenu(*character);
	}
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
		int index = 0;
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
	cout << "모험가의 이름을 정해주세요 : ";

	wstring name= GameUtils::ReadWLine();
	string realName = WStringToUTF8(name);
	while (true)
	{
		GameUtils::WaitMs(500);
		GameUtils::ClearScreen();
		cout << "\n===========================\n";
		cout << "  [ 모험가 직업 ]                 \n";
		cout << "1. 전사 (Warrior)\n";
		cout << "2. 마법사 (Magician)\n";
		cout << "===========================\n";
		cout << "모험가의 직업을 정해주세요(1 선택 시 전사) :";

		wstring input = GameUtils::ReadWLine();
		if (input == L"1" || input == L"전사" || input == L"warrior" || input == L"Warrior")
		{
			character = new Warrior(realName);
			break;
		}

		if (input == L"2" || input == L"마법사" || input == L"magician" || input == L"Magician")
		{
			character = new Magician(realName);
			break;
		}
		cout << "직업을 잘못 입력하셨습니다. 1,2 또는 직업 이름을 영문 또는 한글로 입력해주세요.\n";
	}
	
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
		if (!character->GetInventory().empty())
		{
			cout << "===========================\n";
			cout << "   [ 아 이 템 선 택 창 ]                         \n";
			cout << "===========================\n";
			int index;
			GameUtils::ReadInt("사용할 포션 번호를 입력하세요. : ", index);
			character->DrinkPotion(index, *currentMonster);
		}
		else
		{
			cout << "인벤토리에 아무것도 없습니다." << endl;
		}
	}
	GameUtils::WaitMs(500);
	Render();
}

void GameManager::MonsterAct()
{
	currentMonster->Attack(*character);
	GameUtils::WaitMs(500);
	Render();
}

void GameManager::Render() const
{
	GameUtils::ClearScreen();
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
		bool isBoss = currentMonster->GetIsBoss();

		currentMonster->Dead();
		character->AddExperience(50);
		GameUtils::WaitMs(500);
		
		int randomGold = rand() % 11 + 10;
		character->AddGold(randomGold);

		if (rand() % 10 < 3)
		{
			Item* item = (rand() % 2 == 0) ? (Item*)new AttackBoost() : (Item*)new HealthPotion();
			character->AddItem(item);
		}
		if (rand() % 10 < 1)
		{
			Item* item = (rand() % 2 == 0) ? (Item*)new PoisonPotion() : (Item*)new FirePotion();
			character->AddItem(item);
		}
		delete currentMonster;
		currentMonster = nullptr;
		
		if (isBoss)
		{
			bool isGameClear = stageManager.OnBossDefeated();
			if (isGameClear && character->GetLevel()>=20)
			{
				GameWin();
				return false;
			}
			else
			{
				cout << "다음 스테이지로 이동합니다..." << endl;
			}
		}
		
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
		GameUtils::WaitMs(500);
		return false;
	}
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
	if (shopManager != nullptr)
	{
		delete shopManager;
		shopManager = nullptr;
	}
}

bool GameManager::VisitShop()
{
	cout << "\n===========================\n";
	cout << "  [ 상 점 방 문 여 부]                 \n";
	cout << "===========================\n";
	cout << "상점을 방문을 하시겠습니까? >(Yes : 1, No : 0)";
	
	string input;
	cin >> input;
	
	if (input == "1" || input == "Yes" || input == "yes" || input == "Y" || input == "y")
		return true;
	
	if (input == "0" || input == "N0" || input == "no" || input == "N" || input == "n")
		return false;
	
	cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
	return VisitShop();

}