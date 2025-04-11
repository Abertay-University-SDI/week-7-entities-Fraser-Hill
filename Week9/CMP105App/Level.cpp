#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager = new BallManager();
	goombaManager = new GoombaManager(window->getSize());
	player = new Player();
	player->setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//if (input->isKeyDown(sf::Keyboard::Space)) {
		//ballManager->spawn(sf::Vector2f spawnPosition);
		//input->setKeyUp(sf::Keyboard::Space);
	//}
	//if (input->isKeyDown(sf::Keyboard::W)) {
	//	goombaManager->spawn();
	//	input->setKeyUp(sf::Keyboard::W);
	//}

	player->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ballManager->update(dt);
	ballManager->deathCheck();

	goombaManager->update(dt);
	goombaManager->deathCheck();

	player->update(dt);
	
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager->render(window);

	goombaManager->render(window);

	window->draw(*player);
	player->render(window);
	endDraw();
}
