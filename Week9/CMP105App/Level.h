#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "BallManager.h"
#include "Goomba.h"
#include "GoombaManager.h"
#include "Player.h"

class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	Ball Ball;
	BallManager* ballManager;
	Goomba goomba;
	GoombaManager* goombaManager;

	Player* player;

};