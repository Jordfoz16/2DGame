#include "Player.h"

void Player::init() {

}

void Player::update(float xOffset, float yOffset) {
	xr = xa;
	yr = ya;

}

void Player::draw() {
	ofSetColor(255, 255, 0);
	ofDrawRectangle(xa, ya, width, height);
}