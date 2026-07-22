#pragma once

#include "Character.h"

#include <string>

struct SkillData
{
	const std::string skillName; // 스킬 이름
	const float damageMultiplier; // 공격력 배율 
	const int attackCount; // 공격 홋수 (최소 1)
	const int mpCost; // 마나 소모량 (최소 0)
	const int cooldownTurn; // 대기 턴 수 (0: 매 턴 사용 가능)

	SkillData(std::string skillName, float damageMultiplier = 1, int attackCount = 1, int mpCost = 0, int cooldownTurn = 0);

	std::string getInfoText() const; // 스킬 설명 텍스트 반환
};

class Skill
{
protected:
	const SkillData* skillData; // 스킬 데이터
	int currentCooldownTurn; // 남은 대기 턴 수 (0일 때 사용 가능)

public:
	Skill(const SkillData* skillData);
	~Skill() = default;

	bool isReady() const; // 스킬 사용 준비 여부 반혼 (현재 대기 턴 확인)
	void updateCooldownTurn(); // 쿨다운 턴 감소
	void resetCooldown(); // 쿨다운 초기화 (0 설정)
	void startCooldown(); // 쿨다운 시작

	std::string getInfoText() const; // 스킬 설명 텍스트 반환
	std::string getCombatMenuText() const; // 전투 메뉴(쿨다운 및 준비 여부 포함) 텍스트 반환

	// Getters
	std::string getSkillName() const;
	float getDamageMultiplier() const;
	int getAttackCount() const;
	int getMPCost() const;
	int getCooldownTurn() const;
	int getCurrentCooldownTurn() const;
};

