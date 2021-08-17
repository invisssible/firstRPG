#include <iostream>

#include "marine.h"
#include "randomizer.h"

bool Marine::becomeSober(){
	if (drunkTime >= 5) {
		drunkTime = 0;
		isDrunk = false;
		return true;
	}
	return false;
}

Marine::Marine(std::string Name, double health, double damage, int defence, int accuracy, int _vodka)
	: Character{ Name, health, damage, defence, accuracy }, vodka{ _vodka }, halfHealth{ health / 2 }, isDrunk{ false }, drunkTime{ 0 }{}

void Marine::attack(Imob& character)
{	
	if (!calculateAccuracy()) {
		std::cout << Name << " - mised\n";
		if (isDrunk) {
			if (!becomeSober()) {
				drunkTime++;
			}
		}
		return;
	}
	if (health < halfHealth && !isDrunk) {
		if (vodka == 0) {
			std::cout << "~~~~ Hangover of " << Name << ". Armor is reducing!" << std::endl;
			defence -= (defence * 20) / 100;
			character.takeDamage(damage);
			return;
		}
		isDrunk = true;
		accuracy -= (accuracy * 60) / 100;
		vodka--;
		std::cout << "~~~~ Vodka activated! DMG*5: " << damage * 5 << std::endl;
	}
	if (isDrunk == true) {
		if (becomeSober()) {
			accuracy += (accuracy * 150) / 100;
			std::cout << "[log] accuracy is " << accuracy << std::endl;
			character.takeDamage(damage);
			return;
		}
		drunkTime++;
		character.takeDamage(damage*5);
		return;
	}
	character.takeDamage(damage);
}

void Marine::takeDamage(int _damage)
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

std::string Marine::getName() {
	return Name;
}
double Marine::getHealth() {
	return health;
}
double Marine::getDamage() {
	return damage;
}
int Marine::getDefence() {
	return defence;
}
bool Marine::getisAlive() {
	return isAlive;
}
