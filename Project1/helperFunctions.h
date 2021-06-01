#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>
namespace hf {
	sf::Vector2f normalizeVector(sf::Vector2f vector);


	double vectorLength(sf::Vector2f vector);

	//converts angle in degress to normalized vector
	sf::Vector2f angleToVector(float angle);

	sf::VertexArray globalBoundToVertexArray(sf::FloatRect rect);

}
