#include "Floor.hpp"

Floor::Floor(std::string name) : Tile(name)
{
}

bool Floor::isSolid()
{
    return false;
}