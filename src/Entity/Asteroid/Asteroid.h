#pragma once
#include <random>

#include "../Entity.h"
#include "../../Sprite/Sprite.h"

class Asteroid : public Entity 
{
private:

	float rotationSpeed;

public:

	Asteroid() : Entity() {};
	Asteroid(float posX, float posY) : Entity(posX, posY) {};
	Asteroid(float posX, float posY, float width, float height) : Entity(posX, posY, width, height) {};
	Asteroid(float posX, float posY, float width, float height, float rot) : Entity(posX, posY, width, height, rot) {};
	
	Sprite* asteroidSprite;

	void init();
	void update(float xOffset, float yOffset);
	void draw();
};