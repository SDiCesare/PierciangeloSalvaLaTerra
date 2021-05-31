#include "World.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

World::World() {
    entity = new Enemy();
    player = new Player();
    entities.push_back(player);
    entities.push_back(entity);
}

void World::tick()
{
    int index = 0;
    for (Entity* entity : entities) {
        entity->tick();
        if (!entity->isAlive()) {
            entities.erase(entities.begin() + index);
        }
        index++;
    }
}

void World::display(sf::RenderWindow &window)
{
    for (Entity* entity : entities) {
        window.draw(entity->getSprite());
    }
}


void World::addEntity(Entity *entity) {
    entities.push_back(entity);
}