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

	cout << "=====================================================" << "\n";
	cout << "닉네임: " << player->getName() << " | 직업: " << jobName << " | 레벨: " << player->getLevel() << "\n";
	cout << "-----------------------------------------------------" << "\n";
	cout << "HP: " << player->getHP() << " | MP: " << player->getMP() << "| 공격력: " << player->getPower() << " | 방어력: " << player->getDefence() << "\n";
	cout << "=====================================================" << "\n";
}

