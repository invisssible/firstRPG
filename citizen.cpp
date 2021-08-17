#include <iostream>
#include "citizen.h"

Citizen::Citizen(std::string Name, double health, double damage, int defence, int accuracy) : Character{ Name, health, damage, defence, accuracy } {}


void Citizen::attack(Itroops& character)
{
	if (!calculateAccuracy()) {
		std::cout << Name << " - mised\n";
		return;
	}
	character.takeDamage(damage);
}

void Citizen::takeDamage(int _damage)
{
	_damage -= defence;
	if (_damage <= 0) {
		return;
	}
	health -= _damage;
	if (health <= 0) {
		isAlive = false;
	}
}

std::string Citizen::getName() {
	return Name;
}
double Citizen::getHealth() {
	return health;
}
double Citizen::getDamage() {
	return damage;
}
int Citizen::getDefence() {
	return defence;
}
bool Citizen::getisAlive() {
	return isAlive;
}