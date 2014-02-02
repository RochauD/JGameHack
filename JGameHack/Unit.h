#ifndef UNIT_IS_LOADED
#define UNIT_IS_LOADED
#include <string>
//#include "Card.h"

class Unit {
private:
	int hp, strength;
	std::string title, description;
public:
	Unit(int, int, std::string, std::string);
	bool isAlive();
	void applyDamage(int);
	int getHP();
	int getStrength();
};

#endif
