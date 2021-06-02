#include "Bullet.h"
#include <iostream>
#include "..\\Game.h"

Bullet::Bullet(Entity *source) : Bullet(source, sf::Vector2f(0, 0))
{
}

Bullet::Bullet(Entity *source, sf::Vector2f speed) : Entity(source->getWorld())
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\bullet.png"))
    {
        std::cout << "Bullet Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    this->source = source;
    this->speed = speed;
    this->strength = 0.f;
    this->alive = true;
    this->setupSize(8, 8);
}

void Bullet::onHit(Entity *entity)
{
    if (entity != this->source)
    {
        entity->setHealth(entity->getHealth() - this->strength);
        this->alive = false;
    }
}

void Bullet::onHit(Tile *tile)
{
    this->alive = false;
}

void Bullet::tick()
{
    this->move(this->speed.x, this->speed.y);
    if (this->getPos().x < 0 || this->getPos().y < 0 || this->getPos().x > Game::width || this->getPos().y > Game::height)
    {
        this->alive = false;
    }
}

void Bullet::setStrength(float strength)
{
    this->strength = strength;
}