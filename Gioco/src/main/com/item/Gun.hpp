#ifndef Gun_hpp
#define Gun_hpp

#include "Item.hpp"
#include "..\\entity\\Bullet.hpp"

class Gun : public Item
{
public:
    Gun(std::string name, float strength, float delay, float speedFactor);
    float getStrength();
    float getDelay();
    void setDelay(float delay);
    float getSpeedFactor();
    virtual Bullet *generateBullet(Direction facing, Entity &source);

private:
    float delay;
    float strength;
    float speedFactor;
};

#endif
