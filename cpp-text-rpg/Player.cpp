#include "Players.h"

#include "SkillSystem.h"

using namespace std;

Player::Player(string name, int maxHP, int maxMP, int power, int defence, int level, int exp, int gold, EPlayerJob job)
	: Character(name, maxHP, maxMP, power, defence), level(level), exp(exp), gold(gold), job(job)
{
	SkillSystem::InitializePlayerSkills(this);
}

// 직업 전환
Player* Player::ChangeJob(Player* player, EPlayerJob newJob)
{
	player->removeBonusStat();

	Player* newPlayer;
	switch (newJob)
	{
	case EPlayerJob::None:
		newPlayer = new NoJob(player->getName(), player->getCurrentHP(), player->getCurrentMP(), player->getPower(), player->getDefence(), player->getLevel(), player->getExp(), player->getGold());
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

void Player::resetSkills()
{
	skills.clear();
}

void Player::addSkill(const Skill* skill)
{
	skills.push_back(skill);
}

const vector<const Skill*> Player::getSkills() const
{
	return skills;
}

// Getters
EPlayerJob Player::getJob() const
{
	return job;
}

int Player::getLevel() const
{
	return level;
}

int Player::getExp() const
{
	return exp;
}

int Player::getGold() const
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
