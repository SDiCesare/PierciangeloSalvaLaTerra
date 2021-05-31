#include "Player.h"
#include "Entity.hpp"
#include <iostream>
#include "Bullet.h"

Player::Player() : Entity()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\player.png"))
    {
        std::cout << "Bullet Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setPosition(0, 0);
    speed.x = 3;
    speed.y = 3;
}

void Player::tick()
{
    move();
}

void Player::move()
{
    float x = sprite->getPosition().x;
    float y = sprite->getPosition().y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x -= speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x += speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y -= speed.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y += speed.y;
    }
    sprite->setPosition(x, y);
}