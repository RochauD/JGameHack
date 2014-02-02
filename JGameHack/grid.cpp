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
	this->selectedGrid = sf::Mouse::getPosition(*this->mWindow);
	this->selectedGrid.x = (this->selectedGrid.x - 300) / 100;
	this->selectedGrid.y = (this->selectedGrid.y - 100) / 100;

	if ((0 <= this->selectedGrid.x) && (this->selectedGrid.x <= 9) && (0 <= this->selectedGrid.y) && (this->selectedGrid.y <= 4))
	{
		//Is in grid; coords are stored in (x,y)
		// uncomment fo automatic crashes
		this->mSpriteManager->changeTexture(this->gridArray[this->selectedGrid.y][this->selectedGrid.x].GetSprite(), &std::string("square2.png"), 5);
		
	}
	else
	{
		this->selectedGrid.x = -1;
		this->selectedGrid.y = -1;
	}
}

