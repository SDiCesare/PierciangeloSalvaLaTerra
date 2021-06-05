#include "Gun.hpp"

Gun::Gun(std::string name, float strength, float delay, float speedFactor) : Item(name)
{
    this->strength = strength;
    this->delay = delay;
    this->speedFactor = speedFactor;
}

float Gun::getStrength()
{
    return this->strength;
}

float Gun::getSpeedFactor()
{
    return this->speedFactor;
}

float Gun::getDelay()
{
    return this->delay;
}