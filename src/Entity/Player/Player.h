#pragma once

#include "../Entity/Entity.h"
#include "../../Sprite/Sprite.h"

class Player : public Entity 
{
private:
	
public:

	Player() : Entity() {};
	Player(float posX, float posY) : Entity(posX, posY) {};
	Player(float posX, float posY, float width, float height) : Entity(posX, posY, width, height) {};
	Player(float posX, float posY, float width, float height, float rot) : Entity(posX, posY, width, height, rot) {};

	Sprite* playerSprite;

	void init();
	void update(float xOffset, float yOffset);
	void draw();
};