#pragma once

#include "stdafx.h"

typedef std::pair<int, sf::Texture*> intTexturePair;
typedef std::map<std::string, intTexturePair> resourceMapType;


class resourceManager
{
private:
	resourceMapType resourceMap;
	std::string fileDirectory;


public:
	resourceManager();
	~resourceManager();

	void setFileDirectory(std::string path);
	std::string getFileDirectory();

	void incrementUsageCount(std::string* key);


	bool loadResource(std::string* fileName, sf::Texture* pTexture);
	void deleteResource(std::string* fileName);
};

