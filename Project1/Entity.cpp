#include "Entity.h"

Entity::Entity(sf::Vector2f pos, sf::VertexArray vertexArray) {
	this->vertexArray = vertexArray;
	
	this->setPosition(pos);
}



Entity::Entity() {

}

void Entity::setRotation(const float angle) {
	float rotationDelta = angle - currentAngle;
	this->rotate(rotationDelta);
}


void Entity::rotate(const float angle) {
	for (int i = 0; i < 3; i++)
	{
		vertexArray[i].position = rotatePoint(vertexArray[i].position, currentPosition, angle);
	}
	currentAngle += angle;
}


//some math i stole of the internet, makes point go brrr around other point
sf::Vector2f Entity::rotatePoint(sf::Vector2f point, sf::Vector2f origin, const float rotationAngle) {
	float angleRad = (rotationAngle) * ((atan(1) * 4) / 180); // Convert to radians; atan(1)*4 is PI
	float rotatedX = std::cos(angleRad) * (point.x - origin.x) - std::sin(angleRad) * (point.y - origin.y) + origin.x;
	float rotatedY = std::sin(angleRad) * (point.x - origin.x) + std::cos(angleRad) * (point.y - origin.y) + origin.y;
	return sf::Vector2f(rotatedX, rotatedY);
}


sf::VertexArray Entity::getDrawable() {
	return vertexArray;
}

void Entity::setPosition(sf::Vector2f pos) {
	this->move(pos - currentPosition);
}

void Entity::setPositionX(const float x) {
	this->move(sf::Vector2f(x - currentPosition.x, 0));
}

void Entity::setPositionY(const float y) {
	this->move(sf::Vector2f(0, y - currentPosition.y));
}

void Entity::setLabel(std::string label)
{
	this->label = label;
}

std::string Entity::getLabel()
{
	return this->label;
}

bool Entity::isOutsideScreen()
{
	if (currentPosition.x > SCREEN_WIDTH) {
		return true;
	}
	if (currentPosition.y > SCREEN_HEIGHT) {
		return true;
	}
	if (currentPosition.x < 0) {
		return true;
	}
	if (currentPosition.y < 0) {
		return true;
	}
	return false;
}


sf::Vector2f Entity::getPosition() {
	return currentPosition;
}

float Entity::getRotation() {
	return currentAngle;
}


void Entity::move(sf::Vector2f moveVector) {
	float sumX = 0;
	float sumY = 0;
	for (size_t i = 0; i < vertexArray.getVertexCount(); i++)
	{
		vertexArray[i].position += moveVector;
		sumX += vertexArray[i].position.x;
		sumY += vertexArray[i].position.y;
	}
	//sets the currentPosition as about middle of the shape
	sumX /= vertexArray.getVertexCount();
	sumY /= vertexArray.getVertexCount();

	currentPosition = sf::Vector2f(sumX, sumY);
}