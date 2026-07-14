#include "PotionSystem.h"

#include <iostream>

string PotionSystem::formatIngredients(vector<pair<EItemID, int>> ingredients)
{
	string ingredientsStr;
	for (const auto& [itemID, count] : ingredients)
	{
		ingredientsStr += ITEM_TABLE.at(itemID)->name + " x" + to_string(count) + ", ";
	}
	ingredientsStr.erase(ingredientsStr.length() - 2);
	return ingredientsStr;
}

PotionSystem::PotionSystem()
{
	setPotionCount(EItemID::HP_POTION_20, 5);
	setPotionCount(EItemID::MP_POTION_20, 5);
}

bool PotionSystem::usePotion(Player* player, EItemID potionID)
{
	if (potionInventory[potionID] == 0)
	{
		return false;
	}

	switch (potionID)
	{
	case EItemID::HP_POTION_20:
		player->increaseMaxHP(20, true);
		break;
	case EItemID::MP_POTION_20:
		player->increaseMaxMP(20, true);
		break;
	default:
		break;
	}

	potionInventory[potionID]--;
	return true;
}

bool PotionSystem::useHPPotion(Player* player)
{
	return usePotion(player, EItemID::HP_POTION_20);
}

bool PotionSystem::useMPPotion(Player* player)
{
	return usePotion(player, EItemID::MP_POTION_20);
}

void PotionSystem::showAllRecipes()
{
	cout << "< 전체 포션 레시피 >" << "\n";
	int row = 1;
	for (auto iter = ITEM_TABLE.begin(); iter != ITEM_TABLE.end(); iter++)
	{
		const Potion* potion = static_cast<const Potion*>(iter->second);
		if (potion != nullptr)
		{
			cout << row++ << ". " << potion->name << " (" << formatIngredients(potion->ingredients) << ")" << "\n";
		}
	}
}

void PotionSystem::searchByPotionName(string target)
{
	int row = 1;
	for (auto iter = ITEM_TABLE.begin(); iter != ITEM_TABLE.end(); iter++)
	{
		const Potion* potion = static_cast<const Potion*>(iter->second);
		if (potion != nullptr)
		{
			string potionName = potion->name;
			if (potionName.find(target) != string::npos)
			{
				cout << row++ << ". " << potionName << " (" << formatIngredients(potion->ingredients) << ")" << "\n";
			}
		}
	}
}

void PotionSystem::searchByIngredient(string target)
{
	int row = 1;
	for (auto iter = ITEM_TABLE.begin(); iter != ITEM_TABLE.end(); iter++)
	{
		const Potion* potion = static_cast<const Potion*>(iter->second);
		if (potion != nullptr)
		{
			bool find = false;
			for (const auto& [itemID, count] : potion->ingredients)
			{
				if (ITEM_TABLE.at(itemID)->name.find(target) != string::npos)
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				cout << row++ << ". " << potion->name << " (" << formatIngredients(potion->ingredients) << ")" << "\n";
			}
		}
	}
}

int PotionSystem::getPotionCount(EItemID potionID)
{
	if (potionInventory.find(potionID) == potionInventory.end())
	{
		potionInventory[potionID] = 0;
	}
	return potionInventory[potionID];
}

int PotionSystem::getHPPotionCount()
{
	return getPotionCount(EItemID::HP_POTION_20);
}

int PotionSystem::getMPPotionCount()
{
	return getPotionCount(EItemID::MP_POTION_20);
}

void PotionSystem::setPotionCount(EItemID potionID, int count)
{
	potionInventory[potionID] = count;
}

void PotionSystem::setHPPotionCount(int count)
{
	setPotionCount(EItemID::HP_POTION_20, count);
}

void PotionSystem::setMPPotionCount(int count)
{
	setPotionCount(EItemID::MP_POTION_20, count);
}
