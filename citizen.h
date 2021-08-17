#pragma once
#include "character.h"
#include "Imob.h"
class Citizen :public Character, public Imob {
public:
	Citizen(std::string Name, double health, double damage, int defence, int accuracy);
	void attack(Itroops& character) override;
	void takeDamage(int damage) override;

	std::string getName() override;
	double getHealth() override;
	double getDamage() override;
	int getDefence() override;
	bool getisAlive() override;
};