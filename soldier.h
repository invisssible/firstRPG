#pragma once
#include "character.h"
#include "Imob.h"
class Soldier :public Character, public Itroops {
public:
	Soldier(std::string Name, double health, double damage, int defence, int accuracy);
	void attack(Imob& character) override;
	void takeDamage(int damage) override;

	std::string getName() override;
	double getHealth() override;
	double getDamage() override;
	int getDefence() override;
	bool getisAlive() override;
};