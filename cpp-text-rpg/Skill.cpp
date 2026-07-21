#include "Skill.h"

#include <iostream>

using namespace std;

bool Skill::canUse(Player* player) const
{
	if (!isReady()						   // 쿨다운
		|| player->getCurrentMP() < mpCost // 마나 부족
		)
	{
		return false;
	}
	return true;
}

void Skill::use(Player* player)
{
	if (canUse(player))
	{
		player->setCurrentMP(player->getCurrentMP() - mpCost); // 마나 소모
		startCooldown(); // 쿨다운 시작
	}
}

bool Skill::isReady() const
{
	return currentCooldownTurn == 0;
}

void Skill::updateCooldownTurn()
{
	if (!isReady())
	{
		currentCooldownTurn--;
	}
}

void Skill::resetCooldown()
{
	currentCooldownTurn = 0;
}

void Skill::startCooldown()
{
	currentCooldownTurn = cooldownTurn;
}

void Skill::displayInfo() const
{
	cout
		<< "──────────────────────────────────────────" << "\n"
		<< "  📜 [" + skillName + "]" << "\n"
		<< "──────────────────────────────────────────" << "\n"
		<< "  • 마나 소모	: " << mpCost << " MP" << "\n"
		<< "  • 데미지		: " << int(damageMultiplier * 100) << "% x " << attackCount << "\n"
		<< "  • 재사용 턴	: " << cooldownTurn << "턴\n"
		<< "──────────────────────────────────────────" << "\n";
}

string Skill::getSummary() const
{
	string summary = skillName + " (마나: " + to_string(mpCost) + " | 데미지: " + to_string(int(damageMultiplier * 100)) + "% x " + to_string(attackCount) + ")";
	if (isReady())
	{
		if (cooldownTurn == 0) // 쿨다운 없는 연속 사용 가능
		{
			summary = "🟢 " + summary;
		}
		else // 쿨다운 존재
		{
			summary = "🟢 " + summary + "[0/" + to_string(cooldownTurn) + "턴]";
		}
	}
	else // 쿨다운 중
	{
		summary += "⏳ " + summary + "[대기 " + to_string(currentCooldownTurn) + "/" + to_string(cooldownTurn) + "]";
	}
	return summary;
}

string Skill::getSkillName() const
{
	return skillName;
}

float Skill::getDamageMultiplier() const
{
	return damageMultiplier;
}

int Skill::getAttackCount() const
{
	return attackCount;
}

int Skill::getMPCost() const
{
	return mpCost;
}

int Skill::getCooldownTurn() const
{
	return cooldownTurn;
}

int Skill::getCurrentCooldownTurn() const
{
	return currentCooldownTurn;
}
