#pragma once

#include "Character.h"

#include "Skill.h"

#include <vector>
#include <memory>

class Skill;

// 플레이어 직업 enum
enum class EPlayerJob
{
	None,		// 무직
	Warrior,	// 전사
	Mage,	    // 마법사
	Rogue,		// 도적
	Archer,		// 궁수
};

// 플레이어 클래스
class Player : public Character
{
protected:
	EPlayerJob job;

	int level;
	int exp;
	int gold;

	std::vector<std::shared_ptr<Skill>> skills;

public:
	Player(std::string name, int maxHP, int maxMP, int power, int defence, int level = 0, int exp = 0, int gold = 0, EPlayerJob job = EPlayerJob::None);

	static Player* ChangeJob(Player* player, EPlayerJob newJob); // 직업 전환
	virtual void applyBonusStat() = 0; // 보너스 스탯 적용
	virtual void removeBonusStat() = 0; // 보너스 스탯 제거

	virtual void showAttackMessage() const = 0; // 공격 메시지

	// 스킬 메서드
	void resetSkills(); // 스킬 초기화
	void addSkill(const SkillData* skillData); // 스킬 추가
	std::vector<std::shared_ptr<Skill>> getSkills() const; // 스킬 반환
	void updateSkillsCooldown(); // 스킬들 쿨다운 감소

	// Getters
	EPlayerJob getJob() const;
	int getLevel() const;
	int getExp() const;
	int getGold() const;

	// Setters
	void setJob(EPlayerJob job);
	void setLevel(int level);
	void setExp(int exp);
	void setGold(int gold);
};
