#include "World.h"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

void World::setup()
{
    sf::Texture texture;
    texture.loadFromFile("resources\\textures\\entity\\entity.png");
    // Create a sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    entity = new Entity(sprite);
}

void World::tick()
{
    entity->tick();
}

void World::display(sf::RenderWindow *window) {
    window->draw(entity->getSprite());
}