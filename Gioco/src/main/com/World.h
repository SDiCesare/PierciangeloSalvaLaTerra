#ifndef World_h
#define World_h

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <list>

class World
{
public:
    World();
    Entity *entity;
    Player *player;
    void tick();
    void setup();
    void display(sf::RenderWindow &window);
    void addEntity(Entity *entity);

private:
    std::list<Entity*> entities;
};

#endif