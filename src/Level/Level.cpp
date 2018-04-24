#include "Level.h"

void Level::init(Screen screen, int width, int height) {
	this->screen = screen;
	this->width = width;
	this->height = height;
}

void Level::generateLevel() {
	for (int i = 0; i < 20; i++) {
		spawnAsteroid();
	}

	player = new Player();
	player->setSize(50);
	player->setPosition(100, 100);
	screen.addEntity(player);
}

void Level::spawnAsteroid() {
	
	bool freeSpace = false;
	
	float x, y;
	float rot = rand() % 360;
	float size = (rand() % 100) + 60;
	float xSpeed = (rand() % 3) - 1;
	float ySpeed = (rand() % 3) - 1;

	while (!freeSpace) {
		if (screen.getEntityListSize() == 0) freeSpace = true;

		x = rand() % width;
		y = rand() % height;
		bool hit = false;

		for (int i = 0; i < screen.getEntityListSize(); i++) {

			float xDist = x - screen.getEntityAt(i)->getXa();
			float yDist = y - screen.getEntityAt(i)->getYa();
			float distance = sqrtf((xDist * xDist) + (yDist * yDist));
			float radiusTotal = (size + screen.getEntityAt(i)->getWidth()) / 2;

			if (radiusTotal > distance) hit = true;
		}

		if (hit == false) freeSpace = true;
	}

	Asteroid* temp = new Asteroid(x, y, size, size);
	temp->init();
	temp->asteroidSprite->setSize(size, size);
	temp->setRotation(rot);
	temp->setVelocity(xSpeed, ySpeed);
	temp->setLevel(width, height);
	screen.addEntity(temp);
}

void Level::update() {
	collision();

	if (player->keys->SPACE) {
		Projectile* p = new Projectile(player->getXa(), player->getYa(), player->getRotation());
		screen.addProjectile(p);
	}
}

void Level::collision() {
	std::vector<Entity*>* entityList = screen.getEntityList();
	for (int i = 0; i < entityList->size() - 1; i++) {
		for (int j = i + 1; j < entityList->size(); j++) {
			Entity* entityA = entityList->at(i);
			Entity* entityB = entityList->at(j);

			if (!entityA->isCollidable()) continue;
			if (!entityB->isCollidable()) continue;

			float xDist = entityA->getXa() - entityB->getXa();
			float yDist = entityA->getYa() - entityB->getYa();

			float distance = sqrtf((xDist * xDist) + (yDist * yDist));

			if (distance < (entityA->getWidth() / 2) + (entityB->getWidth() / 2)) {
				calcCollision(entityA, entityB);
			}
		}
	}
}

void Level::calcCollision(Entity* e1, Entity* e2) {

	float xVel1 = (e1->getVelX() * (e1->getMass() - e2->getMass()) + (2 * e2->getMass() * e2->getVelX())) / (e1->getMass() + e2->getMass());
	float yVel1 = (e1->getVelY() * (e1->getMass() - e2->getMass()) + (2 * e2->getMass() * e2->getVelY())) / (e1->getMass() + e2->getMass());

	float xVel2 = (e2->getVelX() * (e2->getMass() - e1->getMass()) + (2 * e1->getMass() * e1->getVelX())) / (e1->getMass() + e2->getMass());
	float yVel2 = (e2->getVelY() * (e2->getMass() - e1->getMass()) + (2 * e1->getMass() * e1->getVelY())) / (e1->getMass() + e2->getMass());
	
	e1->setVelocity(xVel1, yVel1);
	e2->setVelocity(xVel2, yVel2);

	e1->move();
	e2->move();
}
