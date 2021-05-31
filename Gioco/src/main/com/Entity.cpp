#include "Entity.hpp"
#include <SFML/Graphics.hpp>

// Entity get a sprite that will be the entity represented in the game
Entity::Entity(sf::Sprite sprite){
    sprite = sprite;
}

// get a vector composed by 2 float, it will move the sprite in that position
void Entity::setPosition(sf::Vector2f v2f){
    sprite.setOrigin(v2f);
}

void Entity::tick() {
    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    sprite.setPosition(x + 0.1, y + 0.1);
}

sf::Sprite Entity::getSprite() {
    return this->sprite;
}