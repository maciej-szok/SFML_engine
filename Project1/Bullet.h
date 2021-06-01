#pragma once
#include "PhysicEntity.h"
#include <iostream>

class Bullet : public PhysicEntity{
protected:
	void outsideScreen();
public:

	Bullet(sf::Vector2f pos, sf::VertexArray vertexArray, const float mass, const float fricionConstant);

};