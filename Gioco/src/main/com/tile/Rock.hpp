#ifndef Rock_h
#define Rock_h

#include "Tile.hpp"

class Rock : public Tile
{
public:
    Rock();
    bool isBreakableTo(Entity &entity) override;
    void onBreak(Entity &entity) override;
};

#endif