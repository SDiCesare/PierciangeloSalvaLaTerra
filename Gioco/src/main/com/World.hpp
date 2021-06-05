#ifndef World_hpp
#define World_hpp

#include "entity\Player.hpp"
#include "tile\Tile.hpp"
#include "HUD\HealthBarNum.hpp"
#include "HUD\HealthBar.hpp"
#include "TextBox.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include "Menu.hpp"

//class Game;

class World
{
public:
    World();
    Player *player;
    void tick();
    void setup();
    void display(sf::RenderWindow &window);
    void addEntity(Entity &entity);
    bool collideRect(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
    void checkCollision();
    bool canMove(Entity &e, float x, float y, float width, float height);
    bool isHitted(Entity e1, Entity e2);
    bool end;

private:
    void generateWorld();

private:
    std::list<Entity *> entities;
    std::list<Tile *> tiles;
    TextBox deathTextBox;
    TextBox winTextBox;
    sf::Font font;
    Menu menu;
    HealthBarNum healthBar;
    int counter; //for debugging, it counts how many time the loop was executed
};

#endif