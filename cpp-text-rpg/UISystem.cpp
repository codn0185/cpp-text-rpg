#include "UISystem.h"

#include <iostream>

void UISystem::PrintPlayerStat(Player* player)
{
	string jobName;
	switch (player->getJob())
	{
	case EPlayerJob::None:
		jobName = "무직";
		break;
	case EPlayerJob::Archer:
		jobName = "궁수";
		break;
	case EPlayerJob::Mage:
		jobName = "마법사";
		break;
	case EPlayerJob::Rogue:
		jobName = "도적";
		break;
	case EPlayerJob::Warrior:
		jobName = "전사";
		break;
	default:
		break;
	}
	string hpText = "HP: " + to_string(player->getCurrentHP()) + "/" + to_string(player->getMaxHP());
	string mpText = "HP: " + to_string(player->getCurrentMP()) + "/" + to_string(player->getMaxMP());
	string powerText = "공격력: " + to_string(player->getPower());
	string defenceText = "방어력: " + to_string(player->getDefence());

	cout << "===============================================================" << "\n";
	cout << "닉네임: " << player->getName() << " | 직업: " << jobName << " | 레벨: " << player->getLevel() << "\n";
	cout << "---------------------------------------------------------------" << "\n";
	cout << hpText << " | " << mpText << " | " << powerText << " | " << defenceText << "\n";
	cout << "===============================================================" << "\n";
}

