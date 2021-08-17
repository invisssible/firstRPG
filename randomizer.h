#pragma once
class Random {
	int max{};
	int min{};
public:
	Random(int _max, int _min);
	int getRandomNumber();
};