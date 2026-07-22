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

void UISystem::PrintPlayerStat(const Player* player)
{
	string nameText = "닉네임: " + player->getName();
	string jobText = "직업: " + jobNames.at(player->getJob());
	string levelText = "레벨: " + to_string(player->getLevel()) + " (" + to_string(player->getExp()) + "/" + to_string(LevelSystem::GetRequiredExp(player)) + ")";
	string goldText = "골드: " + to_string(player->getGold()) + "G";

	string hpText = "HP: " + to_string(player->getCurrentHP()) + "/" + to_string(player->getMaxHP());
	string mpText = "HP: " + to_string(player->getCurrentMP()) + "/" + to_string(player->getMaxMP());
	string powerText = "공격력: " + to_string(player->getPower());
	string defenceText = "방어력: " + to_string(player->getDefence());

	cout << "============================================================" << "\n";
	cout << " " << nameText << " | " << jobText << " | " << levelText << " | " << goldText << "\n";
	cout << "────────────────────────────────────────────────────────────" << "\n";
	cout << " " << hpText << " | " << mpText << " | " << powerText << " | " << defenceText << "\n";
	cout << "────────────────────────────────────────────────────────────" << "\n";
	cout << " 스킬 리스트" << "\n";
	for (const Skill* skill : player->getSkills())
	{
		cout << "   - " << skill->getInfoText() << "\n";
	}
	cout << "============================================================" << "\n";
}

void UISystem::PrintBattleLog(const Character* attacker, const Character* defender, const int damage)
{
	cout << "\"" << attacker->getName() << "\"이(가) \"" << defender->getName() << "\"에게 " << damage << "만큼의 데미지를 주었습니다!";
	cout << " (" << defender->getCurrentHP() << "/" << defender->getMaxHP() << ")" << "\n";
}
