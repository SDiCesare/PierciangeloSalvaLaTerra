#ifndef Direction_hpp
#define Direction_hpp

#include <SFML\Graphics.hpp>

class Direction
{

private:
    /**
     * @brief Default and Private Constructor for the Direction
     * 
     * @param ordinal The Ordinal Value for a Direction [NORTH, SOUTH, WEST, EAST]
     * @param normal A Rapresentative Vector for the Direction
     * */
    Direction(int ordinal, sf::Vector2f normal)
    {
        this->normal = normal;
        this->ordinal = ordinal;
    }

public:
    /**
     * @return The Rapresentative vector of the Direction
     * */
    sf::Vector2f getNormal() const { return normal; }

    /**
     * @return The Ordinal Value for the Direction [NORTH, SOUTH, WEST, EAST]
     * */
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