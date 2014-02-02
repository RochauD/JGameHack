#pragma once
#include "stdafx.h"
#include "square.h"
#include "unit.h"
#include "spriteManager.h"



class grid
{
private:

	square gridArray[5][10];

	spriteManager* mSpriteManager;
	sf::RenderWindow* mWindow;
	sf::Vector2i selectedGrid;
	sf::Vector2i oldMouse;
	sf::Vector2i oldSquare;
	sf::Sprite* ui[2];
	bool toogleUI;
	bool uiState;
	sf::SoundBuffer buffer;
	sf::Sound sound;




public:
	void SetSpriteManager(spriteManager* mSpriteManager);
	void SetWindow(sf::RenderWindow* pWindow);

	void SetUpGrid();
	void SetUpGrid(spriteManager* pSpriteManager, sf::RenderWindow* pWindow);
	void UpdateGrid();

	void ToogleUI();

	grid();
	~grid();
};

