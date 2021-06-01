#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "PhysicEntity.h"
#include "ColorPalette.h"
#include "Asteroid.h"
#include "helperFunctions.h"
#include <iostream>
#include <algorithm>


#include "CollisionManager.h"


class CollisionManager;

class AsteroidManager {
private:
	std::vector<Asteroid*> asteroids;
public:
	void updatePositions(float deltaTime);

	void drawTo(sf::RenderWindow* renderTarget);
	void drawColliders(sf::RenderWindow* renderTarget);


	//dir must be a normalized vector
	void spawnAsteroid(sf::Vector2f position, sf::Vector2f direction, const float speed, int size, CollisionManager* cm, std::string label = "");

	void removeAsteroidByReference(Asteroid* asteroid);

	~AsteroidManager();

};