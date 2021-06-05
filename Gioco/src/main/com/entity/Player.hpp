#ifndef Player_hpp
#define Player_hpp

#include "LivingEntity.hpp"
#include "..\\item\\Gun.h"

class Player : public LivingEntity
{
public:
    Player();
    void entityInit() override;
    void tick() override;

private:
    Gun gun;
};

#endif