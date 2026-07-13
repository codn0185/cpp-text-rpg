#include "GameManager.h"

#include <iostream>

int main()
{
	GameManager& gm = GameManager::GetInstance();
	gm.run();
}
