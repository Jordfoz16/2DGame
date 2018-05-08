#include "Entity.h"

Entity::Entity() {
	xa = 0, ya = 0;
	width = 10, height = 10;
	mass = 1;
	velX = 0, velY = 0;
	maxSpeed = 5;
	rot = 0;
	friction = 1;
	wrapping = true;
}

Entity::Entity(float posX, float posY) :
	Entity() {

	this->xa = posX;
	this->ya = posY;
}

Entity::Entity(float posX, float posY, float width, float height) :
	Entity() {

	this->xa = posX;
	this->ya = posY;
	this->width = width;
	this->height = height;
}

Entity::Entity(float posX, float posY, float width, float height, float rot) :
	Entity() {

	this->xa = posX;
	this->ya = posY;
	this->width = width;
	this->height = height;
	this->rot = rot;
}

Entity::~Entity() {
	std::cout << "Entity Destroyed" << std::endl;
}

void Entity::init() {

}

void Entity::update(float xOffset, float yOffset) {

}

void Entity::draw() {

}

void Entity::move() {

	if (wrapping) {
		if (xa > levelWidth) {
			xa = 0;
		}
		else if (xa + width < 0) {
			xa = levelWidth;
		}

		if (ya > levelHeight) {
			ya = 0;
		}
		else if (ya + height < 0) {
			ya = levelHeight;
		}
	}
	else {
		if (xa + (width / 2) > levelWidth) {
			velX = abs(velX) * -1;
		}
		else if (xa - (width / 2) < 0) {
			velX = abs(velX);
		}

		if (ya + (height / 2) > levelHeight) {
			velY = abs(velY) * -1;
		}
		else if (ya - (height / 2) < 0) {
			velY = abs(velY);
		}
	}

	velX *= friction;
	velY *= friction;

	if (velX > maxSpeed) velX = maxSpeed;
	else if (velX < -maxSpeed) velX = -maxSpeed;
	if (velY > maxSpeed) velY = maxSpeed;
	else if (velY < -maxSpeed) velY = -maxSpeed;

	xa += velX;
	ya += velY;
}

void Entity::setPosition(float xa, float ya) {
	this->xa = xa;
	this->ya = ya;
}

void Entity::setVelocity(float velX, float velY) {
	this->velX = velX;
	this->velY = velY;
}

void Entity::setSpeed(float speed) {
	float curAngle = atan2f(velY, velX);;
	curAngle = (180 / PI) * curAngle;
	setSpeed(speed, curAngle);
}

void Entity::setSpeed(float speed, float angle) {
	angle = (PI / 180) * angle;
	this->velX = cosf(angle) * speed * friction;
	this->velY = sinf(angle) * speed * friction;
}

void Entity::setLevel(int width, int height) {
	levelWidth = width;
	levelHeight = height;
}

float Entity::getSpeed() {
	float currentSpeed = (velX * velX) + (velY * velY);
	currentSpeed = sqrtf(currentSpeed);
	return currentSpeed;
}

void Entity::setSize(float size) {
	width = size;
	height = size;
}
void Entity::setMass(float mass) { this->mass = mass; }
void Entity::setFriction(float friction) { this->friction = friction; }
void Entity::setRotation(float rot) { this->rot = rot; }
void Entity::setColour(ofColor colour) { this->colour = colour; }
void Entity::setWrapping(bool wrapping) { this->wrapping = wrapping; }
void Entity::remove() { removed = true; }
bool Entity::toRemove() { return removed; }
bool Entity::isCollidable() { return collidable; }
float Entity::getXa() { return xa; }
float Entity::getYa() { return ya; }
float Entity::getXr() { return xr; }
float Entity::getYr() { return yr; }
float Entity::getWidth() { return width; }
float Entity::getHeight() { return height; }
float Entity::getVelX() { return velX; }
float Entity::getVelY() { return velY; }
float Entity::getMass() { return mass; }
float Entity::getRotation() { return rot; }