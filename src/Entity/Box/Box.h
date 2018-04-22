#pragma once

#include "../Entity.h"
#include "../../Sprite/Sprite.h"

class Box : public Entity
{
public:

	Box() : Entity() {};
	Box(float posX, float posY) : Entity(posX, posY) {};
	Box(float posX, float posY, float width, float height) : Entity(posX, posY, width, height) {};
	Box(float posX, float posY, float width, float height, float rot) : Entity(posX, posY, width, height, rot) {};

	void update(float xOffset, float yOffset);
	void draw();
};

