#pragma once

#include "stdafx.h"
#include "textureManager.h"



class square
{
private:
	int state;
	bool owner;
	textureManager* mTextureManager;
	sf::RenderWindow* mWindow;


public:
	void SetTextureManager(textureManager* pTextureManager);
	void SetWindow(sf::RenderWindow* pWindow);



	square();
	~square();
};

