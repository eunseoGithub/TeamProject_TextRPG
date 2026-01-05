#pragma once
#include <iostream>
#include <string>

using namespace std;

enum StageOneMonsterType
{
	troll = 0,
	orc,
	slime,
	goblin,
};
enum StageTwoMonsterType
{
	ghost = 0,
	golem,
	medusa,
	ogre,
};
extern StageOneMonsterType gOneMonsterType;
extern StageTwoMonsterType gTwoMonsterType;