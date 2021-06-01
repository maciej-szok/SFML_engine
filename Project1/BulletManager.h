#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "PhysicEntity.h"
#include "ColorPalette.h"
#include "CollisionManager.h"
#include "Bullet.h"

class CollisionManager;

class BulletManager {
private:
	const float bulletMass = 1.f;
	std::vector<Bullet*> bullets;
public:
	void updatePositions(float deltaTime);


	void drawTo(sf::RenderWindow *renderTarget);

	//dir must be a normalized vector
	void spawnBullet(sf::Vector2f position, sf::Vector2f direction, const float speed, CollisionManager* cm);

	void removeBulletByReference(PhysicEntity* bl);

	~BulletManager();

};