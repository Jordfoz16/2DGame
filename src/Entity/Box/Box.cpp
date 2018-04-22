#include "Box.h"

void Box::update(float xOffset, float yOffset) {
	xr = xa - xOffset;
	yr = ya - yOffset;

	move();
}

void Box::draw() {
	
	ofSetColor(colour);
	ofPushMatrix();
	ofTranslate(xr, yr, 0);
	ofRotateZ(rot);
	ofDrawRectangle(0 - width / 2, 0 - height / 2, width, height);
	ofPopMatrix();
}