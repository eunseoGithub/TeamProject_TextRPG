#include "GameUtils.h"
#include <thread>
#include <chrono>
#include <cstdlib>

namespace GameUtils
{
	void WaitMs(int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void ClearScreen()
	{
		system("cls");
	}
}