#include "helperFunctions.h"

sf::Vector2f hf::normalizeVector(sf::Vector2f vector) {
	double len = vectorLength(vector);
	vector.x = vector.x / len;
	vector.y = vector.y / len;
	return vector;
}

double hf::vectorLength(sf::Vector2f vector) {
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

//converts angle in degress to normalized vector
sf::Vector2f hf::angleToVector(float angle) {
	double angleRad = angle * 3.14159265358979323846 / 180;
	return normalizeVector(sf::Vector2f(std::cos(angleRad), std::sin(angleRad)));
}

sf::VertexArray hf::globalBoundToVertexArray(sf::FloatRect rect) {
	sf::VertexArray outline(sf::LineStrip, 5);
	outline[0].position = sf::Vector2f(rect.left, rect.top);
	outline[1].position = sf::Vector2f(rect.left + rect.width, rect.top);
	outline[2].position = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
	outline[3].position = sf::Vector2f(rect.left, rect.top + rect.height);
	outline[4].position = sf::Vector2f(rect.left, rect.top);
	return outline;
}