#include "Rock.hpp"
#include <iostream>

Rock::Rock() : Tile("rock")
{
}

bool Rock::isBreakableTo(Entity &entity)
{
    //TODO Break Rock with some stuff (explosion and so on)
    return false;
}

void Rock::onBreak(Entity &entity)
{
}