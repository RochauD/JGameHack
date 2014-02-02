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
	this->oldSquare.x = -1;
	this->oldSquare.y = -1;
	this->toogleUI = false;

	ui[0] = this->mSpriteManager->addNewSprite(&std::string("sword.png"), 10);
	ui[1] = this->mSpriteManager->addNewSprite(&std::string("boot.png"), 10);


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
	this->oldSquare.x = -1;
	this->oldSquare.y = -1;
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
	sf::Vector2i curMouse = sf::Mouse::getPosition(*this->mWindow);
	this->selectedGrid = curMouse;

	if (this->selectedGrid.x >= 300 && this->selectedGrid.x <= 1300)
	{
		if (this->selectedGrid.y >= 100 && this->selectedGrid.y <= 600)
		{
			this->selectedGrid.x = (this->selectedGrid.x - 300) / 100;
			this->selectedGrid.y = (this->selectedGrid.y - 100) / 100;

			if ((0 <= this->selectedGrid.x) && (this->selectedGrid.x <= 9) && (0 <= this->selectedGrid.y) && (this->selectedGrid.y <= 4))
			{
				if (oldSquare.x >= 0 && oldSquare.x <= 9)
				{
					if (oldSquare.y >= 0 && oldSquare.y <= 4)
					{
						this->mSpriteManager->changeTexture(this->gridArray[this->oldSquare.y][this->oldSquare.x].GetSprite(), &std::string("square1.png"), 5);
					}
				}
				this->mSpriteManager->changeTexture(this->gridArray[this->selectedGrid.y][this->selectedGrid.x].GetSprite(), &std::string("square2.png"), 5);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					ui[0]->setPosition(curMouse.x -25, curMouse.y - 70);
					ui[1]->setPosition(curMouse.x -25, curMouse.y + 20);
				}
								
				
				
				this->oldSquare = this->selectedGrid;

			}
			else
			{
				this->mSpriteManager->changeTexture(this->gridArray[this->oldSquare.y][this->oldSquare.x].GetSprite(), &std::string("square1.png"), 5);
				this->selectedGrid.x = -1;
				this->selectedGrid.y = -1;
			}
		}
		else 
		{
			this->mSpriteManager->changeTexture(this->gridArray[this->oldSquare.y][this->oldSquare.x].GetSprite(), &std::string("square1.png"), 5);
		}
	}
	else
	{
		this->mSpriteManager->changeTexture(this->gridArray[this->oldSquare.y][this->oldSquare.x].GetSprite(), &std::string("square1.png"), 5);
	}
}

void grid::ToogleUI()
{
	if (this->toogleUI == false)
	{
		ui[0]->setColor(sf::Color(0, 0, 0, 255));
		ui[1]->setColor(sf::Color(0, 0, 0, 255));
	}
	else
	{
		ui[0]->setColor(sf::Color(0, 0, 0, 0));
		ui[1]->setColor(sf::Color(0, 0, 0, 0));
	}
}