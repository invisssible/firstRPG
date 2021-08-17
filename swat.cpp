#include<iostream>

#include "swat.h"
#include "randomizer.h"

SWAT::SWAT(std::string Name, double health, double damage, int defence, int accuracy, int _granade) 
	: Character{ Name, health, damage, defence, accuracy }, granade{_granade} {}

void SWAT::attack(Imob& character)
{
	if (!calculateAccuracy()) {
		std::cout << Name << " - mised\n";
		return;
	}
	if (granade > 0) {
		Random id{ 1,0 };
		if (id.getRandomNumber() == 1) {
			character.takeDamage(damage*2);
			granade--;
			std::cout << "Fire in the hole. Damage is: " << damage * 2 << std::endl;
		}
	}
	character.takeDamage(damage);
}

void SWAT::takeDamage(int _damage)
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
std::string SWAT::getName() {
	return Name;
}
double SWAT::getHealth() {
	return health;
}
double SWAT::getDamage() {
	return damage;
}
int SWAT::getDefence() {
	return defence;
}
bool SWAT::getisAlive() {
	return isAlive;
}