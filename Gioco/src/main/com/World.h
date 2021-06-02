#ifndef World_h
#define World_h

#include "entity\\Player.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Menu.h"

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
    void checkCollision();
    bool isHitted(Entity e1, Entity e2);

private:
    std::list<Entity *> entities;
    TextBox deathTextBox;
    TextBox winTextBox;
    Menu menu;
    size_t* temp;
};

#endif