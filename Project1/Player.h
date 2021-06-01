#pragma once
#include "ColorPalette.h"
#include "CONFIG.h"
#include "PhysicEntity.h"
#include <iostream>

class Player : public PhysicEntity{
private:
	const float mass = 1.f;
	const float frictionConstant = 1.f;
	const float rotateSpeed = 3.f;
	const float accelerationConstant = 0.11f;
public:
	Player(sf::Vector2f pos, sf::VertexArray vertexArray, const float mass, const float friction);
	void rotateRight(float deltaTime);
	void rotateLeft(float deltaTime);

	void collided(PhysicEntity collision);
	
	void accelerate();

};