#include "Tile.h"

Tile::Tile()
{
}

bool Tile::isAir()
{
    return true;
}

void Tile::setSprite(sf::Sprite *sprite)
{
    this->sprite = sprite;
}

void Tile::setTexture(sf::Texture *texture)
{
    this->texture = texture;
}

void Tile::setPos(sf::Vector2f pos)
{
    this->sprite->setPosition(pos);
}

void Tile::setPos(float x, float y)
{
    this->sprite->setPosition(x, y);
}

sf::Sprite Tile::getSprite()
{
    return *(this->sprite);
}

sf::Texture Tile::getTexture()
{
    return *(this->texture);
}

sf::Vector2f Tile::getPos()
{
    return this->sprite->getPosition();
}