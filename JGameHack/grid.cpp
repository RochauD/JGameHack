#include "stdafx.h"
#include "grid.h"


grid::grid()
{
}


grid::~grid()
{
}

void grid::SetTextureManager(textureManager* pTextureManager)
{
	this->mTextureManager = pTextureManager;
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
			(this->gridArray[i][j]).SetTextureManager(this->mTextureManager);
			(this->gridArray[i][j]).SetWindow(this->mWindow);
		}
	}
}
void grid::SetUpGrid(textureManager* pTextureManager, sf::RenderWindow* pWindow)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			(this->gridArray[i][j]).SetTextureManager(pTextureManager);
			(this->gridArray[i][j]).SetWindow(pWindow);
		}
	}
}

