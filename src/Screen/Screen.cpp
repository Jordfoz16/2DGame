#include "Screen.h"

void Screen::init(int levelWidth, int levelHeight){
	this->levelWidth = levelWidth;
	this->levelHeight = levelHeight;
	
	camera = new Camera;
	camera->setLevel(levelWidth, levelHeight);
	camera->setFriction(0.9);
	camera->setWrapping(false);
}

void Screen::update() {

	camera->update();

	for (int i = 0; i < entityList->size(); i++) {
		if (entityList->at(i)->toRemove()) {
			delete entityList->at(i);
			entityList->erase(entityList->begin() + i);
		}
		if (!entityList->size()) return;
		entityList->at(i)->update(camera->getXOffset(), camera->getYOffset());
	}
}

void Screen::draw() {
	drawSize = 0;

	ofSetColor(0);
	ofDrawRectangle(0 - camera->getXOffset(), 0 - camera->getYOffset(), levelWidth, levelHeight);

	for (int i = 0; i < entityList->size(); i++) {
		Entity* e = entityList->at(i);

		if (e->getXr() + e->getWidth() >= 0 && e->getXr() <= ofGetWindowWidth() + 50) {
			if (e->getYr() + e->getHeight() >= 0 && e->getYr() <= ofGetWindowHeight() + 50) {
				entityList->at(i)->draw();
				drawSize++;
			}
		}
	}
}

void Screen::addEntity(Entity* e) {
	entityList->push_back(e);
}

std::vector<Entity*>* Screen::getList() {
	return entityList;
}

Entity* Screen::getEntityAt(int index) {
	return entityList->at(index);
}

int Screen::getEntityListSize() {
	return entityList->size();
}

int Screen::getEntityDrawSize() {
	return drawSize;
}