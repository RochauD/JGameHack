#pragma once

#include "stdafx.h"
#include "textureManager.h"

struct z_compare;
typedef std::pair<int, sf::Sprite*> spritePair;
typedef std::set<spritePair, z_compare> spriteSet;

struct z_compare
{
	bool operator() (const spritePair& lhs, const spritePair& rhs) const
	{
		return lhs.first < rhs.first;
	}
};

class spriteManager
{
private:
	spriteSet mSpriteSet;
	textureManager* mTextureManager;
	sf::RenderWindow* mWindow;

public:

	void SetTextureManager(textureManager* pTextureManager);
	void SetWindow(sf::RenderWindow* pWindow);

	sf::Sprite* addNewSprite(std::string* filename, int zValue);
	void deleteSprite(sf::Sprite* pSprite);

	spriteSet::iterator findSprite(sf::Sprite* pSprite);

	void DrawAll();
	



	spriteManager();
	~spriteManager();


};

