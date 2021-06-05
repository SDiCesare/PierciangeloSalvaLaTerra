#ifndef Direction_hpp
#define Direction_hpp

#include <SFML\Graphics.hpp>

class Direction
{

private:
    Direction(int ordinal, sf::Vector2f normal)
    {
        this->normal = normal;
        this->ordinal = ordinal;
    }

public:
    sf::Vector2f getNormal() const { return normal; }
    int getOrdinal() const { return ordinal; }

private:
    sf::Vector2f normal;
    int ordinal;

public:
    static const Direction NORTH;
    static const Direction SOUTH;
    static const Direction EAST;
    static const Direction WEST;
};

#endif