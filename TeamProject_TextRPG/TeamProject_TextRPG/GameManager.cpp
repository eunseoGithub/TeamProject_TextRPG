#include "GameManager.h"

GameManager::GameManager()
{
	
}

Monster* GameManager::GenerateMonster(int level)
{
	return new Monster();
}

void GameManager::Battle(Character* character)
{
	
}

const void GameManager::DisplayInventory(const Character* const character)
{

}