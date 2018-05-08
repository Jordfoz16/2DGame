#pragma once

#include <vector>
#include <random>

#include "ofMain.h"
#include "Star\Star.h"

class Background
{
private:

	std::vector<Star*>* starList = new std::vector<Star*>;

public:
	Background(int width, int height);

	void draw(int xOffset, int yOffset);
};

