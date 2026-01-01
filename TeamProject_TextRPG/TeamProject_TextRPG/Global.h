#pragma once
#include <iostream>
#include <string>

using namespace std;

enum MonsterType
{
	troll = 0,
	orc,
	slime,
	goblin,
};
extern MonsterType gMonsterType;