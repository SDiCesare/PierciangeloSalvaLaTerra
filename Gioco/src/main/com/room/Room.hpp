#ifndef Room_hpp
#define Room_hpp

#include <string>
#include <map>
#include "..\\tile\\Tile.hpp"
#include "..\\Element.hpp"
#include <SFML\\Graphics.hpp>

class Room
{
public:
    Room(std::string roomFile, Element e);
    virtual Tile *getTileFromValue(int index);
    int **getTiles();
    int getWidth();
    int getHeight();
    void makeEntrance(int index);
    void print();

protected:
    void load(std::string room);

protected:
    sf::Texture tileSheet;
    sf::Texture roomTexture;
    Element element;

private:
    int width;
    int height;
    int **tiles;
};

#endif