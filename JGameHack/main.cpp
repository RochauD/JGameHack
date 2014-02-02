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
	sf::Sprite* backgroundSprite = gSpriteManager->addNewSprite(&std::string("background.png"), -100);
	
	grid gameGrid;
	gameGrid.SetSpriteManager(gSpriteManager);
	gameGrid.SetWindow(gWindow);
	gameGrid.SetUpGrid();

	sf::RectangleShape playerZone[2];
	playerZone[0].setPosition(300, 100);
	playerZone[0].setSize(sf::Vector2f(200.0, 500.0));
	playerZone[0].setFillColor(sf::Color(215, 52, 52, 125));

	playerZone[1].setPosition(1100, 100);
	playerZone[1].setSize(sf::Vector2f(200.0, 500.0));
	playerZone[1].setFillColor(sf::Color(52, 52, 215, 125));

	//setup background music



	sf::Music music;
	if (!music.openFromFile("bin/sound/HeartOfCourage.ogg"))
		return -1; // error
	music.setLoop(true);

	music.play();
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

		gameGrid.UpdateGrid();


		// Clear screen
		window.clear();

		//Draw stuff in here
	

		gSpriteManager->DrawAll();
		window.draw(playerZone[0]);
		window.draw(playerZone[1]);

		// Update the window
		window.display();
	}

	gSpriteManager->deleteSprite(backgroundSprite, &std::string("background.png"));
	gSpriteManager->DeleteAll();
	return EXIT_SUCCESS;
}









