#include <iostream>
#include <thread>
#include <chrono>
#include "randomizer.h"
#include "soldier.h"
#include "swat.h"
#include "marine.h"
#include "mob.h"

using namespace std::chrono_literals;

int main() {
	Marine Ignat{"Marine Ignat",175, 70, 20, 75, 2};
	Mob Crew{ "The crew",30 };

	while (true) {
		std::cout << "Marine attacs Crew! \n";
		Ignat.attack(Crew);
		if (!Crew.getisAlive()) {
			std::cout << "Marine wins! Rebelians failed...\n";
			break;
		}
		std::cout << "Crew attacs Marine! \n";
		Crew.attack(Ignat);
		if (!Ignat.getisAlive()) {
			std::cout << "Rebelians wins! Government failed...\n";
			break;
		}
		std::cout << "Marine hp is " << Ignat.getHealth() << std::endl;

		//std::this_thread::sleep_for(300ms);
	}
	return 0;
}