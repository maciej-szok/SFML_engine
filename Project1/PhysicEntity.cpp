#include "PhysicEntity.h"

PhysicEntity::PhysicEntity(sf::Vector2f pos, sf::VertexArray vertexArray, 
	const float mass, const float fricionConstant) : Entity(pos, vertexArray){
	this->frictionConstant = fricionConstant;
	this->mass = mass;
	this->collider = this->vertexArray.getBounds();
}



PhysicEntity::PhysicEntity() {
	this->mass = 0;
	this->frictionConstant = 0;
	this->currentAngle = 0;

}


void PhysicEntity::setSpeed(sf::Vector2f speed) {
	this->speed = speed;
}

sf::FloatRect PhysicEntity::getCollider()
{
	return this->getDrawable().getBounds();
}

void PhysicEntity::collided(PhysicEntity collision)
{
	std::cout << this->label << " collided with: " << collision.label << std::endl;
}


//okay so this method defines what happens when entity flies off the screen
//(outside the visible area)
//by default is just wraps to the other side 
//but behaviour can be changed by overloading this method in derieved class
void PhysicEntity::outsideScreen()
{
	if (currentPosition.x > SCREEN_WIDTH) {
		this->setPositionX(1);
	}
	if (currentPosition.y > SCREEN_HEIGHT) {
		this->setPositionY(1);
	}
	if (currentPosition.x < 0) {
		this->setPositionX(SCREEN_WIDTH - 1);
	}
	if (currentPosition.y < 0) {
		this->setPositionY(SCREEN_HEIGHT - 1);
	}
}


void PhysicEntity::updatePosition(float deltaTime) {
	speed.x += acceleration.x;
	speed.y += acceleration.y;
	acceleration.x = 0;
	acceleration.y = 0;
	speed.x -= speed.x * frictionConstant;
	speed.y -= speed.y * frictionConstant;
	this->move(speed * deltaTime);

	if (this->isOutsideScreen()) this->outsideScreen();
}