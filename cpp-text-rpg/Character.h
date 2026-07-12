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

	virtual void takeDamage(int damage) = 0;
	virtual bool isDead() = 0;

	// Life Cycles
	//  virtual void onEnable() = 0;
	//  virtual void onDisable() = 0;

	// Getters
	virtual string getName() = 0;
	virtual int getHP() = 0;
	virtual int getMP() = 0;
	virtual int getPower() = 0;
	virtual int getDefence() = 0;

	// Setters
	virtual void setName(string name) = 0;
	virtual void setHP(int hp) = 0;
	virtual void setMP(int mp) = 0;
	virtual void setPower(int power) = 0;
	virtual void setDefence(int defence) = 0;
};