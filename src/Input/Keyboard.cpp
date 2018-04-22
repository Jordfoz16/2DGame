#include "Keyboard.h"

void Keyboard::update() {
	UP = activeKeys[KEY_W];
	DOWN = activeKeys[KEY_S];
	LEFT = activeKeys[KEY_A];
	RIGHT = activeKeys[KEY_D];
	SPACE = activeKeys[KEY_SPACE];
}

void Keyboard::keyPressed(int key) {
	activeKeys[key] = true;
}

void Keyboard::keyReleased(int key) {
	activeKeys[key] = false;
}