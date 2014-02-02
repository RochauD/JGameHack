#include "stdafx.h"
#include "grid.h"


grid::grid()
{
}


grid::~grid()
{

}

void grid::SetSpriteManager(spriteManager* pSpriteManager)
{
	this->mSpriteManager = pSpriteManager;
}
void grid::SetWindow(sf::RenderWindow* pWindow)
{
	this->mWindow = pWindow;
}

void grid::SetUpGrid()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			(this->gridArray[i][j]).SetSpriteManager(this->mSpriteManager);
			(this->gridArray[i][j]).SetWindow(this->mWindow);
			(this->gridArray[i][j]).SetUp();
			(this->gridArray[i][j]).GetSprite()->setPosition(j  * 100 + 300,i  * 100 + 100);
			
		}
	}
}
void grid::SetUpGrid(spriteManager* pSpriteManager, sf::RenderWindow* pWindow)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			(this->gridArray[i][j]).SetSpriteManager(pSpriteManager);
			(this->gridArray[i][j]).SetWindow(pWindow);
			(this->gridArray[i][j]).SetUp();
			(this->gridArray[i][j]).GetSprite()->setPosition((j + 1) * 100 + 300, (i + 1) * 100 + 100);
		}
	}
}

void grid::UpdateGrid()
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*this->mWindow);
	if (localPosition.x >= 300 && localPosition.x <= 1300)
	{
		if (localPosition.y >= 100 && localPosition.y <= 600)
		{
			
		}
	}
}

