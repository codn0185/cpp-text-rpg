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
	int price;

	Item(EItemType itemType, string name, int price);

	virtual bool canUse() = 0;
};

