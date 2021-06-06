#ifndef Bullet_hpp
#define Bullet_hpp

#include "Projectile.hpp"

class Bullet : public Projectile
{
public:
    Bullet(float damage, Direction dir, float factor, Entity &source);
};

#endif