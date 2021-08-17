#include "mob.h"
#include "randomizer.h"

void Mob::generateCrew(size_t x)
{
	for (int i{}; i < x; i++) {
		Random obj(50, 0);
		std::string Name{ "Crewmate " };
		Name.append(std::to_string(i));
		People.emplace_back ( Name, obj.getRandomNumber(), obj.getRandomNumber() , obj.getRandomNumber() , obj.getRandomNumber() );
	}
}

Mob::Mob(std::string _Name, size_t number) : Name{ _Name } {
	generateCrew( number );
}

void Mob::attack(Itroops& character){
	Random obj(People.size()-1, 0);
	auto man{ obj.getRandomNumber() };
	People[man].attack(character);
}

void Mob::takeDamage(int damage){
	Random obj(People.size() - 1, 0);
	auto man{ obj.getRandomNumber() };
	People[man].takeDamage(damage);

	if (People[man].getHealth() <= 0) {
		std::cout << People[man].getName() << " defeated! People left: " << People.size() - 1 << std::endl;
		People.erase(People.begin() + man);
	}
}

bool Mob::getisAlive() {
	if (People.size() == 0) {
		return false;
	}
	else{
		return true;
	}
}