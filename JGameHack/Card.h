#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

#ifndef CARD_IS_INCLUDED
#define CARD_IS_INCLUDED

#define UNIT 0
#define SPELL 0

#define NUMBEROFCARDS 1

class Card {
	int strength, health;
	std::string name, description;
	int mana;
	int steps;
	int type;
	int idnumber;
public:
	Card();
	Card(int);   //Loads card from corresponding file according to id
	int getType() {return type;}
	int getMana() {return mana;}
	int getID () {return idnumber;}

	//Unit create() {Unit(strength, health, ...)}

	//Unit summon();
};

#endif