#pragma once
#include "Ball.h"

class BallManager {
public:
	BallManager();
	~BallManager();

	void spawn(sf::Vector2f spawnPosition);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:

	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	float timeSinceCountPrinted = 0.f;

	const float Time_Between_Printing = 3.0f;

};