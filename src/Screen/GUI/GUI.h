#pragma once

#include <sstream>

#include "ofMain.h"
#include "../Level/Level.h"
#include "Button.h"

enum gameMode
{
	start, game, finished
};

class GUI
{
private:

	ofTrueTypeFont titleFont, bodyFont;
	Button startButton, infoButton, restartButton;

	Level* level;

	bool ended = false;

public:

	gameMode mode;

	GUI();

	void init(Level &level);
	void update();
	void mouseUpdate(int mouseX, int mouseY, int mouseB);
	void draw();

	void startMenu();
	void gameInterface();
	void endMenu();
};