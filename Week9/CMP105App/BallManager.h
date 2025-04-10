#pragma once
#include "Ball.h"

class BallManager {
public:
	BallManager();
	~BallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:

	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;

};