#include "Card.h"
#include <vector> 


#ifndef _PLAYER_
#define _PLAYER_

class Player{
	const static int DEFAULT_HP = 200;
	

	std::list<Card> cardList;
	std::list<Unit> unitList;
	int HP;
	int mana;
public:
	Player();
	
	void addMana(int);
	bool removeMana(int);
	void removeHP(int);

	void addCard(Card &);
	void removeCard(Card &);

	void addUnit(Unit &);
	void removeUnit(Unit &);

	int getCardNumber();

	const static int MAX_CARDS = 5;
};

#endif