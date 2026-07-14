#include "PotionSystem.h"

map<EPotionID, PotionDataRow> POTION_TABLE = {
	{EPotionID::HP_POTION_20, PotionDataRow(EPotionID::HP_POTION_20, EPotionType::HP_POTION, "HP 포션 (소형)", "HP를 20만큼 회복한다.", {{EIngredientID::WATER, 1}, {EIngredientID::HEALING_HERB, 2}})},
	{EPotionID::MP_POTION_20, PotionDataRow(EPotionID::MP_POTION_20, EPotionType::MP_POTION, "MP 포션 (소형)", "MP를 20만큼 회복한다.", {{EIngredientID::WATER, 1}, {EIngredientID::MANA_DUST, 2}})},
};

string PotionSystem::formatIngredients(vector<pair<EIngredientID, int>> ingredients)
{
	string ingredientsStr;
	for (const auto& [itemID, count] : ingredients)
	{
		ingredientsStr += INGREDIENT_TABLE[itemID]->name + " x" + to_string(count) + ", ";
	}
	ingredientsStr.erase(ingredientsStr.length() - 2);
	return ingredientsStr;
}

PotionSystem::PotionSystem()
{
	setPotionCount(EPotionID::HP_POTION_20, 5);
	setPotionCount(EPotionID::MP_POTION_20, 5);
}

bool PotionSystem::usePotion(Player* player, EPotionID potionID)
{
	if (potionInventory[potionID] == 0)
	{
		return false;
	}

	switch (potionID)
	{
	case EPotionID::HP_POTION_20:
		player->increaseMaxHP(20, true);
		break;
	case EPotionID::MP_POTION_20:
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
	return usePotion(player, EPotionID::HP_POTION_20);
}

bool PotionSystem::useMPPotion(Player* player)
{
	return usePotion(player, EPotionID::MP_POTION_20);
}

void PotionSystem::showAllRecipes()
{
	cout << "< 전체 포션 레시피 >" << "\n";
	int row = 1;
	for (auto iter = POTION_TABLE.begin(); iter != POTION_TABLE.end(); iter++)
	{
		cout << row++ << ". " << iter->second.name << " (" << formatIngredients(iter->second.ingredients) << ")" << "\n";
	}
}

void PotionSystem::searchByPotionName(string target)
{
	int row = 1;
	for (auto iter = POTION_TABLE.begin(); iter != POTION_TABLE.end(); iter++)
	{
		string potionName = iter->second.name;
		if (potionName.find(target) != string::npos)
		{
			cout << row++ << ". " << potionName << " (" << formatIngredients(iter->second.ingredients) << ")" << "\n";
		}
	}
}

void PotionSystem::searchByIngredient(string target)
{
	int row = 1;
	for (auto iter = POTION_TABLE.begin(); iter != POTION_TABLE.end(); iter++)
	{
		bool find = false;
		for (const auto& [itemID, count] : iter->second.ingredients)
		{
			if (INGREDIENT_TABLE[itemID]->name.find(target) != string::npos)
			{
				find = true;
				break;
			}
		}
		if (find)
		{
			cout << row++ << ". " << iter->second.name << " (" << formatIngredients(iter->second.ingredients) << ")" << "\n";
		}
	}
}

int PotionSystem::getPotionCount(EPotionID potionID)
{
	if (potionInventory.find(potionID) == potionInventory.end())
	{
		potionInventory[potionID] = 0;
	}
	return potionInventory[potionID];
}

int PotionSystem::getHPPotionCount()
{
	return getPotionCount(EPotionID::HP_POTION_20);
}

int PotionSystem::getMPPotionCount()
{
	return getPotionCount(EPotionID::MP_POTION_20);
}

void PotionSystem::setPotionCount(EPotionID potionID, int count)
{
	potionInventory[potionID] = count;
}

void PotionSystem::setHPPotionCount(int count)
{
	setPotionCount(EPotionID::HP_POTION_20, count);
}

void PotionSystem::setMPPotionCount(int count)
{
	setPotionCount(EPotionID::MP_POTION_20, count);
}
