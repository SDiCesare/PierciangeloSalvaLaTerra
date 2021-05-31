#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

Entity::Entity(sf::Sprite sprite)
{
    this->sprite = sprite;
}

Entity::Entity()
{
}

void Entity::setPosition(sf::Vector2f v2f)
{
    sprite.setOrigin(v2f);
}

void Entity::tick()
{
    
}

sf::Sprite Entity::getSprite()
{
    return this->sprite;
}