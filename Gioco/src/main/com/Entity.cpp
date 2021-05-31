#include "Entity.hpp"

// Entity get a sprite that will be the entity represented in the game
Entity::Entity(sf::Sprite sprite){
    entitySprite = sprite;
}

// get a vector composed by 2 float, it will move the sprite in that position
Entity::setPosition(sf::Vector2f v2f){
    entitySprite.setOrigin(v2f);
}