#include "Tile.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Tile::Tile(std::string name) : textureBox(sf::TriangleStrip, 4)
{
    this->name = name;
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
    textureBox[0].position = sf::Vector2f(x, y);
    textureBox[1].position = sf::Vector2f(x, this->height + y);
    textureBox[2].position = sf::Vector2f(this->width + x, y);
    textureBox[3].position = sf::Vector2f(this->width + x, this->height + y);
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
    return textureBox[0].position;
}

void Tile::setOffset(int x, int y)
{
    this->xOff = x;
    this->yOff = y;
    textureBox[0].texCoords = sf::Vector2f(this->xOff, this->yOff);
    textureBox[1].texCoords = sf::Vector2f(this->xOff, this->height);
    textureBox[2].texCoords = sf::Vector2f(this->width, this->yOff);
    textureBox[3].texCoords = sf::Vector2f(this->width, this->height);
}

void Tile::setXOff(int x)
{
    this->setOffset(x, this->yOff);
}

void Tile::setYOff(int y)
{
    this->setOffset(this->xOff, y);
}

Tile Tile::clone()
{
    Tile t = Tile(this->name);
    t.setOffset(this->xOff, this->yOff);
    t.setPosition(this->getPosition().x, this->getPosition().y);
    return t;
}

void Tile::setBounds(int x, int y, float width, float height)
{
    this->width = width;
    this->height = height;
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, this->height);
    textureBox[2].position = sf::Vector2f(this->width, 0);
    textureBox[3].position = sf::Vector2f(this->width, this->height);
    this->setOffset(x, y);
}

sf::VertexArray Tile::getTextureBox()
{
    return this->textureBox;
}