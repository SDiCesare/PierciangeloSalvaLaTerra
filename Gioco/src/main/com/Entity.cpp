#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

Entity::Entity(sf::Sprite *sprite)
{
    this->sprite = sprite;
    this->alive = true;
}

Entity::Entity()
{
    this->alive = true;
}

void Entity::setPosition(sf::Vector2f v2f)
{
    sprite->setPosition(v2f);
}

void Entity::tick()
{
}

sf::Sprite Entity::getSprite()
{
    return *sprite;
}

bool Entity::isAlive() {
    return this->alive;
}