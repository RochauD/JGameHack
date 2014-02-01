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
	std::string name, description;
	int mana;
	int damage;

	int strength;
	int health;
	int Id;

	std::string image;
public: 
	int getMana();
	int getId ();
	int use(std::list<Unit>&);

	// name description mana
	friend std::istream& operator>>(std::istream&, const Card&){

	
};

#endif