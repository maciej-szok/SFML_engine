#include "AsteroidManager.h"

void AsteroidManager::updatePositions(float deltaTime) {
	for (size_t i = 0; i < asteroids.size(); i++)
	{
		asteroids[i]->updatePosition(deltaTime);
	}
}


void AsteroidManager::spawnAsteroid(sf::Vector2f position, sf::Vector2f direction, const float speed, int size, CollisionManager* cm, std::string label) {

	Asteroid *temp = new Asteroid(position, direction, speed, size);
	sf::Vector2f speedVector = direction * speed;
	temp->setSpeed(speedVector);
	temp->setLabel(label);
	asteroids.push_back(temp);

	cm->addEntity((PhysicEntity*)temp);	
}

void AsteroidManager::drawColliders(sf::RenderWindow* renderTarget)
{
	for (size_t i = 0; i < asteroids.size(); i++)
	{
		//renderTarget->draw(hf::globalBoundToVertexArray(asteroids[i]->getDrawable().getBounds()));
		renderTarget->draw(hf::globalBoundToVertexArray(asteroids[i]->getCollider()));
	}
}


AsteroidManager::~AsteroidManager()
{
	//is that the way to do it?? TODO check if there is memory leak
	for (int i = 0; i < asteroids.size(); i++)
	{
		delete asteroids[i];
	}
}

void AsteroidManager::removeAsteroidByReference(Asteroid* ast)
{
	asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
}

void AsteroidManager::drawTo(sf::RenderWindow* renderTarget) 
{
	for (size_t i = 0; i < asteroids.size(); i++)
	{
		renderTarget->draw(asteroids[i]->getDrawable());
	}
}