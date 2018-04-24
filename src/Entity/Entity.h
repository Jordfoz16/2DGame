#pragma once
#include <iostream>
#include <math.h>

#include "../ofMain.h"

class Entity
{
protected:
	//xa and ya are the absolute position of the entity (Center of Object)
	float xa, ya;
	//xr and yr are the relative position to the camera of the entity
	float xr, yr;
	//Rotation value of the entity
	float rot;
	//Width and Height of the entity
	float width, height;
	//Mass of the entity
	float mass;
	//Velocity of the entity
	float velX, velY;
	float friction;
	float maxSpeed;
	//Level width and height
	int levelWidth, levelHeight;
	//Wrap the entity at bounds
	bool wrapping;
	//Stores whether the entity needs to be removed
	bool removed = false;
	bool collidable = false;
	//Stores the colour of the entity
	ofColor colour = ofColor(255, 255, 255);

public:

	Entity();
	Entity(float posX, float posY);
	Entity(float posX, float posY, float width, float height);
	Entity(float posX, float posY, float width, float height, float rot);
	~Entity();

	virtual void init();
	virtual void update(float xOffset, float yOffset);
	virtual void draw();
	virtual void move();
	void remove();

	void setPosition(float xa, float ya);
	void setVelocity(float velX, float velY);
	void setSpeed(float speed);
	void setSpeed(float speed, float angle);
	void setSize(float size);
	void setMass(float mass);
	void setFriction(float friction);
	void setRotation(float rot);
	void setColour(ofColor colour);
	void setLevel(int width, int height);
	void setWrapping(bool wrapping);

	bool toRemove();
	bool isCollidable();
	float getXa();
	float getYa();
	float getXr();
	float getYr();
	float getWidth();
	float getHeight();
	float getVelX();
	float getVelY();
	float getMass();
	float getSpeed();
	float getRotation();
};