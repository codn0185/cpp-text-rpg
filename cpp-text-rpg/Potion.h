#pragma once

#include "Item.h"
#include "Ingredient.h"

#include <vector>
#include <map>

// 포션 ID
enum class EPotionID
{
	HP_POTION_20,
	MP_POTION_20,
};

// 포션 타입
enum class EPotionType
{
	HP_POTION,
	MP_POTION,
};


// 포션 구조체
struct Potion : public Item
{
	EPotionID potionID;
	EPotionType potionType;
	int amount;
	vector<pair<EIngredientID, int>> ingredients;

	Potion(EPotionID potionID, EPotionType potionType, string name, string description = "", int price = 0, int amount = 0, vector<pair<EIngredientID, int>> ingredients = {});

	bool canUse() override;
};

// 포션 테이블
extern const map<EPotionID, Potion> POTION_TABLE;
