#include "ofApp.h"
#include <sstream>

void ofApp::setup() {

	//Hello World

	ofSetFrameRate(60);

	screen.init(LEVEL_WIDTH, LEVEL_HEIGHT);
	screen.camera->init(keyboard);
	level.init(screen, LEVEL_WIDTH, LEVEL_HEIGHT);
	level.generateLevel();
}

void ofApp::update(){

	delta = ofGetElapsedTimef();
	timer += delta;
	ofResetElapsedTimeCounter();

	keyboard.update();
	level.update();
	screen.update();
	

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
		std::cout << ss.str() << std::endl;

		timer--;
		frames = 0;
	}
}

void ofApp::draw(){
	ofBackground(255, 0, 238);
	screen.draw();

	frames++;
}

void ofApp::keyPressed(int key){
	keyboard.keyPressed(key);
}

void ofApp::keyReleased(int key){
	keyboard.keyReleased(key);
}

void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}

