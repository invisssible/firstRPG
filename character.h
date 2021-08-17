#pragma once
#include <string>
#include "Imob.h"

class Character{
protected:
	std::string Name{};
	double health{};
	double damage{};
	int defence{};
	int accuracy{};
	bool isAlive{ true };
public:
	Character();
	Character(std::string Name, double health, double damage, int defence, int accuracy);

	std::string getName();
	double getHealth();
	double getDamage();
	int getDefence();
	bool getisAlive();
	bool calculateAccuracy();
};


