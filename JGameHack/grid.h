#pragma once
#include "stdafx.h"
#include "square.h"
#include "textureManager.h"



class grid
{
private:

	square gridArray[5][10];
	textureManager* mTextureManager;
	sf::RenderWindow* mWindow;

public:
	void SetTextureManager(textureManager* pTextureManager);
	void SetWindow(sf::RenderWindow* pWindow);

	void SetUpGrid();
	void SetUpGrid(textureManager* pTextureManager, sf::RenderWindow* pWindow);

	grid();
	~grid();
};

