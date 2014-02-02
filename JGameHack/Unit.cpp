#include "Unit.h"

Unit::Unit(int stre, int health, std::string ti, std::string descr) {
	strength = stre;
	hp = health;
	title = ti;
	description = descr;
}

bool Unit::isAlive() {
	return (hp>0);
}

void Unit::applyDamage(int amount) {
	hp -= amount;
}

int Unit::getHP() {
	return hp;
}

int Unit::getStrength() {
	return strength;
}
