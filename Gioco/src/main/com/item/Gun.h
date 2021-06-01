#ifndef Gun_h
#define Gun_h

#include "Item.h"

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
