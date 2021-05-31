#include <iostream>
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
    if (!texture.loadFromFile("resources\\textures\\entity\\enemy.png"))
    {
        std::cout << "Enemy Textures not found!"
                  << "\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void Enemy::tick()
{
    float xOff = Game::getRandFloat() * 2 - 1;
    float yOff = Game::getRandFloat() * 2 - 1;
    std::cout << xOff << "," << yOff << "\n";
    float x = sprite.getPosition().x + xOff;
    float y = sprite.getPosition().y + yOff;
    if (x < 0)
    {
        x = 100;
    }
    if (x > 100)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 100;
    }
    if (y > 100)
    {
        y = 0;
    }
    sprite.setPosition(x, y);
}