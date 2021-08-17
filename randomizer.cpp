#include "randomizer.h"
#include <random>
#include <chrono>

Random::Random(int _max, int _min) :max{ _max }, min{ _min } {}

int Random::getRandomNumber() {
	std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<>distribution{min, max};
	return distribution(generator);
}