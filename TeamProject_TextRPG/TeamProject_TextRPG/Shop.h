#pragma once
#include "Global.h"
#include <vector>
#include "GameUtils.h"
#include "Item.h"
class Character;

struct ShopItem
{
	int id;
	string name;
	int price;
	ItemType type;
};

class Shop
{
private:
	vector<ShopItem> items;

public:
	Shop();

	void ShowMenu(Character& player);
	void PrintShopItems() const;

	bool BuyItem(Character& player, int itemId);
	bool SellItem(Character& player, int inventoryIndex);
};