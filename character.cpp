#include "character.h"
#include "randomizer.h"

Character::Character() = default;
Character::Character(std::string _Name, double _health, double _damage, int _defence, int _accuracy): 
	Name{ _Name }, health{ _health }, damage{ _damage }, defence{ _defence }, accuracy{ _accuracy }, isAlive{true} {}
std::string Character::getName() {
	return Name;
}
double Character::getHealth() {
	return health;
}
double Character::getDamage() {
	return damage;
}
int Character::getDefence() {
	return defence;
}
bool Character::getisAlive() {
	return isAlive;
}
bool Character::calculateAccuracy()
{
	Random attackID{99,0};
	auto result{ attackID.getRandomNumber() };
	if (result < accuracy) {
		return true;
	}
	return false;
}


