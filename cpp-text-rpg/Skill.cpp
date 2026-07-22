#include "Skill.h"

#include <iostream>

using namespace std;

SkillData::SkillData(string skillName, float damageMultiplier, int attackCount, int mpCost, int cooldownTurn)
	: skillName(skillName), damageMultiplier(damageMultiplier), attackCount(attackCount), mpCost(mpCost), cooldownTurn(cooldownTurn)
{
}

Skill::Skill(const SkillData* skillData)
	: skillData(skillData), currentCooldownTurn(0)
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
	currentCooldownTurn = skillData->cooldownTurn;
}

string Skill::getInfoText() const
{
	string infoText =
		"[" + skillData->skillName + "] "
		"🧪 MP: " + to_string(skillData->mpCost) + " | "
		"⚔️ DMG: " + to_string(int(skillData->damageMultiplier * 100)) + "% x " + to_string(skillData->attackCount) + "타 | "
		"⏳ CD: " + to_string(skillData->cooldownTurn) + "턴";
	return infoText;
}

string Skill::getCombatMenuText() const
{
	string combatMenuText = skillData->skillName + " (🧪 마나: " + to_string(skillData->mpCost) + " | ⚔️ 데미지: " + to_string(int(skillData->damageMultiplier * 100)) + "% x " + to_string(skillData->attackCount) + ")";
	if (isReady())
	{
		if (skillData->cooldownTurn == 0) // 쿨다운 없는 연속 사용 가능
		{
			combatMenuText = "🟢 " + combatMenuText;
		}
		else // 쿨다운 존재
		{
			combatMenuText = "🟢 " + combatMenuText + "[0/" + to_string(skillData->cooldownTurn) + "턴]";
		}
	}
	else // 쿨다운 중
	{
		combatMenuText += "⏳ " + combatMenuText + "[대기 " + to_string(currentCooldownTurn) + "/" + to_string(skillData->cooldownTurn) + "]";
	}
	return combatMenuText;
}

string Skill::getSkillName() const
{
	return skillData->skillName;
}

float Skill::getDamageMultiplier() const
{
	return skillData->damageMultiplier;
}

int Skill::getAttackCount() const
{
	return skillData->attackCount;
}

int Skill::getMPCost() const
{
	return skillData->mpCost;
}

int Skill::getCooldownTurn() const
{
	return skillData->cooldownTurn;
}

int Skill::getCurrentCooldownTurn() const
{
	return currentCooldownTurn;
}
