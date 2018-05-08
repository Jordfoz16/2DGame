#pragma once

#include "../Sprite/Sprite.h"

class Star
{
private:
	Sprite * starSprite;

public:

	int xa, ya;
	int xr, yr;

	Star(int xa, int ya);

	void draw();
	void update(int xOffset, int yOffset);
};

