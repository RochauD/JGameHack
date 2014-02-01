// main.cpp 
//

#include "stdafx.h"
#include "textureManager.h"

textureManager* gTextureManager;
sf::RenderWindow* gWindow;

int main(int argc, char* argv[])
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "JGameHack", sf::Style::Fullscreen);
	gWindow = &window;
	
	textureManager lTextureManager;
	gTextureManager = &lTextureManager;


	// Initalize texture Handler
	gTextureManager->setFileDirectory("bin/textures/");

	//initalize background
	sf::Sprite background;
	sf::Texture backgroundTex;
	gTextureManager->loadTexture(&std::string("background.png") , &backgroundTex);
	background.setTexture(backgroundTex);
	


	sf::Texture testTex;
	sf::Texture testTex2;
	std::string test("square1.png");



	gTextureManager->loadTexture(&test, &testTex);
	gTextureManager->loadTexture(&test, &testTex2);




	sf::Sprite testSprite;
	testSprite.setTexture(testTex);

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

		window.draw(testSprite);
		window.draw(background);

		// Update the window
		window.display();
	}

	gTextureManager->deleteTexture(&std::string("background.png"));

	return EXIT_SUCCESS;

	return 0;
}









