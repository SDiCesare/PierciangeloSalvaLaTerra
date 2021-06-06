#include "Bullet.hpp"

Bullet::Bullet(float damage, Direction dir, float factor, Entity &source) : Projectile("bullet", dir, factor, source)
{
    this->damage = damage;
}