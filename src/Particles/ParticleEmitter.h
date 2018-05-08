#pragma once

#include <vector>

#include "Particles.h"

class ParticleEmitter
{
private:

	float xa, ya;
	float xr, yr;

	std::vector<Particles*>* particlesList = new std::vector<Particles*>;

public:

	ParticleEmitter(float xa, float ya, int amount);
	ParticleEmitter(ofColor colour, float xa, float ya, int amount);

	void update(float xOffset, float yOffset);
	void draw();

	void addParticle(Particles* p);

	int getSize();
};

