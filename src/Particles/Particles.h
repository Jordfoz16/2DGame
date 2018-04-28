#pragma once

#include <random>

#include "ofMain.h"

class Particles
{
private:

	float xPos, yPos;
	float velX, velY;
	float size;
	bool removed = false;
	int lifeTime, lifeCounter;

public:
	Particles();
	~Particles();

	void update();
	void draw(float xr, float yr);
	void move();
	void remove();

	bool isRemoved();
	float getX();
	float getY();
};



