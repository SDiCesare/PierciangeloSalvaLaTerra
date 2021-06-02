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
    this->health = -1;
}

Entity::Entity(World *world) : Entity(nullptr, world)
{
}

//Called every tick
void Entity::tick()
{
}

//Called when source hits this entity
void Entity::onHit(Entity *source)
{
}

//Called when this entity hits tile
void Entity::onHit(Tile *tile)
{
}

void Entity::move(float x, float y)
{
    //Updating Facing Direction
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
    updateSprite();
    //Update Position
    x = this->sprite->getPosition().x + x;
    y = this->sprite->getPosition().y + y;
    if (world->canMove(this, x, y, width, height))
    {
        this->sprite->setPosition(x, y);
    }
}

//Move the entity to a specific position (x, y)
void Entity::moveTo(float x, float y)
{
    if (world->canMove(this, x, y, width, height))
    {
        this->sprite->setPosition(x, y);
    }
}

//Update the sprite direction
void Entity::updateSprite()
{
    if (this->facing.x == 1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, 0, this->width, this->height));
    }
    if (this->facing.x == -1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, this->height, this->width, this->height));
    }
    if (this->facing.y == 1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, this->height * 2, this->width, this->height));
    }
    if (this->facing.y == -1)
    {
        this->sprite->setTextureRect(sf::IntRect(0, this->height * 3, this->width, this->height));
    }
}

void Entity::setupSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

sf::Sprite Entity::getSprite()
{
    return *(this->sprite);
}

bool Entity::isAlive()
{
    return this->alive;
}

void Entity::setPos(sf::Vector2f v2f)
{
    this->sprite->setPosition(v2f);
}

void Entity::setPos(float x, float y)
{
    this->sprite->setPosition(x, y);
}

sf::Vector2f Entity::getPos()
{
    return this->sprite->getPosition();
}

World *Entity::getWorld()
{
    return this->world;
}

int Entity::getWidth()
{
    return this->width;
}

int Entity::getHeight()
{
    return this->height;
}

void Entity::setHealth(float health)
{
    this->health = health;
}

float Entity::getHealth()
{
    return this->health;
}