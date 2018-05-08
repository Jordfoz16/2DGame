#include "Background.h"

Background::Background(int width, int height)
{
	for (int i = 0; i < 500; i++) {
		int randX = rand() % width;
		int randY = rand() % height;
		starList->push_back(new Star(randX, randY));
	}
}

void Background::draw(int xOffset, int yOffset) {

	for (int i = 0; i < starList->size(); i++) {
		Star* star = starList->at(i);

		star->update(xOffset, yOffset);
		
		if (star->xr >= 0 && star->xr <= ofGetWindowWidth() + 20) {
			if (star->yr >= 0 && star->yr <= ofGetWindowHeight() + 20) {
				star->draw();
			}
		}
	}
}