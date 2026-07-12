#pragma once

#include "Character.h"

class CombatSystem
{
public:
	// 데미지 계산
	static int CalculateDamage(Character* attacker, Character* defender);
	// 데미지 적용
	static void ProcessDamage(Character* attacker, Character* defender);
};
