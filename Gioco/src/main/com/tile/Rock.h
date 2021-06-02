#ifndef Rock_h
#define Rock_h

#include "Tile.h"

class Rock : public Tile
{
public:
    Rock();
    bool isAir() override;
};

#endif