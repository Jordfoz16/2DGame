#include "Button.h"

Button::Button() {

}

Button::Button(std::string text, int x, int y){

	this->text = text;
	this->x = x;
	this->y = y;

	width = 150;
	height = 75;

	rollover = false;
	pressed = false;

	buttonFont.loadFont("fonts/mainFont.ttf", 20);
}

void Button::draw() {
	
	if (pressed) {
		ofSetColor(150, 50, 50);
	}else if (rollover){
		ofSetColor(50, 150, 50);
	}else {
		ofSetColor(100, 100, 100);
	}
	
	ofDrawRectangle(x, y, width, height);

	ofSetColor(255);
	buttonFont.drawString(text, x + 38, y + 45);
}

void Button::update(int mouseX, int mouseY, int mouseB) {
	if (mouseX > x && mouseX < x + width) {
		if (mouseY > y && mouseY < y + height) {
			rollover = true;
			if (mouseB == 0) {
				pressed = true;
			}
		}else {
			rollover = false;
		}
	}else {
		rollover = false;
	}
}

void Button::reset() {
	pressed = false;
}

bool Button::getPressed() {
	return pressed;
}