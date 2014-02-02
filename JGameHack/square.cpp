#include "stdafx.h"
#include "square.h"



square::square()
{
}


square::~square()
{
	this->mSpriteManager->deleteSprite(this->mSprite, &this->fileName);
}

void square::SetSpriteManager(spriteManager* pSpriteManager)
{
	this->mSpriteManager = pSpriteManager;
}
void square::SetWindow(sf::RenderWindow* pWindow)
{
	this->mWindow = pWindow;
}

sf::Sprite* square::GetSprite()
{
	return this->mSprite;
}

void square::SetUp()
{
	this->SetFileName(std::string("square1.png"));
	this->mSprite = this->mSpriteManager->addNewSprite(&this->fileName, 1);
}

void square::SetFileName(std::string fileName)
{
	this->fileName = fileName;
}