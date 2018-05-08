#pragma once

#include "ofMain.h"

class Button
{
private:

	ofTrueTypeFont buttonFont;

	std::string text;
	int x, y;
	int width, height;
	bool rollover, pressed;

public:

	Button();
	Button(std::string text, int x, int y);
	
	void draw();
	void update(int mouseX, int mouseY, int mouseB);
	void reset();

	bool getPressed();
};

