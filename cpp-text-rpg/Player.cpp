#include "Players.h"

using namespace std;

Player::Player(string name, int maxHP, int maxMP, int power, int defence)
	: Character(name, maxHP, maxMP, power, defence), job(EPlayerJob::None), level(0), exp(0), gold(0)
{
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

int Player::getExp()
{
	return exp;
}

int Player::getGold()
{
	return gold;
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

void Player::setExp(int exp)
{
	this->exp = exp;
}

void Player::setGold(int gold)
{
	this->gold = gold;
}
