#pragma once

#include "../../Input/Keyboard.h"
#include "../../Entity/Entity.h"

class Camera : public Entity
{
private:

	Keyboard* keys;

	float camSpeed = 10;

public:

	Camera();

	void init(Keyboard &keys);
	void update();
	void move();

	float getXOffset();
	float getYOffset();
};