#pragma once

#include "stdafx.h"
#include "spriteManager.h"



class square
{
private:
	int state;
	bool owner;
	spriteManager* mSpriteManager;
	sf::RenderWindow* mWindow;
	sf::Sprite mSprite;


public:
	void SetSpriteManager(spriteManager* pSpriteManager);
	void SetWindow(sf::RenderWindow* pWindow);



	square();
	~square();
};

