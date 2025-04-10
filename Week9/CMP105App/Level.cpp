#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager = new BallManager();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		ballManager->spawn();
		input->setKeyUp(sf::Keyboard::Space);
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager->update(dt);
	ballManager->deathCheck();
	
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager->render(window);
	endDraw();
}
