#include "Bullet.h"

void Bullet::outsideScreen()
{
	//std::cout << "the bullet went outside the screen" << std::endl;
}

Bullet::Bullet(sf::Vector2f pos, sf::VertexArray vertexArray, const float mass, const float fricionConstant):
	PhysicEntity(pos,vertexArray, mass, fricionConstant)
{
}
