#include "BulletManager.h"


void BulletManager::updatePositions(float deltaTime) {
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->updatePosition(deltaTime);
	}
}


void BulletManager::spawnBullet(sf::Vector2f position, sf::Vector2f direction, const float speed, CollisionManager* cm) {


	sf::VertexArray shape(sf::Triangles, 3);
	shape[0].position = sf::Vector2f(0.f, 0.f);
	shape[1].position = sf::Vector2f(10.f, 0.f);
	shape[2].position = sf::Vector2f(5.f, 5.f);

	shape[0].color = ColorPalette::darkGray;
	shape[1].color = ColorPalette::darkGray;
	shape[2].color = ColorPalette::darkGray;

	Bullet *temp = new Bullet(position, shape, bulletMass,0);
	sf::Vector2f speedVector = direction * speed;
	temp->setSpeed(speedVector);
	temp->setLabel("BULLET");
	cm->addEntity(temp);
	bullets.push_back(temp);
}

void BulletManager::removeBulletByReference(PhysicEntity* bl)
{
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bl), bullets.end());
}


void BulletManager::drawTo(sf::RenderWindow *renderTarget) {
	for (size_t i = 0; i < bullets.size(); i++)
	{
		renderTarget->draw(bullets[i]->getDrawable());
	}
}


BulletManager::~BulletManager()
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}
}