#include "stdafx.h"
#include "square.h"



square::square()
{
}


square::~square()
{
}

void square::SetTextureManager(textureManager* pTextureManager)
{
	this->mTextureManager = pTextureManager;
}
void square::SetWindow(sf::RenderWindow* pWindow)
{
	this->mWindow = pWindow;
}

