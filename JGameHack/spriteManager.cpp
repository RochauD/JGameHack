#include "stdafx.h"
#include "spriteManager.h"


spriteManager::spriteManager()
{
}


spriteManager::~spriteManager()
{
	DeleteAll();
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
	static sf::Texture* loadingTexture;
	if (!this->mTextureManager->loadTexture(filename, &loadingTexture))
	{
		return NULL;
	}
	else
	{
		curSprite->setTexture(*loadingTexture);
		this->mSpriteSet.insert(spritePair(zValue, curSprite));
		return curSprite;
	}
}

void spriteManager::deleteSprite(sf::Sprite* pSprite, std::string* fileName)
{
	spriteSet::iterator iter = findSprite(pSprite);
	this->mTextureManager->deleteTexture(fileName);
	delete iter->second;
	this->mSpriteSet.erase(iter);
}

bool spriteManager::changeTexture(sf::Sprite* pSprite, std::string* filename, int zValue)
{
	spriteSet::iterator iter = findSprite(pSprite);
	static sf::Texture *loadingTexture;
	if (!this->mTextureManager->loadTexture(filename, &loadingTexture))
	{
		return EXIT_FAILURE;
	}
	else
	{
		(*iter->second).setTexture(*loadingTexture);
		this->mSpriteSet.insert(spritePair(zValue, iter->second));
		this->mSpriteSet.erase(iter);
		return true;
	}

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

void spriteManager::DeleteAll()
{
	for (spriteSet::iterator iter = this->mSpriteSet.begin(); iter != this->mSpriteSet.end(); iter++)
	{
		delete &iter->second;
		this->mSpriteSet.erase(iter);
	}
}