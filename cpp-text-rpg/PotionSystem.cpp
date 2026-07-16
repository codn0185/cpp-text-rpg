#include "PotionSystem.h"

#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string PotionSystem::GetLowerString(string str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return tolower(c); });
	return str;
}

string PotionSystem::FormatIngredients(map<EItemID, int> ingredients)
{
	string ingredientsStr;
	for (const auto& [itemID, count] : ingredients)
	{
		ingredientsStr += ITEM_TABLE.at(itemID)->name + " x" + to_string(count) + ", ";
	}
	ingredientsStr.erase(ingredientsStr.length() - 2);
	return ingredientsStr;
}

bool PotionSystem::UsePotion(Player* player, Inventory* inventory, EItemID potionID)
{
	// 포션 없음
	if (inventory->getItemCount(potionID) == 0)
	{
		cout << ITEM_TABLE.at(potionID)->name << "이(가) 없습니다." << "\n";
		return false;
	}

	// 포션 사용
	switch (potionID)
	{
	case EItemID::HP_POTION_20:
		if (player->getCurrentHP() < player->getMaxHP()) // HP 포션 사용 가능
		{
			int prevHP = player->getCurrentHP();
			player->setCurrentHP(min(prevHP + 20, player->getMaxHP()));
			inventory->removeItem(EItemID::HP_POTION_20);
			std::cout << "* HP를 20 회복했습니다. (" << prevHP << "/" << player->getMaxHP() << " -> " << player->getCurrentHP() << "/" << player->getMaxHP() << ") ── [남은 HP 포션: " << inventory->getItemCount(EItemID::HP_POTION_20) << "개]" << "\n";
			inventory->addItem(EItemID::BOTTLE); // 공병 반환
			return true;
		}
		std::cout << "HP가 가득 차서 사용할 수 없습니다." << "\n"; // HP 포션 사용 불가능
		break;
	case EItemID::MP_POTION_20:
		if (player->getCurrentMP() < player->getMaxMP()) // MP 포션 사용 가능
		{
			int prevMP = player->getCurrentMP();
			player->setCurrentMP(min(prevMP + 20, player->getMaxMP()));
			inventory->removeItem(EItemID::MP_POTION_20);
			std::cout << "* MP를 20 회복했습니다. (" << prevMP << "/" << player->getMaxMP() << " -> " << player->getCurrentMP() << "/" << player->getMaxMP() << ") ── [남은 MP 포션: " << inventory->getItemCount(EItemID::MP_POTION_20) << "개]" << "\n";
			inventory->addItem(EItemID::BOTTLE); // 공병 반환
			return true;
		}
		std::cout << "MP가 가득 차서 사용할 수 없습니다." << "\n"; // MP 포션 사용 불가능
		break;
	default:
		break;
	}
	return false;
}

void PotionSystem::ShowAllRecipes()
{
	cout << "< 전체 포션 레시피 >" << "\n";
	int row = 1;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		const auto& potion = item.get();
		if (item->isCraftable)
		{
			cout << row++ << ". " << potion->name << " —— [" << FormatIngredients(potion->ingredients) << "]" << "\n";
		}
	}
}

void PotionSystem::SearchByPotionName(string target)
{
	target = GetLowerString(target);
	int row = 1;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		const auto& potion = item.get();
		if (item->isCraftable)
		{
			string potionName = potion->name;
			if (GetLowerString(potionName).find(target) != string::npos)
			{
				cout << row++ << ". " << potionName << " —— [" << FormatIngredients(potion->ingredients) << "]" << "\n";
			}
		}
	}
}

void PotionSystem::SearchByIngredient(string target)
{
	target = GetLowerString(target);
	int row = 1;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		const auto& potion = item.get();
		if (item->isCraftable)
		{
			bool find = false;
			for (const auto& [itemID, count] : potion->ingredients)
			{
				string ingredientnName = ITEM_TABLE.at(itemID)->name;
				if (GetLowerString(ingredientnName).find(target) != string::npos)
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				cout << row++ << ". " << potion->name << " —— [" << FormatIngredients(potion->ingredients) << "]" << "\n";
			}
		}
	}
}

vector<EItemID> PotionSystem::GetPotionIDs()
{
	vector<EItemID> potions;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		if (item->itemType == EItemType::POTION)
		{
			potions.push_back(item->itemID);
		}
	}
	return potions;
}
