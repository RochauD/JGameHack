#include "Player.h"

Player::Player(){
	this->HP = this->DEFAULT_HP;
	this->mana = 0;
}

void Player::addMana(int value){
	this->mana += value;
}

bool Player::removeMana(int value){
	if (this->mana >= value){
		this->mana -= value;
		return true;
	}
	else 
		return false;
}

void Player::removeHP(int value){
	this->HP -= value;
}

void Player::addCard(Card &crd){
	if (this->cardList.size() < this->MAX_CARDS)
		this->cardList.push_front(crd);
}

void Player::removeCard(Card &crd){
	this->cardList.remove_if([crd](Card &aCard){crd.getId() == aCard.getId();});
}

void Player::addUnit(Unit &unit){
	this->unitList.push_front(unit);
}

void Player::removeUnit(Unit &unit){
	this->unitList.remove_if([unit](Unit &anUnit){unit.getId() == anUnit.getId();});
}

int Player::getCardNumber(){
	return this->cardList.size();
} 

bool Player::playCard(Card &aCard){
	if (this->removeMana(aCard.getMana())){
		this->removeCard(aCard);
		return true;
	}
	else
		return false;
}