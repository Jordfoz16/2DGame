#include "Asteroid.h"

void Asteroid::init() {

	std::cout << "Asteroid Created" << std::endl;

	int random = rand() % 2;
	switch (random)
	{
	case 0:
		asteroidSprite = new Sprite("sprites/Asteroid1.png");
		break;
	case 1:
		asteroidSprite = new Sprite("sprites/Asteroid2.png");
		break;
	default:
		break;
	}

	rotationSpeed = ((float)(rand() % 300) - 100) / 100.0f;
	mass = (width * width);
	maxSpeed = 1.5;
	wrapping = false;
	collidable = true;
}

void Asteroid::update(float xOffset, float yOffset) {
	xr = xa - xOffset;
	yr = ya - yOffset;

	if (width < 50) remove();

	setRotation(rot += rotationSpeed);
	move();
}

void Asteroid::draw() {
	ofSetColor(colour);
	ofPushMatrix();
	ofTranslate(xr, yr, 0);
	ofRotateZ(rot);
	asteroidSprite->draw(0 - width/2, 0 - height/2);
	ofPopMatrix();
}

void Asteroid::remove() {
	removed = true;
	asteroidSprite->sprite.clear();
}