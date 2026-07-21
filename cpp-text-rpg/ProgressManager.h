#pragma once

#include <string>
#include <map>

enum class EDungeonProgress
{
	None,   // 던전 밖
	Floor1, // 1층
	Floor2, // 2층
	Floor3, // 3층
	Boss,   // 보스
};

extern std::map<EDungeonProgress, std::string> DUNGEON_PROGRESS_DISPLAY_NAME;

class ProgressManager
{
private:

	EDungeonProgress currentDungeonProgress;
	std::map<EDungeonProgress, bool> unlockedDungeonProgresses;

public:
	ProgressManager();
	~ProgressManager() = default;

	EDungeonProgress getCurrentDungeonProgress();
	void setCurrentDungeonProgress(EDungeonProgress dungeonProgress);

	void unlockDungeonProgress(EDungeonProgress dungeonProgress);
	bool tryUnlockDungeonProgress(EDungeonProgress dungeonProgress);

	void displayDungeonSelection();
	void displayDungeonEnterMessage(EDungeonProgress dungeonProgress);
	void displayAccessDeniedMessage(EDungeonProgress dungeonProgress);

	bool tryEnterDungeonProgress(EDungeonProgress dungeonProgress);
};

