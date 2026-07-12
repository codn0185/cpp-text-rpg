#include "CombatSystem.h"

// 최종 데미지 계산 - max(1, 공격력 - 방어력)
int CombatSystem::CalculateDamage(Character* attacker, Character* defender)
{
	int finalDamage = attacker->getPower() - defender->getDefence();
	if (finalDamage <= 0) finalDamage = 1;
	return finalDamage;
}

// 데미지 적용
void CombatSystem::ProcessDamage(Character* attacker, Character* defender)
{
	int finalDamage = CalculateDamage(attacker, defender);
	defender->takeDamage(finalDamage);
}
