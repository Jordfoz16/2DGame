#pragma once
#include <iostream>

#include "ofMain.h"
#include "ofUtils.h"
#include "Input/Keyboard.h"
#include "Screen/Screen.h"
#include "Screen/GUI/GUI.h"
#include "Level/Level.h"

class ofApp : public ofBaseApp{
private:

	std::stringstream ss;

	bool gameModeSetup = false;

	int LEVEL_WIDTH = 5000, LEVEL_HEIGHT = LEVEL_WIDTH;

	float delta = 0.0f, timer = 0.0f;
	int frames = 0;
	
public:

	Keyboard keyboard;
	Screen screen;
	GUI gui;
	Level level;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
};

