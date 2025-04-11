#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager = new BallManager();
	goombaManager = new GoombaManager(window->getSize());
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
	if (input->isKeyDown(sf::Keyboard::W)) {
		goombaManager->spawn();
		input->setKeyUp(sf::Keyboard::W);
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager->update(dt);
	ballManager->deathCheck();

	goombaManager->update(dt);
	goombaManager->deathCheck();
	
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager->render(window);

	goombaManager->render(window);
	endDraw();
}
