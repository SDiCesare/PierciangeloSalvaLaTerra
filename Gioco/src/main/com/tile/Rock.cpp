#include "Rock.hpp"
#include <iostream>
#include "..\\ResourceHandler.hpp"

Rock::Rock() : Tile(ResourceHandler::ROCK_TEXTURE)
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