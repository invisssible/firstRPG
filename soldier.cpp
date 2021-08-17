#include <iostream>

#include "soldier.h"

Soldier::Soldier(std::string Name, double health, double damage, int defence, int accuracy) : Character{Name, health, damage, defence, accuracy} {}

void Soldier::attack(Imob& character)
{
	if (!calculateAccuracy()) {
		std::cout << Name << " - mised\n";
		return;
	}
	character.takeDamage(damage);
}

void Soldier::takeDamage(int _damage)
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

std::string Soldier::getName() {
	return Name;
}
double Soldier::getHealth() {
	return health;
}
double Soldier::getDamage() {
	return damage;
}
int Soldier::getDefence() {
	return defence;
}
bool Soldier::getisAlive() {
	return isAlive;
}