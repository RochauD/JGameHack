#include "Card.h"
#include "Deck.h"


Deck::Deck() {
	int i = 0;						//At the moment putting random cards into the deck.
									//Could later be changed to a shuffled deck.
	while (i++ < CARDS_IN_DECK) {
		cards[i] = Card(rand()%CARDS_IN_DECK);
	}
	top_card = CARDS_IN_DECK-1;
}

Card Deck::drawCard() {
	return cards[top_card--];
}

bool Deck::isEmpty() {
	return (top_card<=0);
}
