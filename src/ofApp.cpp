#include "ofApp.h"
#include <sstream>

void ofApp::setup() {

	ofSetFrameRate(60);
}

void ofApp::update(){

	gui.update();

	//Checks if the game has been setup for the first time
	if (gameModeSetup == false && gui.mode == game) {
		screen.init(LEVEL_WIDTH, LEVEL_HEIGHT);
		level.init(screen, LEVEL_WIDTH, LEVEL_HEIGHT);
		level.player->init(&keyboard);
		gui.init(level);
		gameModeSetup = true;
	}

	//Resets the game to first time start up
	if (gui.mode == finished) {
		gameModeSetup = false;
	}

	//Starts the FPS counter and starts the update cycle
	if (gui.mode == game) {
		delta = ofGetElapsedTimef();
		timer += delta;
		ofResetElapsedTimeCounter();

		keyboard.update();
		screen.update();
		level.update();

		//Updates the frame counter every second
		if (timer >= 1) {
			//Setting the title with frame counter
			ss.str("");
			ss << "2DGame | FPS: " << frames;
			ofSetWindowTitle(ss.str());

			//Printing infomation to console
			ss.str("");
			ss << "Total Entities: " << screen.getEntityListSize();
			ss << ", Drawing: " << screen.getEntityDrawSize();
			ss << std::endl;
			ss << "Total Projectiles: " << screen.getProjectileListSize();
			ss << ", Drawing: " << screen.getProjectileDrawSize();
			std::cout << ss.str() << std::endl;

			timer--;
			frames = 0;
		}
	}
}

void ofApp::draw(){
	//Draws the screen and adds a background 
	if (gui.mode == game) {
		ofBackground(255, 0, 238);
		screen.draw();
		frames++;
	}
	
	//Drawns the GUI
	gui.draw();
}

void ofApp::keyPressed(int key){
	keyboard.keyPressed(key);
}

void ofApp::keyReleased(int key){
	keyboard.keyReleased(key);
}

void ofApp::mouseMoved(int x, int y ){
	gui.mouseUpdate(x, y, -1);
}

void ofApp::mouseDragged(int x, int y, int button){}

void ofApp::mousePressed(int x, int y, int button){
	gui.mouseUpdate(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}

