#include "Stage.h"
#include <cstdlib>
#include "Monster.h"

#include "Boss.h"
#include "Troll.h"
#include "Orc.h"
#include "Slime.h"
#include "Goblin.h"
// 스테이지 2용 몬스터 header 추가
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
	//if (stageIndex == 1) return Stage1Boss(level);
	//if (stageIndex == 2) return Stage2Boss(level);
	return new Boss(level);
}

Monster* Stage::SpawnRandomNormalMonster(int level) const
{
	int randType = rand() % 4;

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

	/*if (stageIndex == 1)
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
	}*/
	return nullptr;
}
