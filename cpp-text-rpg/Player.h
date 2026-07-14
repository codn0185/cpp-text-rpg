#pragma once

#include "Character.h"

using namespace std;

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

public:
	Player(string name, int hp, int mp, int power, int defence);

	static Player* ChangeJob(Player* player, EPlayerJob newJob); // 직업 전환
	virtual void applyBonusStat() = 0; // 보너스 스탯 적용
	virtual void removeBonusStat() = 0; // 보너스 스탯 제거

	virtual void showAttackMessage() const = 0; // 공격 메시지

	// Getters
	EPlayerJob getJob();
	int getLevel();
	int getExp();

	// Setters
	void setJob(EPlayerJob job);
	void setLevel(int level);
	void setExp(int exp);
};
