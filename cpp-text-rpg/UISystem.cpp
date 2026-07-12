#include "UISystem.h"

#include <iostream>

void UISystem::printPlayerStat(Player* player)
{
	cout << "\n\n";
	cout << "===========================================" << "\n";
	cout << "        " + player->getName() + " 의 현재 능력치        " << "\n";
	cout << "===========================================" << "\n";
	cout << "HP: " + to_string(player->getHP()) + "     MP: " + to_string(player->getMP()) << "\n";
	cout << "공격력: " + to_string(player->getPower()) + "     방어력: " + to_string(player->getDefence()) << "\n";
	cout << "===========================================" << "\n";
	cout << "\n\n";
}