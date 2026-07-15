#pragma once

#include <string>

using namespace std;

class InputSystem
{
public:
	static bool InputString(string& out);
	static bool InputInt(int& out);
	static bool InputInt(int& out, const int min, const int max);
};

