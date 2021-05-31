#include "Entity.hpp"

Entity::Entity(sf::Sprite sprite){
    entitySprite = sprite;
}

Entity::setPosition(sf::Vector2f v2f){
    entitySprite.setOrigin(v2f);
}