#ifndef Player_hpp
#define Player_hpp

#include "LivingEntity.hpp"
#include "..\\item\\Gun.hpp"

class Player : public LivingEntity
{
public:
    Player();

    /**
     * @brief Called from the Constructor, initialize the stats of the entity
     * */
    void entityInit();

    /**
     * @return The Current Gun of the Player
     * */
    Gun getGun();

    /**
     * @brief Called for Shooting from the Gun of the Player
     * 
     * @return A pointer of the shooted projectile
     * */
    Projectile *shoot();

    void tick() override;
    bool isInvulnerable() override;
    void damage(float amount) override;

private:
    Gun gun;
    float invincibilityTime;
    float invincibilityFrames;
    float gunDelay;
};

#endif