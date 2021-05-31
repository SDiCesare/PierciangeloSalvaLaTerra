#ifndef Enemy_h
#define Enemy_h

#include "Entity.hpp"
#include "World.h"

class Enemy : public Entity
{
public:
    Enemy();
    void tick() override;
};

#endif