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

	void takeDamage(int damage);
	bool isDead();

	// Life Cycles
	//  virtual void onEnable() = 0;
	//  virtual void onDisable() = 0;

	// Getters
	string getName();
	int getHP();
	int getMP();
	int getPower();
	int getDefence();

	// Setters
	void setName(string name);
	void setHP(int hp);
	void setMP(int mp);
	void setPower(int power);
	void setDefence(int defence);
};