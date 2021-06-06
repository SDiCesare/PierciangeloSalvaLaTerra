#ifndef Player_hpp
#define Player_hpp

#include "LivingEntity.hpp"
#include "..\\item\\Gun.hpp"

class Player : public LivingEntity
{
public:
    Player();
    void entityInit();
    void tick() override;
    bool isInvulnerable() override;
    void damage(float amount) override;
    Gun getGun();
    Bullet *shoot();

private:
    Gun gun;
    float invincibilityTime;
    float invincibilityFrames;
    float gunDelay;
};

#endif