#pragma once

#include <string>

class InputSystem
{
public:
	static bool InputString(std::string& out, std::string inputMessage = "", std::string errorMessage = "");
	static bool InputInt(int& out, const int min = INT_MIN, const int max = INT_MAX, std::string inputMessage = "", std::string errorMessage = "");

	static int InputIntUnitlValid(const int min = INT_MIN, const int max = INT_MAX, std::string inputMessage = "", std::string errorMessage = "");
};

