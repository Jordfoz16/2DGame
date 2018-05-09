#include "Screen.h"

void Screen::init(int levelWidth, int levelHeight) {
	this->levelWidth = levelWidth;
	this->levelHeight = levelHeight;

	camera = new Camera;
	camera->setLevel(levelWidth, levelHeight);
	camera->setFriction(0.9);
	camera->setWrapping(false);

	if (firstLoad) {
		background = new Background(levelWidth, levelHeight);
	}
	
	firstLoad = false;
}

void Screen::update() {

	camera->update();
	
	if (player->toRemove()) {
		delete player;
	}
	else {
		player->update(camera->getXOffset(), camera->getYOffset());
	}
	
	for (int i = 0; i < projectileList->size(); i++) {
		if (projectileList->at(i)->toRemove()) {
			delete projectileList->at(i);
			projectileList->erase(projectileList->begin() + i);
			continue;
		}

		if (!projectileList->size()) return;
		projectileList->at(i)->update(camera->getXOffset(), camera->getYOffset());
	}

	for (int i = 0; i < entityList->size(); i++) {
		if (entityList->at(i)->toRemove()) {
			delete entityList->at(i);
			entityList->erase(entityList->begin() + i);
			continue;
		}
		if (!entityList->size()) return;
		entityList->at(i)->update(camera->getXOffset(), camera->getYOffset());
	}

	for (int i = 0; i < emitterList->size(); i++) {
		if (emitterList->at(i)->getSize() == 0) {
			delete emitterList->at(i);
			emitterList->erase(emitterList->begin() + i);
			continue;
		}

		if (!emitterList->size()) return;
		emitterList->at(i)->update(camera->getXOffset(), camera->getYOffset());
	}
}

void Screen::draw() {
	drawSizeEntity = 0;
	drawSizeProjectile = 0;

	ofSetColor(0);
	ofDrawRectangle(0 - camera->getXOffset(), 0 - camera->getYOffset(), levelWidth, levelHeight);

	ofSetColor(255);
	background->draw(camera->getXOffset(), camera->getYOffset());

	for (int i = 0; i < entityList->size(); i++) {
		Entity* e = entityList->at(i);

		if (e->getXr() + e->getWidth() >= 0 && e->getXr() <= ofGetWindowWidth() + 100) {
			if (e->getYr() + e->getHeight() >= 0 && e->getYr() <= ofGetWindowHeight() + 100) {
				entityList->at(i)->draw();
				drawSizeEntity++;
			}
		}
	}

	for (int i = 0; i < projectileList->size(); i++) {
		Projectile* p = projectileList->at(i);

		if (p->getXr() + p->getLength() >= 0 && p->getXr() <= ofGetWindowWidth() + 50) {
			if (p->getYr() + p->getLength() >= 0 && p->getYr() <= ofGetWindowHeight() + 50) {
				projectileList->at(i)->draw();
				drawSizeProjectile++;
			}
		}
	}

	for (int i = 0; i < emitterList->size(); i++) {
		emitterList->at(i)->draw();
	}

	player->draw();
}

void Screen::addPlayer(Player* p) {
	player = p;
}

void Screen::addEntity(Entity* e) {
	entityList->push_back(e);
}

void Screen::addProjectile(Projectile* p) {
	projectileList->push_back(p);
}

void Screen::addEmitter(ParticleEmitter* e) {
	emitterList->push_back(e);
}

std::vector<Entity*>* Screen::getEntityList() {
	return entityList;
}

std::vector<Projectile*>* Screen::getProjectileList() {
	return projectileList;
}


Entity* Screen::getEntityAt(int index) {
	return entityList->at(index);
}

int Screen::getEntityListSize() {
	return entityList->size();
}

int Screen::getProjectileListSize() {
	return projectileList->size();
}

int Screen::getEntityDrawSize() {
	return drawSizeEntity;
}

int Screen::getProjectileDrawSize() {
	return drawSizeProjectile;
}