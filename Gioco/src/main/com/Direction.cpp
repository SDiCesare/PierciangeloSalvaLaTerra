#include "Direction.hpp"

const Direction Direction::NORTH = Direction(0, sf::Vector2f(0, -1));
const Direction Direction::SOUTH = Direction(1, sf::Vector2f(0, 1));
const Direction Direction::WEST = Direction(2, sf::Vector2f(-1, 0));
const Direction Direction::EAST = Direction(3, sf::Vector2f(1, 0));