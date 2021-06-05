#ifndef World_h
#define World_h

#include "entity\Player.hpp"
#include "tile\Tile.h"
#include "hud\HealthBar.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Menu.h"

//class Game;

class World
{
public:
    World();
    Player *player;
    void tick();
    void setup();
    void display(sf::RenderWindow &window);
    void addEntity(Entity *entity);
    bool collideRect(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
    void checkCollision();
    bool canMove(Entity *e, float x, float y, float width, float height);
    bool isHitted(Entity e1, Entity e2);
    bool end;

private:
    void generateWorld();

private:
    std::list<Entity *> entities;
    std::list<Tile *> tiles;
    TextBox deathTextBox;
    TextBox winTextBox;
    Menu menu;
    HealthBar healthBar;
    int counter; //for debugging, it counts how many time the loop was executed
};

#endif