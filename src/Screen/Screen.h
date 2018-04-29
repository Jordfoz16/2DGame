#pragma once
#include <vector>

#include "../Entity/Camera/Camera.h"
#include "../Entity/Entity.h"
#include "../Projectile/Projectile.h"

class Screen{
private:

	int levelWidth, levelHeight;
	int drawSizeEntity = 0;
	int drawSizeProjectile = 0;

public:

	std::vector<Entity*>* entityList = new std::vector<Entity*>;
	std::vector<Projectile*>* projectileList = new std::vector<Projectile*>;

	Camera* camera;

	void init(int levelWidth, int levelHeight);
	void update();
	void draw();

	void addEntity(Entity* e);
	void addProjectile(Projectile* p);

	std::vector<Entity*>* getEntityList();
	std::vector<Projectile*>* getProjectileList();

	Entity* getEntityAt(int index);
	int getEntityListSize();
	int getProjectileListSize();
	int getEntityDrawSize();
	int getProjectileDrawSize();
};