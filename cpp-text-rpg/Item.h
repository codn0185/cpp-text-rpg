#pragma once

#include <string>
#include <map>
#include <memory>

enum EItemID
{
	// 아이템 없음
	NONE,

	// 포션
	HP_POTION_20,
	MP_POTION_20,

	// 재료
	BOTTLE, // 공병 (포션 재료 및 포션 사용 시 자동 반환)
	WATER, // 물
	HEALING_HERB, // 치료 허브
	MANA_DUST, // 마나 가루

	// 기타
	SLIME_JELLY, // 슬라임 젤리
	GOBLIN_DAGGER, // 고블린 피
	BAT_FANG, // 박쥐 이빨
	ZOMBIE_LEATHER, // 좀비 가죽
	SKELETON_BONE, // 스켈레톤 뼈
	GHOST_ESSENCE, // 고스트 정수
	ORK_TENDON, // 오크 힘줄
	LIZARDMAN_SCALE, // 리자드맨 비늘
	GARGOYLE_SHARD, // 가고일 파편
	DRAGON_CORE, // 드래곤 정수
};

enum EItemType
{
	POTION, // 포션
	INGREDIENT, // 재료
	MISC, // 기타
};

struct Item
{
	EItemID itemID;
	EItemType itemType;
	std::string name;
	std::string description;

	bool isCraftable; // 제작 가능 여부
	std::map<EItemID, int> ingredients; // 제작 재료

	Item(
		EItemID itemID,
		EItemType itemType,
		std::string name,
		std::string description = "",
		bool isCraftable = false,
		std::map<EItemID, int> ingredients = {}
	);
};

extern const std::map<EItemID, std::shared_ptr<Item>> ITEM_TABLE;
