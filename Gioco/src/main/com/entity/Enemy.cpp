#include "Enemy.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"
#include "..\\Game.hpp"
#include "Player.hpp"

Enemy::Enemy() : LivingEntity("test")
{
    this->clock = 0;
    this->setMaxHealth(20.f);
    this->setHealth(20.f);
    this->setMaxSpeed(sf::Vector2f(2.5f, 2.5f));
}

void Enemy::tick()
{
    if (this->getHealth() < 0)
    {
        this->setAlive(false);
    }
    this->clock -= 0.1f;
    if (this->clock <= 0)
    {
        float xOff = Game::getRandInt(0.f, 4.f) - 2.f;
        float yOff = Game::getRandInt(0.f, 4.f) - 2.f;
        this->move(xOff, yOff);
        this->clock = 2.5f;
    }
}

void Enemy::onHit(Entity &entity)
{
    Player *p = dynamic_cast<Player *>(&entity);
    if (p != NULL && !p->isInvulnerable())
    {
        p->damage(1.f);
    }
}