#pragma once
#include <string>
#include <iostream>

#include "../ofMain.h"

class Sprite {
private:

public:

	ofImage sprite;
	int width, height;

	bool remove = false;

	Sprite();
	Sprite(std::string path);
	Sprite(std::string path, float size);

	void loadSprite(std::string path);
	void draw(float xPos, float yPos);
	void setSize(int width, int height);
	void setScale(float scale);
};

