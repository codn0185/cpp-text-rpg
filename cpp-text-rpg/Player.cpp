#include "Players.h"

Player::Player(string name, int hp, int mp, int power, int defence) : job(EPlayerJob::None), level(0)
{
	setName(name);
	setHP(hp);
	setMP(mp);
	setPower(power);
	setDefence(defence);
}

// 직업 전환
Player* Player::ChangeJob(Player* player, EPlayerJob newJob)
{
	player->removeBonusStat();

	Player* newPlayer;
	switch (newJob)
	{
	case EPlayerJob::None:
		newPlayer = new NoJob(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Warrior:
		newPlayer = new Warrior(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Mage:
		newPlayer = new Mage(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Rogue:
		newPlayer = new Rogue(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		break;
	case EPlayerJob::Archer:
		newPlayer = new Archer(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
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
