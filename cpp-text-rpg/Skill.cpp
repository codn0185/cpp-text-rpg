#include "Skill.h"

#include <iostream>

using namespace std;

Skill::Skill(string skillName, float damageMultiplier, int attackCount, int mpCost, int cooldownTurn)
	: skillName(skillName), damageMultiplier(damageMultiplier), attackCount(attackCount), mpCost(mpCost), cooldownTurn(cooldownTurn), currentCooldownTurn(0)
{
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

string Skill::getInfoText() const
{
	string infoText =
		"[" + skillName + "] "
		"🧪 MP: " + to_string(mpCost) + " | "
		"⚔️ DMG: " + to_string(int(damageMultiplier * 100)) + "% x " + to_string(attackCount) + "타 | "
		"⏳ CD: " + to_string(cooldownTurn) + "턴";
	return infoText;
}

string Skill::getCombatMenuText() const
{
	string combatMenuText = skillName + " (🧪 마나: " + to_string(mpCost) + " | ⚔️ 데미지: " + to_string(int(damageMultiplier * 100)) + "% x " + to_string(attackCount) + ")";
	if (isReady())
	{
		if (cooldownTurn == 0) // 쿨다운 없는 연속 사용 가능
		{
			combatMenuText = "🟢 " + combatMenuText;
		}
		else // 쿨다운 존재
		{
			combatMenuText = "🟢 " + combatMenuText + "[0/" + to_string(cooldownTurn) + "턴]";
		}
	}
	else // 쿨다운 중
	{
		combatMenuText += "⏳ " + combatMenuText + "[대기 " + to_string(currentCooldownTurn) + "/" + to_string(cooldownTurn) + "]";
	}
	return combatMenuText;
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
