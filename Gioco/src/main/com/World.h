#include "Entity.hpp"
#include "Player.h"
#include <SFML/Graphics.hpp>

class World
{
public:
    Entity *entity;
    Player *player;
    void tick();
    void setup();
    void display(sf::RenderWindow &window);
};