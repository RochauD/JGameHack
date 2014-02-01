#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

/*
	structure of card file:
	name
	description
	mana
	SPELL|UNIT
	case UNIT:
		strength
		health
		steps
*/

int Card::getId(){
	return this->Id;
}

int Card::getMana(){
	return this->mana;
}

std::istream& operator>>(std::istream& os, const Card& aCard){
  	os >> this->name; // SPELL / UNIT
  	os >> this->description;
  	os >> this->mana;
  	os >> this->damage; // set to 0 if UNIT type
  	os >> this->strength; // set to 0 if SPELL type
  	os >> this->health; // set to 0 if SPELL type
  	os >> this->Id; 
  	os >> this->image; // the path to the image;
  	return os;
}

int Card::use(std::list<Unit> & unitList){
	if (this->name.compare("UNIT")){
		Unit aUnit(this->health, this->damage, this->Id); // add x and y coordinates
		unitList.push_front(aUnit);
		return -1;
	}
	else{
		return this->damage;
	}
}

std::string Card::getImage(){
	return this->image;
}