// main.cpp 
//

#include "stdafx.h"
#include "textureManager.h"

textureManager gTextureManager;

int main(int argc, char* argv[])
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "JGameHack");
	

	// Initalize texture Handler
	gTextureManager.setFileDirectory("bin/textures/");

	sf::Texture testTex;
	sf::Texture testTex2;
	std::string test("test.png");



	gTextureManager.loadTexture(&test, &testTex);
	gTextureManager.loadTexture(&test, &testTex2);




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
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();

		//Draw stuff in here

		window.draw(testSprite);

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;

	return 0;
}









