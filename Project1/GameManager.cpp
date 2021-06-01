#include "GameManager.h"

void GameManager::setupGame()
{
	collisionManager.addAsteroidManager(&asteroidManager);
	collisionManager.addBulletManager(&bulletManager);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroids!", sf::Style::Default, settings);
	window.setFramerateLimit(60);
    int size = 50;

    sf::VertexArray vertexArray = sf::VertexArray(sf::Triangles, 3);
    vertexArray[0].position = sf::Vector2f(0.f, 0.f);
    vertexArray[1].position = sf::Vector2f(size / 2, size);
    vertexArray[2].position = sf::Vector2f(size, 0.f);

    vertexArray[0].color = ColorPalette::pink;
    vertexArray[1].color = ColorPalette::red;
    vertexArray[2].color = ColorPalette::pink;

    sf::Vector2f pos(200.f, 200.f);


    Player player(pos, vertexArray, 1.f, 0.015);
    player.setLabel("PLAYER");



    collisionManager.addEntity((PhysicEntity*)&player);

}


void GameManager::run()
{
}
