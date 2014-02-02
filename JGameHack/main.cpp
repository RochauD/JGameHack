// main.cpp 
//

#include "stdafx.h"
#include "textureManager.h"
#include "spriteManager.h"
#include "grid.h"

textureManager* gTextureManager;
spriteManager* gSpriteManager;
sf::RenderWindow* gWindow;

int main(int argc, char* argv[])
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "JGameHack");
	gWindow = &window;
	
	textureManager pTextureManager;
	gTextureManager = &pTextureManager;


	// Initalize texture Handler
	gTextureManager->setFileDirectory("bin/textures/");

	//Initalize sprite manager

	spriteManager pSpriteManager;
	gSpriteManager = &pSpriteManager;

	gSpriteManager->SetTextureManager(gTextureManager);
	gSpriteManager->SetWindow(gWindow);


	//initalize background
	gSpriteManager->addNewSprite(&std::string("background.png"), -100);
	
	grid gameGrid;
	gameGrid.SetSpriteManager(gSpriteManager);
	gameGrid.SetWindow(gWindow);


	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
		// Clear screen
		window.clear();

		//Draw stuff in here


		gSpriteManager->DrawAll();

		// Update the window
		window.display();
	}

	gTextureManager->deleteTexture(&std::string("background.png"));

	return EXIT_SUCCESS;

	return 0;
}









