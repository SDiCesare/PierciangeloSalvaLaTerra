#ifndef FireRoom_hpp
#define FireRoom_hpp

#include "Room.hpp"

class FireRoom : public Room
{
public:
    FireRoom(std::string roomName);
    Tile *getTileFromValue(int index) override;
};

#endif