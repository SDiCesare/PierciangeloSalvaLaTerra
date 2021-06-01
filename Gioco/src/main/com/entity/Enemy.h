#ifndef Enemy_h
#define Enemy_h

#include "Entity.hpp"
class World;
class Enemy : public Entity
{
public:
    Enemy(World *World);
    void tick() override;
    void checkplayer();
    void onHit(Entity *entity) override;
};

#endif