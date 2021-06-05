#include "Enemy.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Enemy::Enemy() : LivingEntity(ResourceHandler::SNAKE_TEXTURE)
{
}

void Enemy::tick()
{
    if (this->getHealth() < 0)
    {
        this->setAlive(false);
    }
    this->move(0.1f, 0.1f);
}

void Enemy::onHit(Entity &entity)
{
}