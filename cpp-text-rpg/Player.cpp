#include "Players.h"

Player::Player(string name, int hp, int mp, int power, int defence) : job(EPlayerJob::None), level(0)
{
	setName(name);
	setMaxHP(hp);
	setMaxMP(mp);
	setPower(power);
	setDefence(defence);

	reset();
}

// 직업 전환
Player* Player::ChangeJob(Player* player, EPlayerJob newJob)
{
	player->removeBonusStat();

	Player* newPlayer;
	switch (newJob)
	{
	case EPlayerJob::None:
		newPlayer = new NoJob(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Warrior:
		newPlayer = new Warrior(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Mage:
		newPlayer = new Mage(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Rogue:
		newPlayer = new Rogue(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Archer:
		newPlayer = new Archer(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence());
		break;
	default:
		newPlayer = nullptr;
		break;
	}
	delete player;
	if (newPlayer != nullptr)
	{
		newPlayer->applyBonusStat();
	}
	return newPlayer;
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
