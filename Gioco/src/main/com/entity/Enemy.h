#ifndef Enemy_h
#define Enemy_h

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy();
    void tick() override;
};

#endif