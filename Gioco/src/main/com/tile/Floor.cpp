#include "Floor.h"
#include <iostream>

Floor::Floor()
{
    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\tile\\floor.png"))
    {
        std::cout << "Floor Textures not found!"
                  << "\n";
    }
    this->setTexture(texture);
    sf::Sprite *sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    this->setSprite(sprite);
}