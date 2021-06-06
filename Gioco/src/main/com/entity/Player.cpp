#include "Player.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Player::Player() : LivingEntity("player"), gun("", 0, 0, 0)
{
    this->entityInit();
}

void Player::entityInit()
{
    std::cout << "Player Init\n";
    this->setMaxHealth(20.f);
    this->setHealth(20.f);
    this->setMaxSpeed(sf::Vector2f(5.f, 5.f));
    this->invincibilityFrames = 5.f;
    this->invincibilityTime = 0.f;
}

void Player::damage(float amount)
{
    LivingEntity::damage(amount);
    this->invincibilityTime = this->invincibilityFrames;
}

void Player::tick()
{
    if (this->getHealth() <= 0)
    {
        this->setAlive(false);
    }
    if (this->invincibilityTime > 0)
    {
        this->invincibilityTime -= 0.1f;
    }
}

bool Player::isInvulnerable()
{
    return this->invincibilityTime > 0;
}