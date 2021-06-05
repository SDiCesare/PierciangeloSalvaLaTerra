#include "LivingEntity.hpp"
#include <iostream>

LivingEntity::LivingEntity(sf::Texture texture) : Entity(texture)
{
}

bool LivingEntity::isInvulnerable()
{
    return false;
}

void LivingEntity::damage(float amount)
{
    this->health -= amount;
}

//Setter

void LivingEntity::setMaxHealth(float maxHealth)
{
    this->maxHealth = maxHealth;
}

void LivingEntity::setHealth(float health)
{
    this->health = health;
}

void LivingEntity::setMaxSpeed(sf::Vector2f maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

//Getter

float LivingEntity::getMaxHealth()
{
    return this->maxHealth;
}

float LivingEntity::getHealth()
{
    return this->health;
}

sf::Vector2f LivingEntity::getMaxSpeed()
{
    return this->maxSpeed;
}