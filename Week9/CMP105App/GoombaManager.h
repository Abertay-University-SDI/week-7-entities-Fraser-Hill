#pragma once
#include "Goomba.h"

class GoombaManager {
public:
	GoombaManager(sf::Vector2u windowSize);
	~GoombaManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:

	std::vector<Goomba> Goombas;
	float spawnY;
	sf::Texture texture;
	sf::Font font;
	sf::Text message;
	float timeSinceCountPrinted = 0.f;
	sf::Vector2u sizeOfWindow;

	const float Time_Between_Printing = 3.0f;
	const int GOOMBA_COUNT = 40;

};