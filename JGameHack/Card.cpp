#include "Card.h"

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


Card::Card(int id) {

	idnumber = id;

	std::ifstream infile;
	std::stringstream ss;
	ss << std::setw(3) << std::setfill('0') << id;
	std::string filename = "card"+ss.str()+".txt";
	infile.open(filename.c_str());

	std::string line;

	getline(infile, name);
	getline(infile, description);

	getline(infile, line);

	mana = atoi(line.c_str());

	getline(infile, line);

	if (!line.compare("UNIT")) {
		type = UNIT;
		getline(infile, line);
		strength = atoi(line.c_str());
		getline(infile, line);
		health = atoi(line.c_str());
		getline(infile, line);
		steps = atoi(line.c_str());

	} else if (!line.compare("SPELL")) {
		type = SPELL;
	} else {
		//exception
	}

	infile.close();
}
