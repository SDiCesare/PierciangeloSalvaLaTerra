#include "World.h"
#include "entity\\Enemy.h"
#include <iostream>

World::World() : deathTextBox(100, 100, 350.f, 250.f), winTextBox(100, 100, 350.f, 250.f)
{
    entity = new Enemy(this);
    player = new Player(this);
    player->setPosition(sf::Vector2f(300, 100));
    entities.push_back(player);
    entities.push_back(entity);
    deathTextBox.setString("DEFEAT");
    deathTextBox.setCharTime(0.3f * 1000.f);
    winTextBox.setString("WIN");
    winTextBox.setCharTime(0.5f * 1000.f);
}

void World::tick()
{
    if (!player->isAlive())
        return;

    for (Entity *entity : entities)
    {
        entity->tick();
    }

    checkCollision();
}

void World::checkCollision()
{
    for (Entity *entity : entities)
    {
        for (Entity *e : entities)
        {
            if (e != entity && isHitted(*entity, *e))
            {
                entity->onHit(e);
            }
        }
        if (!entity->isAlive())
        {
            entities.remove(entity);
            std::cout << "Removing Entity!\n";
        }
    }
}

bool World::isHitted(Entity e1, Entity e2)
{
    float x1 = e1.getPosition().x;
    float y1 = e1.getPosition().y;
    float width1 = e1.getWidth();
    float height1 = e1.getHeight();

    float x2 = e2.getPosition().x;
    float y2 = e2.getPosition().y;
    float width2 = e2.getWidth();
    float height2 = e2.getHeight();

    if (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2)
    {
        return true;
    }

    return false;
}

void World::display(sf::RenderWindow &window)
{
    // need to be set in a if clause,
    // use isPrinting() method to know if print is endend
    if (!player->isAlive())
    {
        window.draw(*deathTextBox.typewriter());
        return;
    }
    if (!entity->isAlive())
    {
        window.draw(*winTextBox.typewriter());
        return;
    }
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