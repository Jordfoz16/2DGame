#include "Camera.h"

Camera::Camera() : Entity(){

}

void Camera::init(Keyboard &keys) {
	this->keys = &keys;
	friction = 0.985;
}

void Camera::update() {

	float camX = 0, camY = 0;

	if (keys->UP) camY = -camSpeed;
	if (keys->DOWN) camY = camSpeed;
	if (keys->LEFT) camX = -camSpeed;
	if (keys->RIGHT) camX = camSpeed;
	
	if (camX == 0 && camY == 0) {
		camX = velX;
		camY = velY;
	}
	else if (camX == 0) {
		camX = velX;
	}
	else if (camY == 0) {
		camY = velY;
	}

	setVelocity(camX, camY);

	move();
}

void Camera::move() {
	velX *= friction;
	velY *= friction;

	if (velX > maxSpeed) velX = maxSpeed;
	else if (velX < -maxSpeed) velX = -maxSpeed;
	if (velY > maxSpeed) velY = maxSpeed;
	else if (velY < -maxSpeed) velY = -maxSpeed;

	xa += velX;
	ya += velY;
}

float Camera::getXOffset() {
	return xa;
}

float Camera::getYOffset() {
	return ya;
}