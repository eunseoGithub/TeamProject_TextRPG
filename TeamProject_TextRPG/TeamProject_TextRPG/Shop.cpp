#include "Shop.h"
#include "Character.h"


Shop::Shop()
{
	items.push_back({ 1, "체력 포션 (+ 50)", 20 });
	items.push_back({ 2, "공격력 포션 (+ 10)", 10 });
}

void Shop::ShowMenu(Character& player)
{
	cout << "\n[상점] 방문했습니다.\n";

	while (true)
	{
		cout << "\n=== 상점 메뉴 ===\n";
		cout << "0. 메뉴판\n";
		cout << "1. 아이템 사기\n";
		cout << "2. 아이템 팔기\n";
		cout << "3. 상점 나가기\n";
		cout << "선택: ";

		int choice;
		cin >> choice;

		if (choice == 0)
		{
			PrintShopItems();
		}
		else if (choice == 1)
		{
			PrintShopItems();
			cout << "구매할 아이템 ID 입력: ";
			int id;
			cin >> id;
			BuyItem(player, id);
		}
		else if (choice == 2)
		{
			cout << "=== 내 인벤토리(ID) ===\n";
			const auto& inv = player.GetInventory();
			if (inv.empty())
			{
				cout << "(비어있음)\n";
			}
			else
			{
				for (int id : inv) cout << id << " ";
				cout << "\n";
			}

			cout << "판매할 아이템 ID 입력: ";
			int id;
			cin >> id;
			SellItem(player, id);
		}
		else if (choice == 3)
		{
			cout << "[상점] 나갑니다.\n";
			break;
		}
		else
		{
			cout << "잘못된 입력입니다.\n";
		}
	}
}

bool Shop::BuyItem(Character& player, int itemId)
{
	const ShopItem* item = FindShopItem(items, itemId);
	if (!item)
	{
		cout << "아이템 ID가 상점에 없습니다.\n";
		return false;
	}

	if (player.GetGold() < item->price)
	{
		cout << "골드가 부족합니다.\n";
		return false;
	}

	player.AddGold(-item->price);

	player.GetInventory().push_back(item->id);

	cout << "[ 구매 ]" << item->name << "구매 완료 (남은 골드: " << player.GetGold() << "G)\n";
}

void Shop::PrintShopItems() const
{
	cout << "== 상점 아이템 목록 ==\n";
	for (const auto& it : items)
	{
		cout << "[" << it.id << "]" << it.name << " - 가격: " << it.price << "G\n";
	}
}

static const ShopItem* FindShopItem(const vector<ShopItem>& items, int id)
{
	for (const auto& it : items)
		if (it.id == id) return &it;
	return nullptr;
}

bool Shop::SellItem(Character& player, int itemId)
{
	const ShopItem* item = FindShopItem(items, itemId);

	if (it == inv.end())
	{
		cout << "인벤토리에 아이템이 없습니다.\n";
		return false;
	}

	int sellPrice = static_cast<int>(item->price * 0.6);

	inv.erase(it);


	player.AddGold(sellPrice);

	cout << "[ 판매 ] " << item->name << " 판매 완료 (+"
	<< sellPrice << "G, 현재 골드: " << player.GetGold() << "G)\n";
	return true;
}
