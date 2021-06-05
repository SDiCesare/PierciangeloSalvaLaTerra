#include "Tile.hpp"
#include <iostream>

Tile::Tile(sf::Texture texture) : textureBox(sf::TriangleStrip, 4)
{
    this->texture = texture;
    this->width = this->texture.getSize().x;
    this->height = this->texture.getSize().x;
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, this->height);
    textureBox[2].position = sf::Vector2f(this->width, 0);
    textureBox[3].position = sf::Vector2f(this->width, this->height);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(textureBox, states);
}

bool Tile::isSolid()
{
    return true;
}

bool Tile::isBreakableTo(Entity &entity)
{
    return false;
}

void Tile::onBreak(Entity &entity)
{
}

void Tile::setPosition(float x, float y)
{
    sf::Transformable::setPosition(x, y);
}

int Tile::getWidth()
{
    return this->width;
}

int Tile::getHeight()
{
    return this->height;
}

sf::Vector2f Tile::getPosition()
{
    return sf::Transformable::getPosition();
}