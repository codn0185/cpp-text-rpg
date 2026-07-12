#pragma once

#include "Character.h"

#include "Item.h"

class Monster : public Character
{
protected:
	Item dropItem;

public:
	// Getters
	virtual Item getDropItem() = 0;

	// Setters
	virtual void setDropItem(Item dropItem) = 0;
};
