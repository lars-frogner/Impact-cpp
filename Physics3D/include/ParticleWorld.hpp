#pragma once
#include "precision.hpp"
#include "ParticleForceRegistry.hpp"
#include "ParticleForceGenerator.hpp"
#include "ParticleContact.hpp"
#include "ParticleContactResolver.hpp"
#include "ParticleContactGenerator.hpp"
#include <vector>
#include <ctime>

namespace Impact {
namespace Physics3D {

class ParticleWorld {

protected:

	std::vector<Particle*> _particles;
	std::vector<ParticleContactGenerator*> _contact_generators;
	ParticleForceRegistry _force_registry;
	
	imp_uint _max_contacts;
	ParticleContact* _contacts;
	ParticleContactResolver _contact_resolver;

	bool _calculate_iterations;

	imp_uint generateContacts();

	void integrateMotion(imp_float duration);

	void resetForces();

public:

	ParticleWorld(imp_uint new_max_contacts, imp_uint max_iterations = 0);
	~ParticleWorld();

	ParticleWorld(const ParticleWorld& other) = delete;
	ParticleWorld& operator=(const ParticleWorld& other) = delete;

	void addParticle(Particle* particle);
	void removeParticle(Particle* particle);
	void clearParticles();

	bool hasParticle(Particle* particle) const;
	bool hasParticles(const std::vector<Particle*>& particles) const;

	void addContactGenerator(ParticleContactGenerator* contact_generator);
	void removeContactGenerator(ParticleContactGenerator* contact_generator);
	void clearContactGenerators();

	void addForceGenerator(Particle* particle, ParticleForceGenerator* force_generator);
	void removeForceGenerator(Particle* particle, ParticleForceGenerator* force_generator);
	void clearForceGenerators();

	imp_uint getNumberOfParticles() const;

	void performPerFrameInitialization();

	void advance(imp_float duration);

	void updateTransformations();
};

} // Physics3D
} // Impact
