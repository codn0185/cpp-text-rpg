#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence) : job(EPlayerJob::None), level(0)
{
	setName(name);
	setHP(hp);
	setMP(mp);
	setPower(power);
	setDefence(defence);
}

// Getters
EPlayerJob Player::getJob()
{
	return job;
}

int Player::getLevel()
{
	return level;
}

// Setters
void Player::setJob(EPlayerJob job)
{
	this->job = job;
}

void Player::setLevel(int level)
{
	this->level = level;
}
