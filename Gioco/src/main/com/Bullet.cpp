#include "Bullet.h"
#include "Entity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

Bullet::Bullet(Entity *source) : Entity()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\bullet.png"))
    {
        std::cout << "Bullet Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setPosition(0, 0);
    this->source = source;
    this->speed = sf::Vector2f(3.f, 3.f);
}

Bullet::Bullet(Entity *source, sf::Vector2f speed) : Entity()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\bullet.png"))
    {
        std::cout << "Bullet Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setPosition(0, 0);
    this->source = source;
    this->speed = speed;
}

void Bullet::tick()
{
    float x = this->sprite->getPosition().x;
    float y = this->sprite->getPosition().y;
    x += this->speed.x;
    y += this->speed.y;
    if (x > Game::width || y > Game::height) {
        this->alive = false;
    }
}