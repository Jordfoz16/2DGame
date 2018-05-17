#include "Player.h"

void Player::init(Keyboard* keys) {
	
	std::cout << "Player Created" << std::endl;
	this->keys = keys;

	//Two sprites for engines on and off
	idleSprite = new Sprite("sprites/rocket_no.png");
	thrustSprite = new Sprite("sprites/rocket.png");
	playerSprite = idleSprite;
	idleSprite->setScale(0.3);
	thrustSprite->setScale(0.3);
	friction = 0.98;
	maxSpeed = 5;
	coolDown = coolDown * 60;
	collidable = false;
}

void Player::update(float xOffset, float yOffset) {
	
	//Stops the player being killed for 5 seconds
	if (invincibleCounter < 300) {
		invincibleCounter++;
	}
	else {
		collidable = true;
	}

	xr = xa - xOffset;
	yr = ya - yOffset;

	if (keys->UP) {
		//Increase the amount of thrust
		thruster += thrusterSpeed;
		//Prevents thrust going higher than max speed
		if (thruster > maxSpeed) thruster = maxSpeed;
		//Changes to thrust sprite
		playerSprite = thrustSprite;
	}
	else {
		//Changes to idle sprite
		playerSprite = idleSprite;
		if (thruster > 0) {
			thruster *= friction;
		}
		else {
			thruster = 0;
		}
	}
	
	//Rotation of ship
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
	//Move the player to relative position
	ofTranslate(xr, yr, 0);
	//Rotates the player
	ofRotateZ(rot);
	playerSprite->draw((0 - width / 2), (0 - height / 2) + 10);
	ofPopMatrix();
}

float Player::getCoolDown() {
	return coolDown;
}