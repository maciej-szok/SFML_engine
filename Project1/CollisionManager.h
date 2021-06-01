#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "PhysicEntity.h"
#include <iostream>
#include "Player.h"
#include "BulletManager.h"


#include "AsteroidManager.h"

class AsteroidManager;
class BulletManager;

class CollisionManager {
private:
	std::vector<PhysicEntity*> entities;
	AsteroidManager *asteroidManager;
	BulletManager* bulletManager;

	void checkOutsideScreen();
	void objectsCollided(PhysicEntity* entity1, PhysicEntity* entity2);

public:
	CollisionManager();
	//TODO collisions
	//its actually way more complex than i thought
	//well fuck that lets make it simple and inefficient
	void checkCollisions();

	void addEntity(PhysicEntity *entity);
	void addAsteroidManager(AsteroidManager* am);
	void addBulletManager(BulletManager* bm);

	void removeEntityByReference(PhysicEntity* pe);
};
