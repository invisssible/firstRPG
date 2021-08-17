#pragma once
class Itroops;
class Imob {
public:
	virtual void attack(Itroops& obj)=0;
	virtual void takeDamage(int damage)=0;
	virtual std::string getName() = 0;
	virtual double getHealth() = 0;
	virtual double getDamage() = 0;
	virtual int getDefence() = 0;
	virtual bool getisAlive() = 0;
};
class Itroops {
public:
	virtual void attack(Imob& obj) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual std::string getName() = 0;
	virtual double getHealth() = 0;
	virtual double getDamage() = 0;
	virtual int getDefence() = 0;
	virtual bool getisAlive() = 0;
};