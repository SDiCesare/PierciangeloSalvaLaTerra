#ifndef Enemy_hpp
#define Enemy_hpp

#include "LivingEntity.hpp"
#include "..\\item\\Gun.h"

class Enemy : public LivingEntity
{
public:
    Enemy();
    void tick() override;
    void onHit(Entity &entity) override;
};

#endif