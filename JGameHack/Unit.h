#pragma once

#include "stdafx.h"
//#include "Card.h"

class unit 
{
private:
	int hp;
	int strength;
	std::string title;
	std::string description;
public:
	unit(int, int, std::string, std::string);
	bool isAlive();
	void applyDamage(int);
	int getHP();
	int getStrength();
};


