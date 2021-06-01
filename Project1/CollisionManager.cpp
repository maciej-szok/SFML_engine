#include "CollisionManager.h"	

CollisionManager::CollisionManager() {}


//checks if any of the entities is outside the screen and can destroy/whatever them
void CollisionManager::checkOutsideScreen()
{
	std::vector<PhysicEntity*> toRemove(2);
	for (size_t j = 0; j < entities.size(); j++) {
		if (entities[j]->isOutsideScreen()) {
			if (entities[j]->getLabel() == "BULLET") {
				toRemove.push_back(entities[j]);
				bulletManager->removeBulletByReference(entities[j]);
			}
		}
	}

	//remove all the entities that need to be removed
	for (auto entity : toRemove) {
		this->removeEntityByReference(entity);
	}

}


//defines behaviour for objects when they collide
void CollisionManager::objectsCollided(PhysicEntity* entity1, PhysicEntity* entity2)
{
	std::vector<PhysicEntity*> toRemove(2);

	entity1->collided(*entity2);
	entity2->collided(*entity1);
	if (entity1->getLabel() == "ASTEROID" && entity2->getLabel() == "BULLET") {
		asteroidManager->removeAsteroidByReference((Asteroid*)entity1);
		toRemove.push_back(entity1);
		bulletManager->removeBulletByReference(entity2);
		toRemove.push_back(entity2);
	}

	//remove all the entities that need to be removed
	for (auto entity : toRemove) {
		this->removeEntityByReference(entity);
	}

}


void CollisionManager::checkCollisions()
{
	//okay that somehow works just fine lets not touch it until necessary [solution: make the method collided(...) virtual in PhysicEntity
	//jim lahley wali wódê
	for (size_t j = 0; j < entities.size(); j++)
		for (size_t i = j; i < entities.size(); i++)
		{
			if (i != j) 
				if(entities[j]->getCollider().intersects(entities[i]->getCollider())){
					this->objectsCollided(entities[j], entities[i]);
				}
		}
	
	this->checkOutsideScreen();

}

void CollisionManager::addEntity(PhysicEntity *entity)
{
	entities.push_back(entity);
}

void CollisionManager::addAsteroidManager(AsteroidManager* am)
{
	this->asteroidManager = am;
}

void CollisionManager::addBulletManager(BulletManager* bm)
{
	this->bulletManager = bm;
}

void CollisionManager::removeEntityByReference(PhysicEntity* pe)
{
	entities.erase(std::remove(entities.begin(), entities.end(), pe), entities.end());
}
