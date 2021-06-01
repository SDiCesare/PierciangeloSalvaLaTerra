#include "World.h"
#include "entity\\Enemy.h"
#include <iostream>

World::World() : textbox(100, 100, 100.f, 100.f)
{
    entity = new Enemy(this);
    player = new Player(this);
    entities.push_back(player);
    entities.push_back(entity);
    textbox.setString("prova");
}

void World::tick()
{
    /*int index = 0;
    for (int i = 0; i < entities.size(); i++) {
        Entity* entity = entities.begin()._M_node;
        entity->tick();
        if (!entity->isAlive()) {
            entities.erase(entity);
        }
    }*/
    for (Entity *entity : entities)
    {
        entity->tick();
        if (!entity->isAlive())
        {
            entities.remove(entity);
        }
    }
}

void World::display(sf::RenderWindow &window)
{
    // need to be set in a if clause,
    // use isPrinting() method to know if print is endend
    // window.draw(*textbox.typewriter());
    for (Entity *entity : entities)
    {
        window.draw(entity->getSprite());
    }
}

void World::addEntity(Entity *entity)
{
    if (entities.size() == entities.max_size() - 1)
    {
        std::cout << "Finito Spazio!\n";
        return;
    }
    entities.push_back(entity);
}