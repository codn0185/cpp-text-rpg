#include "GameStartState.h"

#include <iostream>

using namespace std;

bool GameStartState::needInput()
{
	return false;
}

void GameStartState::handleInput(std::istream& in)
{
}

void GameStartState::onEnter()
{
	std::cout << "===========================================" << "\n";
	std::cout << "          [ 던전 탈출 텍스트 RPG ]          " << "\n";
	std::cout << "===========================================" << "\n";
}

void GameStartState::onExit()
{
}
