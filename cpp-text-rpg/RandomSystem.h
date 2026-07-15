#pragma once

#include <vector>
#include <random>

class RandomSystem
{
public:
	static int GetRandomInt(int min, int max);

	template <typename T>
	static T GetRandomByWeight(std::vector<T> array, std::vector<float> weights);
};

template<typename T>
inline T RandomSystem::GetRandomByWeight(std::vector<T> array, std::vector<float> weights)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::discrete_distribution<int> Distribution(weights.begin(), weights.end());
	return array[Distribution(gen)];
}
