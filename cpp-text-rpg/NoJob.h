#pragma once

#include "Player.h"

class NoJob : public Player
{
	void showAttackMessage() const override;
};

