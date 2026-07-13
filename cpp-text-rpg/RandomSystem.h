#pragma once

#include <vector>
#include <random>

using namespace std;

class RandomSystem
{
public:
	template <typename T>
	static T getRandom(vector<T> array, vector<float> weights);
};

template<typename T>
inline T RandomSystem::getRandom(vector<T> array, vector<float> weights)
{
	random_device rd;
	mt19937 gen(rd());

	std::discrete_distribution<int> Distribution(weights.begin(), weights.end());
	return array[Distribution(gen)];
}
