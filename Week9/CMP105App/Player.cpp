#include "Player.h"

Player::Player() {
	texture.loadFromFile("gfx/Goomba.png");
	setTexture(&texture); 

	setPosition(50, 500);
	setSize(sf::Vector2f(80, 80));

	bulletManager = new BallManager();
}

Player::~Player() {

}

void Player::shoot() {

}

void Player::update(float dt) {
	move(velocity * dt);

	bulletManager->update(dt);
	bulletManager->deathCheck();
}

void Player::handleInput(float dt) {

	if (input->isKeyDown(sf::Keyboard::Up)) {
		velocity.y -= 2;
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		velocity.y += 2;
	}
	if (input->isKeyDown(sf::Keyboard::Left)) {
		velocity.x -= 2;
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		velocity.x += 2;
	}
	if (input->isKeyDown(sf::Keyboard::R)) {
		velocity = { 0 ,0 };
		setPosition(50, 500 );
	}
	if (input->isKeyDown(sf::Keyboard::Q)) {
		bulletManager->spawn(getPosition());
		input->setKeyUp(sf::Keyboard::Q);
	}

}

void Player::render(sf::RenderWindow* window) {

	bulletManager->render(window);

}