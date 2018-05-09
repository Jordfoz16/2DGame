#pragma once
#include <vector>

#include "../Entity/Camera/Camera.h"
#include "../Entity/Entity.h"
#include "../Player/Player.h"
#include "../Projectile/Projectile.h"
#include "../Particles/ParticleEmitter.h"
#include "../Level/Background/Background.h"

class Screen{
private:

	int levelWidth, levelHeight;
	int drawSizeEntity = 0;
	int drawSizeProjectile = 0;

	bool firstLoad = true;

public:

	Player* player;
	Camera* camera;
	Background* background;

	std::vector<Entity*>* entityList = new std::vector<Entity*>;
	std::vector<Projectile*>* projectileList = new std::vector<Projectile*>;
	std::vector<ParticleEmitter*>* emitterList = new std::vector<ParticleEmitter*>;

	void init(int levelWidth, int levelHeight);
	void update();
	void draw();

	void addPlayer(Player* p);
	void addEntity(Entity* e);
	void addProjectile(Projectile* p);
	void addEmitter(ParticleEmitter* e);

	std::vector<Entity*>* getEntityList();
	std::vector<Projectile*>* getProjectileList();

	Entity* getEntityAt(int index);
	int getEntityListSize();
	int getProjectileListSize();
	int getEntityDrawSize();
	int getProjectileDrawSize();
};