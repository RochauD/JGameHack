#include "stdafx.h"
#include "textureManager.h"


textureManager::textureManager()
{
}


textureManager::~textureManager()
{
}


void textureManager::setFileDirectory(std::string path)
{
	this->fileDirectory = path;
}


std::string textureManager::getFileDirectory()
{
	return fileDirectory;
}



bool textureManager::loadTexture(std::string* fileName, sf::Texture* pTexture)
{
	textureMapType::iterator iter = this->textureMap.find(*fileName);
	if (iter != this->textureMap.end())
	{
		pTexture = (this->textureMap[*fileName].second);
	}
	else
	{
		sf::Texture* curTexture = new sf::Texture();
		if (!curTexture->loadFromFile(fileDirectory + (*fileName)))
		{
			return false;
		}
		else
		{
			this->textureMap.insert(std::pair<std::string, intTexturePair>(*fileName, intTexturePair(1, curTexture)));
			*pTexture = *curTexture;
		}
	}
	return true;
}


void textureManager::deleteTexture(std::string* fileName)
{
	if (this->textureMap[*fileName].first == 1)
	{
		delete textureMap[*fileName].second;
	}
	else
	{
		this->textureMap[*fileName].first--;
	}
}