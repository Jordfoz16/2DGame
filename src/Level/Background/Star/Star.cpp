#include "Star.h"

Star::Star(int xa, int ya){

	this->xa = xa;
	this->ya = ya;

	starSprite = new Sprite("sprites/Star.png");
	starSprite->setScale(0.8);
}

void Star::draw() {
	starSprite->draw(xr, yr);
}

void Star::update(int xOffset, int yOffset) {
	xr = xa - xOffset;
	yr = ya - yOffset;
}