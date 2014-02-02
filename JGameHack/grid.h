#pragma once
#include "stdafx.h"
#include "square.h"
#include "spriteManager.h"



class grid
{
private:

	square gridArray[5][10];
	spriteManager* mSpriteManager;
	sf::RenderWindow* mWindow;
	sf::Vector2i selectedGrid;
	sf::Vector2i oldSquare;
	sf::Sprite* ui[3];



public:
	void SetSpriteManager(spriteManager* mSpriteManager);
	void SetWindow(sf::RenderWindow* pWindow);

	void SetUpGrid();
	void SetUpGrid(spriteManager* pSpriteManager, sf::RenderWindow* pWindow);
	void UpdateGrid();


	grid();
	~grid();
};

