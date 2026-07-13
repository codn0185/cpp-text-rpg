#pragma once

#include <string>

using namespace std;

// 플레이어 및 몬스터의 기본이 되는 추상 클래스
class Character
{
protected:
	string name;

	int maxHP;
	int currentHP;

	int maxMP;
	int currentMP;

	int power;
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
	int getMaxHP();
	int getCurrentHP();
	int getMaxMP();
	int getCurrentMP();
	int getPower();
	int getDefence();

	// Setters
	void setName(string name);
	void setMaxHP(int hp);
	void setCurrentHP(int hp);
	void setMaxMP(int mp);
	void setCurrentMP(int mp);
	void setPower(int power);
	void setDefence(int defence);

	// Utilities
	void fullHP();
	void fullMP();
	void reset();
	void increaseMaxHP(int amount, bool addToCurrrent = false);
	void increaseMaxMP(int amount, bool addToCurrrent = false);
};