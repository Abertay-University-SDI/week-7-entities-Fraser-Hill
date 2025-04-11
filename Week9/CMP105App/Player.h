#pragma once
#include "Framework/GameObject.h"
#include "BallManager.h"

class Player:public GameObject
{
public: 
	Player();
	~Player();

	void shoot();

	void update(float dt) override;
	void handleInput(float dt) override;
	void render(sf::RenderWindow* window); 

	BallManager* bulletManager;
	sf::Texture texture;

};

