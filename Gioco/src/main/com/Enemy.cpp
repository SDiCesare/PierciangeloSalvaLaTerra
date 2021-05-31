#include <iostream>
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy() : Entity()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\enemy.png"))
    {
        std::cout << "Enemy Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setPosition(0, 0);
}

void Enemy::tick()
{
    float x = sprite->getPosition().x;
    float y = sprite->getPosition().y;

    float xSpeed = Game::getRandInt(0, 3) - 1.5f;
    /*if (xSpeed < -1)
        xSpeed = -1;
    if (xSpeed > 1)
        xSpeed = 1;*/

    float ySpeed = Game::getRandInt(0, 3) - 1.5f;
    /*if (ySpeed < -1)
        ySpeed = -1;
    if (ySpeed > 1)
        ySpeed = 1;*/

    sprite->setPosition(x + xSpeed, y + ySpeed);
}