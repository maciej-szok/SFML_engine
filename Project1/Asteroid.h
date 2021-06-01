#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "PhysicEntity.h"
#include <stdlib.h>   
#include <time.h>      
#include "ColorPalette.h"

class Asteroid : public PhysicEntity{
	int size;
	int numberOfVerticies = 20;

	
public:
	Asteroid(sf::Vector2f pos, sf::Vector2f direction, const float speed, const int size);
	void randomizeVertex(const int size);
	void collided(PhysicEntity collision);
};