#include "InputSystem.h"

#include <iostream>

using namespace std;

bool InputSystem::InputString(string& out, string inputMessage, string errorMessage)
{
	cout << inputMessage;
	if (!getline(cin, out))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		out.clear();
		cout << errorMessage;
		return false;
	}

	return true;
}

bool InputSystem::InputInt(int& out, const int min, const int max, string inputMessage, string errorMessage)
{
	cout << inputMessage;
	if (!(cin >> out))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		out = 0;
		cout << errorMessage;
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
	int result = 0;
	while (true)
	{
		cout << inputMessage;
		if (InputInt(result, min, max))
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cout << errorMessage;
	}
	return result;
}
