#include "Player.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Player::Player() : LivingEntity(ResourceHandler::PLAYER_TEXTURE), gun("", 0, 0, 0)
{
}

void Player::entityInit()
{
    this->setMaxHealth(20.f);
    this->setHealth(20.f);
    this->setMaxSpeed(sf::Vector2f(5.f, 5.f));
}

void Player::tick()
{
    if (this->getHealth() < 0)
    {
        this->setAlive(false);
    }
}