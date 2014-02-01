#include "Card.h"
#include <stdlib.h>

#ifndef DECK_INCLUDED
#define DECK_INCLUDED

#define CARDS_IN_DECK 10

class Deck {
	Card cards[CARDS_IN_DECK];
	int top_card;
public:
	Deck();
	Card drawCard();
	bool isEmpty();
};


#endif
