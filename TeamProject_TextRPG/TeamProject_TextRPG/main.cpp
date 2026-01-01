#include "Global.h"
#include "GameManager.h"

int main()
{
	GameManager* game = new GameManager();
	if (!game->CreateCharacter())
		return 0;
	system("cls");
	while (true)
	{
		game->Render();
		if (!game->GamePlay())
		{
			break;
		}
	}

}