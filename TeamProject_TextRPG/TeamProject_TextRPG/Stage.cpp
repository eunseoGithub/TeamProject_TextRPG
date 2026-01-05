#include "Stage.h"
#include <cstdlib>
#include "Monster.h"

#include "Troll.h"
#include "Orc.h"
#include "Slime.h"
#include "Goblin.h"
#include "Dragon.h"

#include "Demon.h"
#include "Ghost.h"
#include "Golem.h"
#include "Medusa.h"
#include "Ogre.h"

#include "Global.h"

Stage::Stage(int stageIndex, int bossLevelThreshold)
{
	this->stageIndex = stageIndex;
	this->bossLevelThreshold = bossLevelThreshold;
}

int Stage::GetStageIndex() const
{
	return stageIndex;
}

int Stage::GetBossLevelThreshold() const
{
	return bossLevelThreshold;
}

Monster* Stage::SpawnNextMonster(int playerLevel) const
{
	if (playerLevel >= bossLevelThreshold)
	{
		return SpawnBoss(playerLevel);
	}

	return SpawnRandomNormalMonster(playerLevel);
}

Monster* Stage::SpawnBoss(int level) const
{
	if (stageIndex == 1) return new Dragon(level);
	if (stageIndex == 2) return new Demon(level);
}

Monster* Stage::SpawnRandomNormalMonster(int level) const
{
	int randType = rand() % 4;

	if (stageIndex == 1)
	{
		switch (randType)
		{
		case troll:
			return new Troll(level);
			break;
		case orc:
			return new Orc(level);
			break;
		case slime:
			return new Slime(level);
			break;
		case goblin:
			return new Goblin(level);
			break;
		default:
			return nullptr;
			break;
		}
	}
	else if (stageIndex == 2)
	{
		switch (randType)
		{
		case ghost:
			return new Ghost(level);
			break;
		case golem:
			return new Golem(level);
			break;
		case medusa:
			return new Medusa(level);
			break;
		case ogre:
			return new Ogre(level);
			break;
		default:
			return nullptr;
			break;
		}
	}
	return nullptr;
}
