#ifndef MapGenerator_hpp
#define MapGenerator_hpp

#include "FireRoom.hpp"
#include "..\\Element.hpp"
#include "..\\Game.hpp"

class MapGenerator
{
public:
    static std::list<Tile *> generateRoom(int nRoom)
    {
        std::list<Tile *> tiles = std::list<Tile *>();
        int connection = Game::getRandInt(1, 4);
        FireRoom room = FireRoom("test");
        if (connection > nRoom)
        {
            connection = nRoom;
        }
        nRoom -= (connection + 1);
        for (int i = 0; i < connection; i++)
        {
            room.makeEntrance(i);
            //appendRoom(tiles, i, nRoom, 0, 0, room);
        }
        for (int i = 0; i < room.getHeight(); i++)
        {
            for (int j = 0; j < room.getWidth(); j++)
            {
                Tile *t = room.getTileFromValue(room.getTiles()[j][i]);
                t->setPosition(32 * i, 32 * j);
                tiles.push_back(t);
            }
        }
        return tiles;
    }

    static void appendRoom(std::list<Tile *> &tiles, int entrance, int nRoom, int xOff, int yOff, Room parent)
    {
        FireRoom room = FireRoom("test");
        room.makeEntrance(entrance);
        int connection = Game::getRandInt(1, 3);
        if (connection > nRoom)
        {
            connection = nRoom;
        }
        nRoom -= (connection + 1);
        if (nRoom < 0)
        {
            nRoom = 0;
        }
        switch (entrance)
        {
        case 0:
        {
            yOff = yOff - (room.getHeight() * 32);
            break;
        }
        case 1:
        {
            xOff = xOff + (parent.getWidth() * 32);
            break;
        }
        case 2:
        {
            yOff = yOff + (parent.getHeight() * 32);
            break;
        }
        case 3:
        {
            xOff = xOff - (room.getWidth() * 32);
            break;
        }
        }
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (count == connection)
            {
                break;
            }
            if (i != entrance)
            {
                room.makeEntrance(i);
                appendRoom(tiles, i, nRoom, xOff, yOff, room);
                count++;
            }
        }
        for (int i = 0; i < room.getWidth(); i++)
        {
            for (int j = 0; j < room.getHeight(); j++)
            {
                Tile *t = room.getTileFromValue(room.getTiles()[i][j]);
                t->setPosition(xOff + (t->getWidth() * i), yOff + (t->getHeight() * j));
                tiles.push_back(t);
            }
        }
    }
};

#endif