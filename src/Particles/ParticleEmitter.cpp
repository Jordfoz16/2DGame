#include "ParticleEmitter.h"



ParticleEmitter::ParticleEmitter(float xa, float ya, int amount){
	this->xa = xa;
	this->ya = ya;

	for (int i = 0; i < amount; i++) {
		Particles* p = new Particles();
		addParticle(p);
	}
}


ParticleEmitter::~ParticleEmitter(){
	
}

void ParticleEmitter::update(float xOffset, float yOffset) {
	xr = xa - xOffset;
	yr = ya - yOffset;

	for (int i = 0; i < particlesList->size(); i++) {
		if (particlesList->at(i)->isRemoved()) {
			delete particlesList->at(i);
			particlesList->erase(particlesList->begin() + i);
			continue;
		}
		if (!particlesList->size()) return;
		particlesList->at(i)->update();
	}
}

void ParticleEmitter::draw() {
	for (int i = 0; i < particlesList->size(); i++) {
		particlesList->at(i)->draw(xr, yr);
	}
}

void ParticleEmitter::addParticle(Particles* p) {
	particlesList->push_back(p);
}

int  ParticleEmitter::getSize() {
	return particlesList->size();
}
