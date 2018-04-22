#pragma once
#include <vector>

#include "../Entity/Camera/Camera.h"
#include "../Entity/Entity.h"

class Screen{
private:

	int levelWidth, levelHeight;
	int drawSize = 0;

public:

	std::vector<Entity*>* entityList = new std::vector<Entity*>;

	Camera* camera;

	void init(int levelWidth, int levelHeight);
	void update();
	void draw();
	void addEntity(Entity* e);

	std::vector<Entity*>* getList();
	Entity* getEntityAt(int index);
	int getEntityListSize();
	int getEntityDrawSize();
};