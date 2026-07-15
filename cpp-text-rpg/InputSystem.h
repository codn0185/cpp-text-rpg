#pragma once

#include <string>

class InputSystem
{
public:
	static bool InputString(std::string& out);
	static bool InputInt(int& out);
	static bool InputInt(int& out, const int min, const int max);
};

