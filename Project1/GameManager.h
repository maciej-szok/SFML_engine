#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "Player.h"
#include "ColorPalette.h"

#include "CONFIG.h"
#include "BulletManager.h"
#include "helperFunctions.h"

#include "AsteroidManager.h"
#include "CollisionManager.h"


class GameManager {
private:
    BulletManager bulletManager;
    AsteroidManager asteroidManager;
    CollisionManager collisionManager;
public:
    void setupGame();

    void run();

};