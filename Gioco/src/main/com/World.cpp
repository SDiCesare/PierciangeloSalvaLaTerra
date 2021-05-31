#include "World.h"
#include "Entity.hpp"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void World::setup()
{
    entity = new Enemy();
    player = new Player();
}

void World::tick()
{
    entity->tick();
    player->tick();
}

void World::display(sf::RenderWindow &window)
{
    window.draw(entity->getSprite());
    window.draw(player->getSprite());
}