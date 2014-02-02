#include "stdafx.h"
#include "unit.h"

unit::unit(int stre, int health, std::string ti, std::string descr) {
	strength = stre;
	hp = health;
	title = ti;
	description = descr;
}

bool unit::isAlive() {
	return (hp>0);
}

void unit::applyDamage(int amount) {
	hp -= amount;
}

int unit::getHP() {
	return hp;
}

int unit::getStrength() {
	return strength;
}
