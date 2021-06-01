#include "Asteroid.h"


Asteroid::Asteroid(sf::Vector2f pos, sf::Vector2f direction, const float speed, const int size)
{
	this->setSpeed(direction * speed);
	this->size = size;

	this->randomizeVertex(this->size);
	this->setPosition(pos);
}

void Asteroid::randomizeVertex(const int size)
{
	//takes a circle and makes it randomly pointy so it kinds resembles a asteroid
	//(it looks more like shit) TODO make it look like a fucking asteroid 
	sf::CircleShape circle(50, numberOfVerticies);

	sf::VertexArray finalShape(sf::TriangleFan, numberOfVerticies);

	srand(time(NULL));

	int variation = size/1.1;


	for (size_t i = 0; i < numberOfVerticies; i++)
	{
		int randX = rand() % variation + variation/2;
		int randY = rand() % variation + variation/2;
		randX -= variation;
		randY -= variation;
		finalShape[i].position = circle.getPoint(i) + sf::Vector2f(randX, randY);
		finalShape[i].color = ColorPalette::red;
	}

	this->vertexArray = finalShape;
	
}


void Asteroid::collided(PhysicEntity collision)
{
	if (collision.getLabel() == "BULLET") {
		std::cout << "whoops the asredois: " << this->getLabel() << " collider with bullet. Destroying." << std::endl;
	}
}