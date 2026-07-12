#pragma once

#include <string>

using namespace std;

// 플레이어 및 몬스터의 기본이 되는 추상 클래스
class Character
{
protected:
	string name;

	// 	int defaultHP;
	// 	int maxHP;
	// 	int currentHP;
	int hp;

	// 	int defalutMP;
	// 	int maxMP;
	// 	int currentMP;
	int mp;

	// 	int defaultPower;
	// 	int currentPower;
	int power;

	// 	int defaultDefence;
	// 	int currentDefence;
	int defence;

public:
	virtual ~Character() = default;

	void takeDamage(int damage) = 0;
	bool isDead() = 0;

	// Life Cycles
	//  virtual void onEnable() = 0;
	//  virtual void onDisable() = 0;

	// Getters
	string getName() = 0;
	int getHP() = 0;
	int getMP() = 0;
	int getPower() = 0;
	int getDefence() = 0;

	// Setters
	void setName(string name) = 0;
	void setHP(int hp) = 0;
	void setMP(int mp) = 0;
	void setPower(int power) = 0;
	void setDefence(int defence) = 0;
};