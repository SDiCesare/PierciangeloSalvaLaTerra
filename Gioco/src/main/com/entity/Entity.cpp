#include "Entity.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Entity::Entity(std::string name) : textureBox(sf::TriangleStrip, 4)
{
    //Initialize Render
    this->texture = ResourceHandler::getOrCreate("entity", name);
    this->width = this->texture.getSize().x;
    this->height = this->texture.getSize().x;
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, this->height);
    textureBox[2].position = sf::Vector2f(this->width, 0);
    textureBox[3].position = sf::Vector2f(this->width, this->height);
    this->updateFacing(Direction::SOUTH);
    //Initialize Stats
    this->alive = true;
}

void Entity::onHit(Entity &entity)
{
}

void Entity::onHit(Tile &tile)
{
}

void Entity::move(float x, float y)
{
    if (x != 0)
    {
        updateFacing(x < 0 ? Direction::WEST : Direction::EAST);
    }
    else if (y != 0)
    {
        updateFacing(y < 0 ? Direction::NORTH : Direction::SOUTH);
    }
    sf::Vector2f pos = this->getPosition();
    this->setPosition(pos.x + x, pos.y + y);
}

void Entity::move(sf::Vector2f move)
{
    this->move(move.x, move.y);
}

void Entity::updateFacing(Direction dir)
{
    this->facing = dir;
    //0: North, 1: South, 2: West, 3: East
    switch (dir.getOrdinal())
    {
    case 0:
        textureBox[0].texCoords = sf::Vector2f(0, 0);
        textureBox[1].texCoords = sf::Vector2f(0, this->height);
        textureBox[2].texCoords = sf::Vector2f(this->width, 0);
        textureBox[3].texCoords = sf::Vector2f(this->width, this->height);
        break;
    case 1:
        textureBox[0].texCoords = sf::Vector2f(0, this->height);
        textureBox[1].texCoords = sf::Vector2f(0, this->height * 2);
        textureBox[2].texCoords = sf::Vector2f(this->width, this->height);
        textureBox[3].texCoords = sf::Vector2f(this->width, this->height * 2);
        break;
    case 2:
        textureBox[0].texCoords = sf::Vector2f(0, this->height * 2);
        textureBox[1].texCoords = sf::Vector2f(0, this->height * 3);
        textureBox[2].texCoords = sf::Vector2f(this->width, this->height * 2);
        textureBox[3].texCoords = sf::Vector2f(this->width, this->height * 3);
        break;
    case 3:
        textureBox[0].texCoords = sf::Vector2f(0, this->height * 3);
        textureBox[1].texCoords = sf::Vector2f(0, this->height * 4);
        textureBox[2].texCoords = sf::Vector2f(this->width, this->height * 3);
        textureBox[3].texCoords = sf::Vector2f(this->width, this->height * 4);
        break;
    default:
        std::cout << "Invalid Ordinal" << dir.getOrdinal() << "\n";
    }
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(textureBox, states);
}

void Entity::tick()
{
}

//Setter

void Entity::setAlive(bool alive)
{
    this->alive = alive;
}

void Entity::setPosition(float x, float y)
{
    this->oldPosition.x = this->getPosition().x;
    this->oldPosition.y = this->getPosition().y;
    sf::Transformable::setPosition(x, y);
}

//Getter

bool Entity::isAlive()
{
    return this->alive;
}

int Entity::getWidth()
{
    return this->width;
}

int Entity::getHeight()
{
    return this->height;
}

sf::Vector2f Entity::getPosition()
{
    return sf::Transformable::getPosition();
}

sf::Vector2f Entity::getOldPosition()
{
    return this->oldPosition;
}

Direction Entity::getFacing()
{
    return this->facing;
}