#pragma once

#include "stdafx.h"
#include "spriteManager.h"



class square
{
private:
	int state;
	bool owner;
	spriteManager* mSpriteManager;
	sf::RenderWindow* mWindow;
	sf::Sprite* mSprite;
	std::string fileName;
	std::string fileName2;

public:
	void SetSpriteManager(spriteManager* pSpriteManager);
	void SetWindow(sf::RenderWindow* pWindow);
	sf::Sprite* GetSprite();


	void SetUp();
	void SetFileName(std::string fileName);
	void SetFileName2(std::string fileName);


	square();
	~square();
};

