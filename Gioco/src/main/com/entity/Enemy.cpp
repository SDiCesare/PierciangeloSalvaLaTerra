#include <iostream>
#include "Enemy.h"
#include "..\\Game.h"

Enemy::Enemy(World *world) : Entity(world)
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\enemy.png"))
    {
        std::cout << "Enemy Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
    sprite->setPosition(0, 0);
}

void Enemy::tick()
{
    sf::Vector2f playerPos = world->player->getPosition();
    sf::Vector2f pos = this->getPosition();
    int distX = playerPos.x - pos.x;
    int distY = playerPos.y - pos.y;
    if (distX > 0)
    {
        move(1, 0);
    }
    if (distX < 0)
    {
        move(-1, 0);
    }
    if (distY > 0)
    {
        move(0, 1);
    }
    if (distY < 0)
    {
        move(0, -1);
    }
}