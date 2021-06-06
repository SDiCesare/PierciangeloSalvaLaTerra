#ifndef Gun_hpp
#define Gun_hpp

#include "Item.hpp"
#include "..\\entity\\Bullet.hpp"

class Gun : public Item
{
public:
    /**
     * @brief Te Constructor for the Class Gun
     * 
     * @param name The ItemGun Name
     * @param stregth How much damage the Gun does with his projectile
     * @param delay The reloading Time
     * @param speedFactor How fast the Projectile going when shooting
     * 
     * */
    Gun(std::string name, float strength, float delay, float speedFactor);

    /**
     * @return The strength of the Gun
     * */
    float getStrength();

    /**
     * @return The reloading time of the Gun
     * */
    float getDelay();

    /**
     * @return The speed of the Progectile's Gun
     * */
    float getSpeedFactor();

    /**
     * @brief set the delay of the Gun to a new one
     * 
     * @param delay The new Delay of the gun
     * */
    void setDelay(float delay);

    /**
     * @brief Generate the Projectile associated with this Gun
     * 
     * @param facing The speed direction of the bullet
     * @param source The entity that shoot with the Gun 
     * 
     * */
    virtual Projectile *generateBullet(Direction facing, Entity &source);

private:
    float delay;
    float strength;
    float speedFactor;
};

#endif
