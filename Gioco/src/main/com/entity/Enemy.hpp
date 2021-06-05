#ifndef Enemy_hpp
#define Enemy_hpp

#include "LivingEntity.hpp"

class Enemy : public LivingEntity
{
public:
    Enemy();
    void tick() override;
    void onHit(Entity &entity) override;

private:
    float clock;
};

#endif