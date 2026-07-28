#include "GameManager.h"

int main()
{
	GameManager& gm = GameManager::GetInstance();
	gm.run();
}
