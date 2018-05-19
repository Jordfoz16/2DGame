#pragma once

#include "../Entity/Entity.h"

class Projectile : public Entity
{
private:
	
	float length;

	float speed = 9;
	float lifeTime = 1;
	int counter = 0;

public:
	Projectile(float xa, float ya, float rot);

	void update(float xOffset, float yOffset);
	void draw();
	void move();

	float getLength();

	void remove();
};

