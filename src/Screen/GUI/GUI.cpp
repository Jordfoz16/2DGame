#include "GUI.h"

GUI::GUI(){
	mode = start;
	titleFont.loadFont("fonts/mainfont.ttf", 32);
	bodyFont.loadFont("fonts/mainfont.ttf", 16);

	startButton = Button("Start", 200, 400);
	infoButton = Button("Info", 400, 400);
	restartButton = Button("Restart", 300, 400);
}

void GUI::init(Level &level) {
	this->level = &level;
}

void GUI::update() {
	if (mode == game) {
		if (level->endGame) {
			mode = finished;
		}
	}

	if (mode == finished) {
		if (restartButton.getPressed()) {
			restartButton.reset();
			mode = start;
			ended = false;
		}
	}

	if (startButton.getPressed()) {
		mode = game;
		startButton.reset();
	}
}

void GUI::mouseUpdate(int mouseX, int mouseY, int mouseB) {
	
	switch (mode)
	{
	case start:
		startButton.update(mouseX, mouseY, mouseB);
		infoButton.update(mouseX, mouseY, mouseB);
		break;
	case game:
		break;
	case finished:
		restartButton.update(mouseX, mouseY, mouseB);
		break;
	default:
		break;
	}
}

void GUI::draw() {

	switch (mode)
	{
	case start:
		startMenu();
		break;
	case game:
		gameInterface();
		break;
	case finished:
		endMenu();
		break;
	default:
		break;
	}
}

void GUI::startMenu() {
	ofBackground(0);
	titleFont.drawString("Asteroids", (ofGetWindowWidth() / 2) - 130, (ofGetWindowHeight() / 2) - 200);
	
	startButton.draw();
	infoButton.draw();
}

void GUI::gameInterface() {
	ofSetColor(255);

	std::stringstream ss;
	
	ss << "Score: " << level->score;

	bodyFont.drawString(ss.str(), 10, 25);

	ss.str("");
	ss << "Kill Count: " << level->killCount;

	bodyFont.drawString(ss.str(), 10, 55);
}

void GUI::endMenu() {

	if (ended == false) {
		level->destroyLevel();
		ended = true;
	}
	
	std::stringstream ss;

	ss << "Game Over";

	titleFont.drawString(ss.str(), (ofGetWindowWidth() / 2) - 130, (ofGetWindowHeight() / 2) - 200);

	ss.str("");
	ss << "Final Score: " << level->score << std::endl;
	ss << "Kill Count: " << level->killCount;

	bodyFont.drawString(ss.str(), (ofGetWindowWidth() / 2) - 130, (ofGetWindowHeight() / 2));

	restartButton.draw();
}