#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "FirePotion.h"
#include "PoisonPotion.h"

static const ShopItem* FindShopItem(const vector<ShopItem>& items, int id)
{
	for (const auto& it : items)
		if (it.id == id) return &it;
	return nullptr;
}

Shop::Shop()
{
	items.push_back({ 1, "체력 포션 (+ 50)", 20 });
	items.push_back({ 2, "공격력 포션 (+ 10)", 10 });
	items.push_back({ 3, "화염 포션 (투척)", 50});
	items.push_back({ 4, "독 포션 (투척)",30 });
}

void Shop::PrintShopItems() const
{
	cout << "== 상점 아이템 목록 ==\n";
	for (const auto& it : items)
	{
		cout << "[" << it.id << "]" << it.name << " - 가격: " << it.price << "G\n";
	}
}

void Shop::ShowMenu(Character& player)
{
	cout << "\n[상점] 방문했습니다.\n";

	while (true)
	{
		GameUtils::ClearScreen();
		cout << "\n=== 상점 메뉴 ===\n";
		cout << "현재 보유 골드 : " << player.GetGold() << endl;
		cout << "0. 메뉴판\n";
		cout << "1. 아이템 사기\n";
		cout << "2. 아이템 팔기\n";
		cout << "3. 상점 나가기\n";
		cout << "선택: ";

		int choice;
		cin >> choice;

		if (choice == 0)
		{
			GameUtils::ClearScreen();
			PrintShopItems();
			GameUtils::WaitMs(700);
		}
		else if (choice == 1)
		{
			GameUtils::ClearScreen();
			PrintShopItems();
			cout << "구매할 아이템 번호 입력 : ";
			int id;
			cin >> id;
			BuyItem(player, id);
			GameUtils::WaitMs(700);
		}
		else if (choice == 2)
		{
			GameUtils::ClearScreen();
			auto& inv = player.GetInventory();

			cout << "=== 인벤토리 목록 ===\n";

			if (inv.empty())
			{
				cout << "(비어있음)\n";
			}
			else
			{
				for (int i = 0; i < (int)inv.size(); ++i)
				{
					cout << i << ") " << inv[i]->GetName() << "\n";
				}
			}

			cout << "판매할 아이템 번호 입력: ";
			int inventoryIndex;
			cin >> inventoryIndex;
			SellItem(player, inventoryIndex);
			GameUtils::WaitMs(700);
		}
		else if (choice == 3)
		{
			cout << "상점을 나갑니다.\n";
			GameUtils::WaitMs(400);
			break;
		}
		else
		{
			cout << "잘못된 입력입니다.\n";
			GameUtils::WaitMs(500);
		}
	}
}

bool Shop::BuyItem(Character& player, int itemId)
{
	const ShopItem* item = FindShopItem(items, itemId);
	if (!item)
	{
		cout << "입력한 번호의 아이템이 상점에 없습니다.\n";
		return false;
	}
	if (player.GetGold() < item->price)
	{
		cout << "골드가 부족합니다." << endl;
		return false;
	}
	player.AddGold(-item->price);

	Item* bought = nullptr;

	if (item->id == 1)
	{
		bought = new HealthPotion(50);
	}
	else if (item->id == 2)
	{
		bought = new AttackBoost(10);
	}
	else if (item->id == 3)
	{
		bought = new FirePotion(50);
	}
	else if (item->id == 4)
	{
		bought = new PoisonPotion(30);
	}
	else
	{
		cout << "잘못된 입력입니다.\n";
		player.AddGold(item->price);
		return false;
	}

	player.AddItem(bought);

	cout << "[ 구매 ]" << item->name << "구매 완료!\n";
	GameUtils::WaitMs(400);
	return true;
}

bool Shop::SellItem(Character& player, int inventoryIndex)
{
	auto& inv = player.GetInventory();

	if (inv.empty())
	{
		cout << "인벤토리에 아이템이 없습니다.\n";
		return false;
	}

	if (inventoryIndex < 0 || inventoryIndex >= (int)inv.size())
	{
		cout << "잘못된 입력입니다.\n";
		return false;
	}

	Item* target = inv[inventoryIndex];
	string name = target->GetName();
	int originalPrice = -1;

	for (const auto& it : items)
	{
		if (it.name == name)
		{
			originalPrice = it.price;
			break;
		}
	}

	if (originalPrice < 0)
	{
		cout << "이 아이템은 판매할 수 없습니다.\n";

		return false;
	}

	int sellPrice = static_cast<int>(originalPrice * 0.6);

	delete target;
	inv.erase(inv.begin() + inventoryIndex);

	player.AddGold(sellPrice);

	cout << "[ 판매 ]" << name << "판매 완료! (+" << sellPrice << "G\n";
	GameUtils::WaitMs(400);
	return true;
}