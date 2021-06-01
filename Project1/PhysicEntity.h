#pragma once

#include "Entity.h"
#include "CONFIG.h"
#include <iostream>


class PhysicEntity : public Entity{
protected:
	float mass = 1.f;
	float frictionConstant = 0.015f;
	bool wraps = true;

	sf::FloatRect collider;

	sf::Vector2f speed;
	sf::Vector2f acceleration;

	virtual void outsideScreen();
public:
	PhysicEntity(sf::Vector2f pos, sf::VertexArray vertexArray, const float mass, const float fricionConstant);
	PhysicEntity();

	void setSpeed(sf::Vector2f speed);

	sf::FloatRect getCollider();
	virtual void collided(PhysicEntity collision);

	


	void updatePosition(float deltaTime);
};