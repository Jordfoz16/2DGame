#pragma once

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_SPACE 32


class Keyboard {
private:

	bool activeKeys[255];
public:
	bool UP, DOWN, LEFT, RIGHT;
	bool SPACE;

	void update();
	void keyPressed(int key);
	void keyReleased(int key);
};