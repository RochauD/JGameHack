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
	this->toogleUI = true;

	ui[0] = this->mSpriteManager->addNewSprite(&std::string("sword.png"), 10);
	ui[1] = this->mSpriteManager->addNewSprite(&std::string("boot.png"), 10);

	uiState = false;
	ToogleUI();

	sBArray[0][0].loadFromFile("bin/sound/sound (1).ogg");
	sBArray[0][1].loadFromFile("bin/sound/sound (2).ogg");
	sBArray[0][2].loadFromFile("bin/sound/sound (3).ogg");
	sBArray[0][3].loadFromFile("bin/sound/sound (4).ogg");
	sBArray[0][4].loadFromFile("bin/sound/sound (5).ogg");
	sBArray[0][5].loadFromFile("bin/sound/sound (6).ogg");
	sBArray[0][6].loadFromFile("bin/sound/sound (7).ogg");
	sBArray[0][7].loadFromFile("bin/sound/sound (8).ogg");
	sBArray[0][8].loadFromFile("bin/sound/sound (9).ogg");
	sBArray[0][9].loadFromFile("bin/sound/sound (10).ogg");

	sBArray[1][0].loadFromFile("bin/sound/sound (11).ogg");
	sBArray[1][1].loadFromFile("bin/sound/sound (12).ogg");
	sBArray[1][2].loadFromFile("bin/sound/sound (13).ogg");
	sBArray[1][3].loadFromFile("bin/sound/sound (14).ogg");
	sBArray[1][4].loadFromFile("bin/sound/sound (15).ogg");
	sBArray[1][5].loadFromFile("bin/sound/sound (16).ogg");
	sBArray[1][6].loadFromFile("bin/sound/sound (17).ogg");
	sBArray[1][7].loadFromFile("bin/sound/sound (18).ogg");
	sBArray[1][8].loadFromFile("bin/sound/sound (19).ogg");
	sBArray[1][9].loadFromFile("bin/sound/sound (20).ogg");

	sBArray[2][0].loadFromFile("bin/sound/sound (21).ogg");
	sBArray[2][1].loadFromFile("bin/sound/sound (22).ogg");
	sBArray[2][2].loadFromFile("bin/sound/sound (23).ogg");
	sBArray[2][3].loadFromFile("bin/sound/sound (24).ogg");
	sBArray[2][4].loadFromFile("bin/sound/sound (25).ogg");
	sBArray[2][5].loadFromFile("bin/sound/sound (26).ogg");
	sBArray[2][6].loadFromFile("bin/sound/sound (27).ogg");
	sBArray[2][7].loadFromFile("bin/sound/sound (28).ogg");
	sBArray[2][8].loadFromFile("bin/sound/sound (29).ogg");
	sBArray[2][9].loadFromFile("bin/sound/sound (30).ogg");

	sBArray[3][0].loadFromFile("bin/sound/sound (31).ogg");
	sBArray[3][1].loadFromFile("bin/sound/sound (32).ogg");
	sBArray[3][2].loadFromFile("bin/sound/sound (33).ogg");
	sBArray[3][3].loadFromFile("bin/sound/sound (34).ogg");
	sBArray[3][4].loadFromFile("bin/sound/sound (35).ogg");
	sBArray[3][5].loadFromFile("bin/sound/sound (36).ogg");
	sBArray[3][6].loadFromFile("bin/sound/sound (37).ogg");
	sBArray[3][7].loadFromFile("bin/sound/sound (38).ogg");
	sBArray[3][8].loadFromFile("bin/sound/sound (39).ogg");
	sBArray[3][9].loadFromFile("bin/sound/sound (40).ogg");

	sBArray[4][0].loadFromFile("bin/sound/sound (41).ogg");
	sBArray[4][1].loadFromFile("bin/sound/sound (42).ogg");
	sBArray[4][2].loadFromFile("bin/sound/sound (43).ogg");
	sBArray[4][3].loadFromFile("bin/sound/sound (44).ogg");
	sBArray[4][4].loadFromFile("bin/sound/sound (45).ogg");
	sBArray[4][5].loadFromFile("bin/sound/sound (46).ogg");
	sBArray[4][6].loadFromFile("bin/sound/sound (47).ogg");
	sBArray[4][7].loadFromFile("bin/sound/sound (48).ogg");
	sBArray[4][8].loadFromFile("bin/sound/sound (49).ogg");
	sBArray[4][9].loadFromFile("bin/sound/sound (50).ogg");

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
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					if (this->uiState == true)
					{
						this->ToogleUI();
						this->uiState = false;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					/*
					if (this->uiState == false)
					{
						ui[0]->setPosition(curMouse.x - 25, curMouse.y - 70);
						ui[1]->setPosition(curMouse.x - 25, curMouse.y + 20);
						this->oldMouse = curMouse;
						this->uiState = true;
					}
					else
					{
						if (this->oldMouse.x - 25 <= curMouse.x && curMouse.x <= this->oldMouse.x + 25)
						{
							if (this->oldMouse.y - 70 <= curMouse.y && curMouse.y <= this->oldMouse.y - 20)
							{
								
								buffer.loadFromFile("bin/sound/dragon.ogg");
								sound.setBuffer(buffer);
								sound.play();
							}
							else if (this->oldMouse.y + 20 <= curMouse.y && curMouse.y <= this->oldMouse.y + 70)
							{
								buffer.loadFromFile("bin/sound/soldier.ogg");
								sound.setBuffer(buffer);
								sound.play();
							}
						}
					}
					*/
				}
								
				sArray[this->selectedGrid.y][this->selectedGrid.x].setBuffer(sBArray[this->selectedGrid.y][this->selectedGrid.x]);
				sArray[this->selectedGrid.y][this->selectedGrid.x].play();
				
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
		this->toogleUI = true;
	}
	else
	{
		ui[0]->setPosition(-100, -100);
		ui[1]->setPosition(-100, -100);
		this->toogleUI = false;
	}
}