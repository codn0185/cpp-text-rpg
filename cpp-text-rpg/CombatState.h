#pragma once

#include "CombatManager.h"

class CombatState
{
public:
	CombatState();
	~CombatState();

	virtual void enter(CombatManager* manager) = 0;
	virtual void update(CombatManager* manager) = 0;
	virtual void exit(CombatManager* manager) = 0;
};

