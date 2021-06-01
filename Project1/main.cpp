#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "Player.h"
#include "ColorPalette.h"
                          
#include "CONFIG.h"
#include "BulletManager.h"
#include "helperFunctions.h"

#include "AsteroidManager.h"
#include "CollisionManager.h"

#include <iostream>


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    BulletManager bulletManager;
    AsteroidManager asteroidManager;
    CollisionManager collisionManager;

    collisionManager.addAsteroidManager(&asteroidManager);
    collisionManager.addBulletManager(&bulletManager);

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
    //sf::Vector2f pos2(300.f, 300.f);


    Player player(pos, vertexArray, 1.f, 0.015);
    player.setLabel("PLAYER");

    //Player player2(pos2, vertexArray, 1.f, 0.015);
    //player2.setLabel("PLAYER");

    collisionManager.addEntity((PhysicEntity*)&player);
    //collisionManager.addEntity((PhysicEntity*)&player2);

    int asteroidIndex = 0;

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {    
                    bulletManager.spawnBullet(player.getPosition(), hf::angleToVector(player.getRotation()), BULLET_SPEED, &collisionManager);
                }

                if (event.key.code == sf::Keyboard::M) {
                    //spawn asteroid for degub purp
                    //srand(time(NULL));

                    sf::Vector2f pos(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
                    sf::Vector2f dir(rand() % 10, rand() % 10);
                    dir = hf::normalizeVector(dir);
                    float speed = rand() % 800 / 100;   
                    int size = rand() % 40 + 5;

                    asteroidManager.spawnAsteroid(pos, dir, speed, size, &collisionManager, "ASTEROID");
                    asteroidIndex++;
                    std::cout << std::endl << "spawned seteroid" << std::endl << std::endl;
                }

            }
        }




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.accelerate();
        }

        player.accelerate();


        const float deltaTime = deltaClock.restart().asSeconds() * 60;


        player.updatePosition(deltaTime);
        bulletManager.updatePositions(deltaTime);
        asteroidManager.updatePositions(deltaTime);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.rotateLeft(deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.rotateRight(deltaTime);
        }



        collisionManager.checkCollisions();

        window.clear(ColorPalette::purple);

        //sf::FloatRect temp = player.getGlobalBounds();


        sf::VertexArray temp(sf::LineStrip, 4);

        //window.draw(hf::globalBoundToVertexArray(player.getCollider()));


        bulletManager.drawTo(&window);
        asteroidManager.drawTo(&window);

        window.draw(player.getDrawable());
       // window.draw(player2.getDrawable());
        window.display();
    }


    return 0;
}