#ifndef Gun_hpp
#define Gun_hpp

#include "Item.hpp"

class Gun : public Item
{
public:
    Gun(std::string name, float strength, float delay, float speedFactor);
    float getStrength();
    float getDelay();
    float getSpeedFactor();

private:
    float delay;
    float strength;
    float speedFactor;
};

#endif
