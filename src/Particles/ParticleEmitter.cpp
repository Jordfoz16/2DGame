#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter(float xa, float ya, int amount){
	this->xa = xa;
	this->ya = ya;

	for (int i = 0; i < amount; i++) {
		Particles* p = new Particles(ofColor(195, 195, 195));
		addParticle(p);
	}
}

ParticleEmitter::ParticleEmitter(ofColor colour, float xa, float ya, int amount) {
	this->xa = xa;
	this->ya = ya;

	for (int i = 0; i < amount; i++) {
		Particles* p = new Particles(colour);
		addParticle(p);
	}
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
