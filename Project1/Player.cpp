#include "Player.h"


Player::Player(sf::Vector2f pos, sf::VertexArray vertexArray, const float mass, const float friction) : PhysicEntity(pos,vertexArray, mass, friction){

}



void Player::rotateRight(float deltaTime) {
	this->rotate(rotateSpeed * deltaTime);

}

void Player::rotateLeft(float deltaTime) {
	this->rotate(-rotateSpeed * deltaTime);
}

void Player::collided(PhysicEntity collision)
{
	std::cout << "player sie wjebal w: " << collision.getLabel() << std::endl;
}

void Player::accelerate() {
	float angleRad = (currentAngle) * ((atan(1) * 4) / 180); // Convert to radians; atan(1)*4 is PI
	acceleration.x = std::cos(angleRad) * accelerationConstant;
	acceleration.y = std::sin(angleRad) * accelerationConstant;
}