#include "Character.h"

using namespace std;

Character::Character(string name, int maxHP, int maxMP, int power, int defence)
	: name(name), maxHP(maxHP), currentHP(maxHP), maxMP(maxMP), currentMP(maxMP), power(power), defence(defence)
{
}

void Character::takeDamage(int damage)
{
	currentHP = currentHP < damage ? 0 : currentHP - damage;
}

bool Character::isDead()
{
	return currentHP <= 0;
}

// Getters
string Character::getName()
{
	return name;
}

int Character::getMaxHP()
{
	return maxHP;
}

int Character::getCurrentHP()
{
	return currentHP;
}

int Character::getMaxMP()
{
	return maxMP;
}

int Character::getCurrentMP()
{
	return currentMP;
}

int Character::getPower()
{
	return power;
}

int Character::getDefence()
{
	return defence;
}

// Setters
void Character::setName(string name)
{
	this->name = name;
}

void Character::setMaxHP(int hp)
{
	this->maxHP = hp;
}

void Character::setCurrentHP(int hp)
{
	this->currentHP = hp;
}

void Character::setMaxMP(int mp)
{
	this->maxMP = mp;
}

void Character::setCurrentMP(int mp)
{
	this->currentMP = mp;
}

void Character::setPower(int power)
{
	this->power = power;
}

void Character::setDefence(int defence)
{
	this->defence = defence;
}

// Utilities
void Character::fullHP()
{
	currentHP = maxHP;
}

void Character::fullMP()
{
	currentMP = maxMP;
}

void Character::reset()
{
	fullHP();
	fullMP();
}

void Character::increaseMaxHP(int amount, bool addToCurrrent)
{
	maxHP += amount;
	if (addToCurrrent)
	{
		currentHP += amount;
	}
}

void Character::increaseMaxMP(int amount, bool addToCurrrent)
{
	maxMP += amount;
	if (addToCurrrent)
	{
		currentMP += amount;
	}
}

void Character::increaseStat(Stat stat)
{
	maxHP += stat.hp;
	maxMP += stat.mp;
	power += stat.power;
	defence += stat.defence;
}
