#pragma once
#include <random>
#include <math.h>

#include "../Screen/Screen.h"
#include "../Entity/Asteroid/Asteroid.h"
#include "../Entity/Player/Player.h"
#include "../Projectile/Projectile.h"
#include "../Particles/ParticleEmitter.h"


class Level {
private:
	Screen* screen;
	int width, height;
	int coolDown = 0;
	
	void calcCollision(Entity* e1, Entity* e2);

public:

	int score = 0, killCount = 0;
	bool endGame = false;

	Player* player;

	void init(Screen &screen, int width, int height);
	void generateLevel();
	void spawnAsteroid();
	void update();
	void collision();
};