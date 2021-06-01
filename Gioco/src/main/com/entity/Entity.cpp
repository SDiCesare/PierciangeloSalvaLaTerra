#include "Entity.hpp"
#include <iostream>
#include "..\\Game.h"

Entity::Entity(sf::Sprite *sprite, World *world)
{
    this->sprite = sprite;
    this->alive = true;
    this->facing.x = 0;
    this->facing.y = 1;
    this->world = world;
}

Entity::Entity(World *world) : Entity(nullptr, world)
{
}

void Entity::tick()
{
}

void Entity::move(float x, float y)
{
    if (x < 0)
    {
        this->facing.x = -1;
        this->facing.y = 0;
    }
    if (x > 0)
    {
        this->facing.x = 1;
        this->facing.y = 0;
    }
    if (y < 0)
    {
        this->facing.y = -1;
        this->facing.x = 0;
    }
    if (y > 0)
    {
        this->facing.y = 1;
        this->facing.x = 0;
    }
    x = this->sprite->getPosition().x + x;
    y = this->sprite->getPosition().y + y;
    this->sprite->setPosition(x, y);
    updateSprite();
}

void Entity::moveTo(float x, float y)
{
    this->sprite->setPosition(x, y);
}

void Entity::updateSprite()
{
    if (this->facing.x == 1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
    }
    if (this->facing.x == -1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, 16, 16, 16));
    }
    if (this->facing.y == 1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, 32, 16, 16));
    }
    if (this->facing.y == -1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, 48, 16, 16));
    }
}

sf::Sprite Entity::getSprite()
{
    return *(this->sprite);
}

bool Entity::isAlive()
{
    return this->alive;
}

void Entity::setPosition(sf::Vector2f v2f)
{
    this->sprite->setPosition(v2f);
}

sf::Vector2f Entity::getPosition()
{
    return this->sprite->getPosition();
}

World *Entity::getWorld()
{
    return this->world;
}