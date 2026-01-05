#pragma once
#include <vector>
#include <memory>
#include "Global.h"
class Stage;
class Monster;

class StageManager
{
public:
	StageManager();

	Monster* RequestNextMonster(int playerLevel);

	bool OnBossDefeated();
	int GetCurrentStageIndex() const;
	~StageManager();
private:
	vector<Stage*> stages;
	int currentStageIdx;
};

