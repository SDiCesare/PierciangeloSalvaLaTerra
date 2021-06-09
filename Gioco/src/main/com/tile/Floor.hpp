#ifndef Floor_hpp
#define Floor_hpp

#include "Tile.hpp"

class Floor : public Tile
{
public:
    Floor(std::string name);
    bool isSolid() override;
};

#endif