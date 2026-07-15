#include "PotionSystem.h"

#include <iostream>

using namespace std;

string PotionSystem::FormatIngredients(vector<pair<EItemID, int>> ingredients)
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
		if (player->getCurrentHP() < player->getMaxHP()) // HP 포션 사용 성공
		{
			player->setCurrentHP(min(player->getCurrentHP() + 20, player->getMaxHP()));
			inventory->removeItem(EItemID::HP_POTION_20);
			std::cout << "* HP가 20 회복했습니다. (남은 HP 포션: " << inventory->getItemCount(EItemID::HP_POTION_20) << "개)" << "\n";
			return true;
		}
		std::cout << "HP가 가득 차서 사용할 수 없습니다." << "\n"; // HP 포션 사용 실패
		break;
	case EItemID::MP_POTION_20:
		if (player->getCurrentMP() < player->getMaxMP()) // MP 포션 사용 성공
		{
			player->setCurrentMP(min(player->getCurrentMP() + 20, player->getMaxMP()));
			inventory->removeItem(EItemID::MP_POTION_20);
			std::cout << "* MP가 20 회복했습니다. (남은 MP 포션: " << inventory->getItemCount(EItemID::MP_POTION_20) << "개)" << "\n";
			return true;
		}
		std::cout << "MP가 가득 차서 사용할 수 없습니다." << "\n"; // MP 포션 사용 실패
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
		const Potion* potion = static_cast<const Potion*>(item.get());
		if (potion != nullptr)
		{
			cout << row++ << ". " << potion->name << " (" << FormatIngredients(potion->ingredients) << ")" << "\n";
		}
	}
}

void PotionSystem::SearchByPotionName(string target)
{
	int row = 1;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		const Potion* potion = static_cast<const Potion*>(item.get());
		if (potion != nullptr)
		{
			string potionName = potion->name;
			if (potionName.find(target) != string::npos)
			{
				cout << row++ << ". " << potionName << " (" << FormatIngredients(potion->ingredients) << ")" << "\n";
			}
		}
	}
}

void PotionSystem::SearchByIngredient(string target)
{
	int row = 1;
	for (const auto& [itemID, item] : ITEM_TABLE)
	{
		const Potion* potion = static_cast<const Potion*>(item.get());
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
				cout << row++ << ". " << potion->name << " (" << FormatIngredients(potion->ingredients) << ")" << "\n";
			}
		}
	}
}
