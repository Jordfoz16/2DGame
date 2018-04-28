#include "Particles.h"



Particles::Particles() {
	xPos = 0;
	yPos = 0;
	velX = (float)((rand() % 1000) - 500) / 100;
	velY = (float)((rand() % 1000) - 500) / 100;;
	size = (rand() % 5) + 1;
	lifeTime = (rand() % 20) + 5;
	lifeCounter = 0;
}


Particles::~Particles() {
}

void Particles::update() {
	lifeCounter++;
	if (lifeCounter > lifeTime) remove();

	move();
}

void Particles::draw(float xr, float yr) {
	ofSetColor(195, 195, 195);
	ofDrawRectangle(xr + xPos, yr + yPos, size, size);
}

void Particles::move() {
	xPos += velX;
	yPos += velY;
}

void Particles::remove() {
	removed = true;
}

bool Particles::isRemoved() {
	return removed;
}

float Particles::getX() {
	return xPos;
}

float Particles::getY() {
	return yPos;
}