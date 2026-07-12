#pragma once

#include "Character.h"

using namespace std;

// 플레이어 직업 enum
enum class EPlayerJob
{
	None,		// 무직
	Warrior,	// 전사
	Magician,	// 마법사
	Thief,		// 도적
	Archer,		// 궁수
};

// 플레이어 클래스
class Player : public Character
{
protected:
	EPlayerJob job;
	int level;

public:
	Player(string name, int hp, int mp, int power, int defence);

	// 공격 메시지
	virtual void showAttackMessage() const = 0;

	// Getters
	virtual EPlayerJob getJob() = 0;
	virtual int getLevel() = 0;

	// Setters
	virtual void setJob(EPlayerJob job) = 0;
	virtual void setLevel(int level) = 0;
};
