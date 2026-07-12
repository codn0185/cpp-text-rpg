#include "Character.h"

void Character::takeDamage(int damage)
{
	hp = hp < damage ? 0 : hp - damage;
}

bool Character::isDead()
{
	return hp <= 0;
}

// Getters
string Character::getName()
{
	return name;
}

int Character::getHP()
{
	return hp;
}

int Character::getMP()
{
	return mp;
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

void Character::setHP(int hp)
{
	this->hp = hp;
}

void Character::setMP(int mp)
{
	this->mp = mp;
}

void Character::setPower(int power)
{
	this->power = power;
}

void Character::setDefence(int defence)
{
	this->defence = defence;
}
