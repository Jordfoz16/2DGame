#include "Sprite.h"

Sprite::Sprite(){
}

Sprite::Sprite(std::string path) {
	loadSprite(path);
}

Sprite::Sprite(std::string path, float size) {
	loadSprite(path);
	setSize(size, size);
}

void Sprite::loadSprite(std::string path) {
	sprite.load(path);
	width = sprite.getWidth();
	height = sprite.getHeight();

	std::cout << "Sprite Loaded" << std::endl;
}

void Sprite::draw(float xPos, float yPos) {
	sprite.draw(xPos, yPos, width, height);
}

void Sprite::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}

void Sprite::setScale(float scale) {
	width = width * scale;
	height = height * scale;
}