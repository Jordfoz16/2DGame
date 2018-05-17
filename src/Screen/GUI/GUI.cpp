#include "GUI.h"

GUI::GUI(){
	//Starting mode
	mode = start;
	//Title and Body font
	titleFont.loadFont("fonts/mainfont.ttf", 32);
	bodyFont.loadFont("fonts/mainfont.ttf", 16);

	//GUI buttons
	startButton = Button("Start", 200, 400);
	infoButton = Button("Info", 400, 400);
	restartButton = Button("Restart", 300, 400);
}

void GUI::init(Level &level) {
	this->level = &level;
}

void GUI::update() {

	//Changes game mode to the end
	if (mode == game) {
		if (level->endGame) {
			mode = finished;
		}
	}

	//Resets the game mode to start
	if (mode == finished) {
		if (restartButton.getPressed()) {
			restartButton.reset();
			mode = start;
			ended = false;
		}
	}

	//Sets the game mode to game to start the game
	if (startButton.getPressed()) {
		mode = game;
		startButton.reset();
		showInfo = false;
	}

	//Shows the control infomation
	if (infoButton.getPressed()) {
		if (showInfo == true) showInfo = false;
		else showInfo = true;
		
		infoButton.reset();
	}
}

void GUI::mouseUpdate(int mouseX, int mouseY, int mouseB) {
	
	//Updates mouse X and Y for each button

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

	//Draws each GUI depending on game mode

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

	//GUI for the start menu

	ofBackground(0);
	titleFont.drawString("Asteroids", (ofGetWindowWidth() / 2) - 130, (ofGetWindowHeight() / 2) - 200);
	
	if (showInfo) {
		ss.str("");
		ss << "Controls:" << std::endl;
		ss << "W = Thrust" << std::endl;
		ss << "A = Turn Left" << std::endl;
		ss << "D = Turn Right" << std::endl;
		ss << "Space = Fire Projectile" << std::endl;
		bodyFont.drawString(ss.str(), 200, 160);
		ss.str("");
		ss << "It get points shot the asteroids" << std::endl;
		ss << "and stay alive for as long as you can" << std::endl;
		bodyFont.drawString(ss.str(), 180, 320);
		
	}
	
	startButton.draw();
	infoButton.draw();
}

void GUI::gameInterface() {

	//GUI for the game interface

	ofSetColor(255);
	
	ss.str("");
	ss << "Score: " << level->score;

	bodyFont.drawString(ss.str(), 10, 25);

	ss.str("");
	ss << "Kill Count: " << level->killCount;

	bodyFont.drawString(ss.str(), 10, 55);

	int startTimer = 5 - (level->player->invincibleCounter/60);

	if (startTimer == 0) return;

	ss.str("");
	ss << "Starting in " << startTimer;

	bodyFont.drawString(ss.str(), (ofGetWindowWidth()/2) - 75, (ofGetWindowHeight()/2) - 100);
}

void GUI::endMenu() {

	//GUI of the end menu

	if (ended == false) {
		//Deletes everything from the level
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