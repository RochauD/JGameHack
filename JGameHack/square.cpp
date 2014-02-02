#include "stdafx.h"
#include "square.h"



square::square()
{
}


square::~square()
{
}

void square::SetSpriteManager(spriteManager* pSpriteManager)
{
	this->mSpriteManager = pSpriteManager;
}
void square::SetWindow(sf::RenderWindow* pWindow)
{
	this->mWindow = pWindow;
}

