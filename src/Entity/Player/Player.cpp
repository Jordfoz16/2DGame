#include "Player.h"

void Player::init(Keyboard* keys) {
	
	std::cout << "Player Created" << std::endl;
	this->keys = keys;

	playerSprite = new Sprite("sprites/rocket.png");
	playerSprite->setScale(0.2);
	friction = 0.98;
	maxSpeed = 5;
	coolDown = coolDown * 0;
	collidable = true;
}

void Player::update(float xOffset, float yOffset) {
	
	xr = xa - xOffset;
	yr = ya - yOffset;

	if (keys->UP) {
		thruster += thrusterSpeed;
		if (thruster > maxSpeed) thruster = maxSpeed;
	}
	else {
		if (thruster > 0) {
			thruster *= friction;
		}
		else {
			thruster = 0;
		}
	}
	
	if (keys->LEFT) rot += -1 * rotationSpeed;
	if (keys->RIGHT) rot += 1 * rotationSpeed;
	
	setSpeed(thruster, rot);

	if (toRemove()) return;
	move();
}

void Player::draw() {
	if (toRemove()) return;
	ofSetColor(colour);
	ofPushMatrix();
	ofTranslate(xr, yr, 0);
	ofRotateZ(rot);
	playerSprite->draw((0 - width / 2), (0 - height / 2) + 10);
	ofPopMatrix();
}

float Player::getCoolDown() {
	return coolDown;
}