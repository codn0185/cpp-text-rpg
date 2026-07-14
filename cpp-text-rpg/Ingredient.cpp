#include "Ingredient.h"

Ingredient::Ingredient(EIngredientID ingredientID, string name, int price) : Item(EItemType::INGREDIENT, name, price), ingredientID(ingredientID)
{
}

bool Ingredient::canUse()
{
	return false;
}

// 재료 테이블
map<EIngredientID, Ingredient*> INGREDIENT_TABLE = {
	{EIngredientID::SLIME_JELLY, new Ingredient(EIngredientID::SLIME_JELLY, "슬라임의 끈적한 젤리", 15)},
	{EIngredientID::GOBLIN_BLOOD, new Ingredient(EIngredientID::GOBLIN_BLOOD, "고블린의 오염된 피", 15)},
	{EIngredientID::SKELETON_BONE, new Ingredient(EIngredientID::SKELETON_BONE, "스켈레톤의 부서진 뼈", 15)},
	{EIngredientID::WATER, new Ingredient(EIngredientID::WATER, "물", 5)},
	{EIngredientID::HEALING_HERB, new Ingredient(EIngredientID::HEALING_HERB, "치료 허브", 25)},
	{EIngredientID::MANA_DUST, new Ingredient(EIngredientID::MANA_DUST, "마나 가루", 20)},
};