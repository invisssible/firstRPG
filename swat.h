#pragma once
#include "character.h"
#include "Imob.h"
class SWAT:public Character, public Itroops {
	int granade{};
public:
	SWAT(std::string Name, double health, double damage, int defence, int accuracy, int _granade);
	void attack(Imob& character) override;
	void takeDamage(int damage) override;

	std::string getName() override;
	double getHealth() override;
	double getDamage() override;
	int getDefence() override;
	bool getisAlive() override;
};