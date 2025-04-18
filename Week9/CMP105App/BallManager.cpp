#include "BallManager.h"
#include <iostream>

BallManager::BallManager() {
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++) {
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(10, 10));
	}
}

BallManager::~BallManager() {

}

void BallManager::update(float dt) {
	timeSinceCountPrinted += dt;
	int numberOfBallsAlive = 0;
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			numberOfBallsAlive++;
			balls[i].update(dt);
		}
	}

	if (timeSinceCountPrinted > Time_Between_Printing) {
		std::cout << numberOfBallsAlive << "\n";
	}
	deathCheck();
}

void BallManager::spawn(sf::Vector2f spawnPosition) {
	for (int i = 0; i < balls.size(); i++) {
		if (!balls[i].isAlive()) {
			balls[i].setAlive(true);
			balls[i].setVelocity(100, 0);
			balls[i].setPosition(spawnPosition);
			return;
		}
	}
}

void BallManager::deathCheck() {

	for (int i = 0; i < balls.size();i++) {
		if (balls[i].isAlive()) {
			if (balls[i].getPosition().x < -100) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > 800) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > 600) {
				balls[i].setAlive(false);
			}
		}
	}
}

void BallManager::render(sf::RenderWindow * window) {
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			window->draw(balls[i]);
		}
	}
}