#pragma once
#include <vector>
class Monster;
class Stage
{
public:
	Stage(int stageIndex, int bossLevelThreshold);

	Monster* SpawnNextMonster(int playerLevel) const;

	int GetStageIndex() const;
	int GetBossLevelThreshold() const;
private:
	int stageIndex;
	int bossLevelThreshold;

	Monster* SpawnRandomNormalMonster(int level) const;

	Monster* SpawnBoss(int level) const;
};

