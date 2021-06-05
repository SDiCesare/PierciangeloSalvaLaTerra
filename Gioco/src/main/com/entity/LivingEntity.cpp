#include "LivingEntity.hpp"
#include <iostream>

LivingEntity::LivingEntity(sf::Texture texture) : Entity(texture)
{
    this->entityInit();
}

void LivingEntity::entityInit()
{
    this->maxHealth = 0.f;
    this->health = 0.f;
    this->maxSpeed = sf::Vector2f(0.f, 0.f);
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