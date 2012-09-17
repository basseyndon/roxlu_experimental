#ifndef ROXLU_EMITTERH
#define ROXLU_EMITTERH

#include <roxlu/Roxlu.h>
#include <pbd/PBD.h>

/* 

EMITTER
--------

The Emitter class is a simple helper to spawn particles at a 
certain pace. You can control several different spawn parameters
which are described below. We're trying to be flexible by 
adding a so called "Emitter Helper" which calculates a couple
of things needed by the emitter. See below for more info.

You can se the following emitter params:
---------------------------------------
- min_particle_size:       The minimum size of a particle
- max_particle_size:       The maximum size of a particle
- min_particle_lifetime:   The minimum particle lifetime
- max_particle_lifetime:   The maximum particle lifetime
- min_particle_mass:       The minimum mass of a particle
- max_particle_mass:       The maximum mass of a particle
- min_particle_random_x_vel: The minimum random x velocity
- max_particle_random_x_vel: The maximum random x velocity
- min_particle_random_y_vel: The minimum random y velocity
- max_particle_random_y_vel: The maximum random y velocity
- min_particle_random_z_vel: The minumum random z velocity
- max_particle_random_z_vel: The maximum random z velocity
- particle_x_vel:          The X-velocity of a particle when created
- particle_y_vel:          The Y-velocity of a particle when created
- particle_z_vel:          The Z-velocity of a particle when created
- min_emission:            Minimum particles to spawn per second
- max_emission:            Maximum allowed particles (per second)
- min_particle_lifetime:   The minimum lifetime of a particle (in frame numbers)
- max_particle_lifetime:   The maximum lifetime of a particle (in frame numbers)


 */

// -----------------------------------------------------------
// P = Particle type: Particle<Vec2> or Particle<Vec3>
// C = Particle container: Particles
// V = Vector class
// H = Emitter Helper (e.g. at what position are the particles spawn)
template<class P, class C, class V, class H>
class Emitter {
public:
	Emitter(C& particles, H& helper);
	void setParticleSize(const float min, const float max);
	void setParticleLifeTime(const float min, const float max);
	void setEmission(const float min, const float max);

	void update();

	C& particles;
	H& helper;
	rx_uint64 time_to_emit;
	rx_uint64 emit_time;

	// Particle settings:
	float min_particle_size; 
	float max_particle_size;
	int min_particle_lifetime;
	int max_particle_lifetime;
	float min_particle_mass;
	float max_particle_mass;
	float particle_x_vel;
	float particle_y_vel;
	float particle_z_vel;
	float min_particle_random_x_vel;
	float max_particle_random_x_vel;
	float min_particle_random_y_vel;
	float max_particle_random_y_vel;
	float min_particle_random_z_vel;
	float max_particle_random_z_vel;
	int min_emission;
	int max_emission;
};


template<class P, class C, class V, class H>
Emitter<P, C, V, H>::Emitter(C& particles, H& helper)
	:particles(particles)
	,helper(helper)
	,min_particle_size(0.1f)
	,max_particle_size(2.0f)
	,min_particle_lifetime(60)
	,max_particle_lifetime(2 * 60)
	,min_particle_mass(0.1f)
	,max_particle_mass(3.0f)
	,min_particle_random_x_vel(-2.0f)
	,max_particle_random_x_vel(2.0f)
	,min_particle_random_y_vel(0.0f)
	,max_particle_random_y_vel(-4.0f)
	,min_particle_random_z_vel(0.0f)
	,max_particle_random_z_vel(0.0f)
	,min_emission(100)
	,max_emission(200)
	,time_to_emit(0)
	,particle_x_vel(0.0f)
	,particle_y_vel(-2.8f)
	,particle_z_vel(0.0f)
{
	emit_time = 1000/(max_emission - min_emission);
	time_to_emit = Timer::now() + emit_time;
}

template<class P, class C, class V, class H>
void Emitter<P, C, V, H>::update() {
   helper.update();
	particles.removeDeadParticles();

	// Do we need to emit?
	rx_uint64 now = Timer::now();
	if(now < time_to_emit) {
		return;
	}

	// Did we reach the limit?
	size_t num_particles = particles.size();
	if(num_particles > max_emission) {
		return;
	}
	
	time_to_emit = now + emit_time;

	float	size = random(min_particle_size, max_particle_size);
	float	lifetime = random(min_particle_lifetime, max_particle_lifetime);
	float mass = random(min_particle_mass, max_particle_mass);
	V pos = helper.getPosition();
	V vel = helper.getVelocity(particle_x_vel, particle_y_vel, particle_z_vel);
	vel += helper.getRandomVelocity(min_particle_random_x_vel
											  ,max_particle_random_x_vel
											  ,min_particle_random_y_vel
											  ,max_particle_random_y_vel
											  ,min_particle_random_z_vel
											  ,max_particle_random_z_vel
											  ); 
	P* p = particles.createParticle(pos, mass);
	p->lifespan = lifetime;
	p->size = size;
	p->velocity = vel;
	particles.addParticle(p);
}


// --------------------------------------------------------------------
/**
 * The emitter class takes care of:
 * - calculating the position where to spawn new particles (getPosition)
 * - calculating the start velocity (getVelocity)
 * - applying random forces if necessary
 */
class EmitterHelper {
public:
	EmitterHelper(const float x, const float width, const float minY, const float maxY);
	Vec2 getPosition();
	Vec2 getVelocity(const float velX, const float velY, const float velZ);
	Vec2 getRandomVelocity(const float minx, const float maxx, const float miny, const float maxy, const float minz, const float maxz);
	void update();
	float min_y;
	float max_y;
	float emit_width;
	float emit_x;
	float emit_half_width;
};

inline EmitterHelper::EmitterHelper(const float x, const float width, const float minY, const float maxY)
	:min_y(minY)
	,max_y(maxY)
	,emit_width(width)
	,emit_x(0)
	,emit_half_width(emit_width * 0.5)
{
}

inline Vec2 EmitterHelper::getPosition() {
	return Vec2(random(emit_x-emit_half_width, emit_x+emit_half_width), random(min_y,max_y));
}

inline Vec2 EmitterHelper::getVelocity(const float vx, const float vy, const float vz) {
	return Vec2(vx, vy);
}

inline Vec2 EmitterHelper::getRandomVelocity(const float minx, const float maxx, const float miny, const float maxy, const float minz, const float maxz) {
	return Vec2(random(minx, maxx), random(miny, maxy));
}

inline void EmitterHelper::update() {

}
// -----------------------------------------------------------


#endif