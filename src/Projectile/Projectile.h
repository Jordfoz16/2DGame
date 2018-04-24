#pragma once

#include "../Entity/Entity.h"

class Projectile : public Entity
{
private:
	
	float length;

	float speed = 10;

public:
	Projectile(float xa, float ya, float rot);

	void update(float xOffset, float yOffset);
	void draw();
	void move();

	float getLength();
};
