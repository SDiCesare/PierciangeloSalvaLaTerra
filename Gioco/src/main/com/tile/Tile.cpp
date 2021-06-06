#include "Tile.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Tile::Tile(std::string name) : textureBox(sf::TriangleStrip, 4)
{
    this->texture = ResourceHandler::getOrCreate("tile", name);
    this->width = this->texture.getSize().x;
    this->height = this->texture.getSize().y;
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, this->height);
    textureBox[2].position = sf::Vector2f(this->width, 0);
    textureBox[3].position = sf::Vector2f(this->width, this->height);
    textureBox[0].texCoords = sf::Vector2f(0, 0);
    textureBox[1].texCoords = sf::Vector2f(0, this->height);
    textureBox[2].texCoords = sf::Vector2f(this->width, 0);
    textureBox[3].texCoords = sf::Vector2f(this->width, this->height);
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