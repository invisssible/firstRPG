#pragma once
#include "character.h"
#include "Imob.h"

class Marine :public Character,public Itroops {
	int vodka{};
	double halfHealth{};
	bool isDrunk{};
	int drunkTime{};

	bool becomeSober();
public:
	Marine(std::string Name, double health, double damage, int defence, int accuracy, int _vodka);
	void attack(Imob& character) override;
	void takeDamage(int damage) override;

	std::string getName() override;
	double getHealth() override;
	double getDamage() override;
	int getDefence() override;
	bool getisAlive() override;
};