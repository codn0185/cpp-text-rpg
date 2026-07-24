#include "RandomSystem.h"

using namespace std;

int RandomSystem::GetRandomInt(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distrib(min, max);
	return distrib(gen);
}
