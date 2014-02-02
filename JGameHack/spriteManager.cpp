#include "stdafx.h"
#include "spriteManager.h"


spriteManager::spriteManager()
{
}


spriteManager::~spriteManager()
{
}

void spriteManager::SetTextureManager(textureManager* pTextureManager)
{
	this->mTextureManager = pTextureManager;
}
void spriteManager::SetWindow(sf::RenderWindow* pWindow)
{
	this->mWindow = pWindow;
}

sf::Sprite* spriteManager::addNewSprite(std::string* filename, int zValue)
{
	sf::Sprite* curSprite = new sf::Sprite();
	sf::Texture* loadingTexture;
	if (!this->mTextureManager->loadTexture(filename, &loadingTexture))
	{
		EXIT_FAILURE;
		return NULL;
	}
	else
	{
		curSprite->setTexture(*loadingTexture);
		typedef std::pair<int, sf::Sprite*> spritePair;
		this->mSpriteSet.insert(spritePair(zValue, curSprite));
		return curSprite;
	}
}

void spriteManager::deleteSprite(sf::Sprite* pSprite)
{
	spriteSet::iterator iter = findSprite(pSprite);
	delete iter->second;
	this->mSpriteSet.erase(iter);
}

spriteSet::iterator spriteManager::findSprite(sf::Sprite* pSprite)
{
	spriteSet::iterator iter = this->mSpriteSet.begin();
	for (iter; iter != this->mSpriteSet.end(); iter++)
	{
		if (iter->second == pSprite)
		{
			return iter;
		}
	}	
}


void spriteManager::DrawAll()
{
	for (spriteSet::iterator iter = this->mSpriteSet.begin(); iter != this->mSpriteSet.end(); iter++)
	{
		(this->mWindow)->draw(*iter->second);
	}
}