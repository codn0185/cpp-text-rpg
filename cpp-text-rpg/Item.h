#pragma once

#include <string>

using namespace std;

enum EItemType
{
	INGREDIENT,
	POTION,
};

struct Item
{
	EItemType itemType;
	string name;
	string description;
	int price;

	Item(EItemType itemType, string name, string description = "", int price = 0);

	virtual bool canUse() = 0;
};

