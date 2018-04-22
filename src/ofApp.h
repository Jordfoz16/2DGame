#pragma once
#include <iostream>

#include "ofMain.h"
#include "ofUtils.h"
#include "Input/Keyboard.h"
#include "Screen/Screen.h"
#include "Level/Level.h"
/*
	TODO List:
		-Make Camera follow player not Player followers camera
		-Player controls
		-Player rotation and physics
*/

class ofApp : public ofBaseApp{
private:

	std::stringstream ss;

	int LEVEL_WIDTH = 1200, LEVEL_HEIGHT = LEVEL_WIDTH;

	float delta = 0.0f, timer = 0.0f;
	int frames = 0;
	
public:

	Keyboard keyboard;
	Screen screen;
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

