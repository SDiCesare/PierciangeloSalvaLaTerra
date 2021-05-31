#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>

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
    std::vector<Entity*> entities;
};