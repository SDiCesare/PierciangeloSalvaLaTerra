#include "FireRoom.hpp"
#include "..\\Element.hpp"
#include "..\\tile\\Floor.hpp"

FireRoom::FireRoom(std::string fileName) : Room(fileName, Element::FIRE)
{
    std::string tileSetName = "tileset\\" + element.getName();
}

Tile *FireRoom::getTileFromValue(int index)
{
    int size = 32;
    std::string tileSetName = "tileset\\" + element.getName();
    switch (index)
    {
    case 0:
    {
        Tile *t = new Floor(tileSetName);
        t->setBounds(size, 0, size, size);
        return t;
    }
    case 1:
    {
        Tile *t = new Tile(tileSetName);
        t->setBounds(0, 0, size, size);
        return t;
    }
    default:
    {
        Tile *t = new Floor(tileSetName);
        t->setBounds(size, 0, size, size);
        return t;
    }
    }
}