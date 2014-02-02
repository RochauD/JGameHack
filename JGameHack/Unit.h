#pragma once

#include "stdafx.h"
#include "spriteManager.h"
//#include "Card.h"

class unit 
{
private:
	int hp;
	int strength;
	std::string title;
	std::string description;
	sf::Vector2i gridPosition;

	spriteManager* mSpriteManager;
	sf::RenderWindow* mWindow;
public:

	void SetSpriteManager(spriteManager* mSpriteManager);
	void SetWindow(sf::RenderWindow* pWindow);

	unit(int, int, std::string, std::string);
	bool isAlive();
	void applyDamage(int);
	int getHP();
	int getStrength();
};


