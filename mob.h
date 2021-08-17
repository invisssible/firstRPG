#pragma once
#include<iostream>
#include <string>
#include <vector>

#include "Imob.h"
#include "citizen.h"


class Mob : public Imob {
protected:
	std::vector<Citizen> People;
	std::string Name;

	void generateCrew(size_t x);
public:
	Mob();
	Mob(std::string Name, size_t number );
	void attack(Itroops& character) override;
	void takeDamage(int damage) override;
	std::string getName() override { return Name; };
	double getHealth() override { return 0; };
	double getDamage() override { return 0; };
	int getDefence() override { return 0; };
	bool getisAlive() override;
};

