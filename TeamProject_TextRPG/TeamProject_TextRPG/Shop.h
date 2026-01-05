#pragma once
#include "Global.h"
#include <vector>
#include <memory>
#include "GameUtils.h"

class Character;
class Item;

struct ShopItem
{
	int id;
	string name;
	int price;
};

class Shop
{
private:
	vector<ShopItem> items;

	vector<Item*> pool[4];

	vector<unique_ptr<Item>> owned;

	Item* CreateItemById(int id);
	Item* AcquireItemById(int id);

public:
	Shop();

	void ShowMenu(Character& player);
	void PrintShopItems() const;

	bool BuyItem(Character& player, int itemId);
	bool SellItem(Character& player, int inventoryIndex);

	void ReleaseItem(Item* item);
};