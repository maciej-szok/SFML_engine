#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "CONFIG.h"


class Entity {
protected:
	sf::Vector2f currentPosition;
	float currentAngle = 90.f;

	std::string label;

	sf::VertexArray vertexArray;


	sf::Vector2f rotatePoint(sf::Vector2f point, sf::Vector2f origin, const float rotationAngle);
public:
	Entity(sf::Vector2f pos, sf::VertexArray vertexArray);
	Entity();
	void setRotation(const float angle);
	void rotate(const float angle);


	sf::VertexArray getDrawable();

	void move(sf::Vector2f moveVector);
	void setPosition(sf::Vector2f pos);
	void setPositionX(const float x);
	void setPositionY(const float y);

	void setLabel(std::string label);
	std::string getLabel();

	bool isOutsideScreen();


	sf::Vector2f getPosition();
	float getRotation();
};