#include "stdafx.h"
#include "resourceManager.h"


resourceManager::resourceManager()
{
}


resourceManager::~resourceManager()
{
}


void resourceManager::setFileDirectory(std::string path)
{
	this->fileDirectory = path;
}


std::string resourceManager::getFileDirectory()
{
	return fileDirectory;
}


void resourceManager::incrementUsageCount(std::string* key)
{
	(this->resourceMap[*key]).first = ((this->resourceMap[*key]).first)++;
}


bool resourceManager::loadResource(std::string* fileName, sf::Texture* pTexture)
{
	resourceMapType::iterator iter = this->resourceMap.find(*fileName);
	if (iter != this->resourceMap.end())
	{
		pTexture = (this->resourceMap[*fileName].second);
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
			this->resourceMap.insert(std::pair<std::string, intTexturePair>(*fileName ,intTexturePair(1, curTexture)));
		}
	}	
	return true;
}


void resourceManager::deleteResource(std::string* fileName)
{
	if (this->resourceMap[*fileName].first == 1)
	{
		delete resourceMap[*fileName].second;
	}
	else
	{
		this->resourceMap[*fileName].first--;
	}
}