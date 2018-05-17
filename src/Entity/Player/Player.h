#pragma once

#include "../Entity/Entity.h"
#include "../../Sprite/Sprite.h"
#include "../Input/Keyboard.h"

class Player : public Entity 
{
private:
	
	float thruster = 0;
	float thrusterSpeed = 0.1;
	float rotationSpeed = 5;
	
	float coolDown = 0.3;

public:

	Player() : Entity() {};
	Player(float posX, float posY) : Entity(posX, posY) {};
	Player(float posX, float posY, float width, float height) : Entity(posX, posY, width, height) {};
	Player(float posX, float posY, float width, float height, float rot) : Entity(posX, posY, width, height, rot) {};

	Sprite* playerSprite, *thrustSprite, *idleSprite;
	Keyboard* keys;

	int invincibleCounter = 0;

	void init(Keyboard* keys);
	void update(float xOffset, float yOffset);
	void draw();

	float getCoolDown();
};