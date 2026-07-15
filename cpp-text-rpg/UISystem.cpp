#include "UISystem.h"

#include "LevelSystem.h"

#include <iostream>

using namespace std;

const map<EPlayerJob, string> UISystem::jobNames = {
	{EPlayerJob::None, "무직"},
	{EPlayerJob::Archer, "궁수"},
	{EPlayerJob::Mage, "마법사"},
	{EPlayerJob::Rogue, "도적"},
	{EPlayerJob::Warrior, "전사"},
};

void UISystem::PrintPlayerStat(Player* player)
{
	string nameText = "닉네임: " + player->getName();
	string jobText = "직업: " + jobNames.at(player->getJob());
	int level = player->getLevel();
	int exp = player->getExp();
	int requiredExp = LevelSystem::GetRequiredExp(player);
	string levelText = "레벨: " + to_string(level) + " (" + to_string(exp) + "/" + to_string(requiredExp) + ")";

	string hpText = "HP: " + to_string(player->getCurrentHP()) + "/" + to_string(player->getMaxHP());
	string mpText = "HP: " + to_string(player->getCurrentMP()) + "/" + to_string(player->getMaxMP());
	string powerText = "공격력: " + to_string(player->getPower());
	string defenceText = "방어력: " + to_string(player->getDefence());

	cout << "===============================================================" << "\n";
	cout << nameText << " | " << jobText << " | " << levelText << "\n";
	cout << "---------------------------------------------------------------" << "\n";
	cout << hpText << " | " << mpText << " | " << powerText << " | " << defenceText << "\n";
	cout << "===============================================================" << "\n";
}

void UISystem::PrintBattleLog(Character* attacker, Character* defender, int damage)
{
	cout << "\"" << attacker->getName() << "\"이(가) \"" << defender->getName() << "\"에게 " << damage << "만큼의 데미지를 주었습니다!";
	cout << " (" << defender->getCurrentHP() << "/" << defender->getMaxHP() << ")" << "\n";
}
