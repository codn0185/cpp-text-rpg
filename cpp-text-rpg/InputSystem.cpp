#include "InputSystem.h"

#include <iostream>

using namespace std;

bool InputSystem::InputString(string& out)
{
	if (!getline(cin, out))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		out.clear();
		return false;
	}

	return true;
}

bool InputSystem::InputInt(int& out, const int min, const int max)
{
	if (!(cin >> out))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		out = 0;
		return false;
	}

	if (out < min || out > max)
	{
		return false;
	}

	return true;
}

int InputSystem::InputIntUnitlValid(const int min, const int max, string inputMessage, string errorMessage)
{
	int result;
	while (true)
	{
		cout << inputMessage;
		if (InputInt(result, min, max))
		{
			break;
		}
		cout << errorMessage;
	}
	return result;
}
