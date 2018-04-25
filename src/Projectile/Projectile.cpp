#include "Projectile.h"

Projectile::Projectile(float xa, float ya, float rot)
{
	this->xa = xa;
	this->ya = ya;
	this->rot = (PI / 180) * rot;

	length = 50;

	lifeTime = lifeTime * 60;
	setSpeed(speed, rot);
}

void Projectile::update(float xOffset, float yOffset) {
	xr = xa;
	yr = ya;

	counter++;
	if (counter > lifeTime) {
		remove();
		counter = 0;
	}
	move();
}

void Projectile::move() {
	xa += velX;
	ya += velY;
}

void Projectile::draw() {
	ofSetColor(255, 0, 0);

	float xa2 = (cosf(rot) * length) + xa;
	float ya2 = (sin(rot) * length) + ya;

	ofSetLineWidth(5);
	ofDrawLine(xa, ya, xa2, ya2);
}

float Projectile::getLength() {
	return length;
}