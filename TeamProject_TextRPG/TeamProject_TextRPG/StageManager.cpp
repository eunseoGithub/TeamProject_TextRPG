#include "StageManager.h"
#include "Stage.h"

StageManager::StageManager() :currentStageIdx(0)
{
	stages.push_back(new Stage(1, 10));
	stages.push_back(new Stage(2, 20));
}

StageManager::~StageManager()
{
	for (Stage* s : stages)
		delete s;
	stages.clear();
}

Monster* StageManager::RequestNextMonster(int playerlevel)
{
	if (currentStageIdx < 0 || currentStageIdx >= stages.size())
	{
		return nullptr;
	}
	return stages[currentStageIdx]->SpawnNextMonster(playerlevel);
}

bool StageManager::OnBossDefeated()
{
	currentStageIdx++;

	return currentStageIdx >= (int)stages.size();
}

int StageManager::GetCurrentStageIndex() const
{
	if (currentStageIdx < 0 || currentStageIdx >= stages.size())
		return -1;
	return stages[currentStageIdx]->GetStageIndex();
}