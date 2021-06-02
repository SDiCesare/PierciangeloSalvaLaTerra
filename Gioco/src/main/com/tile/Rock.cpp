#include "Rock.h"
#include <iostream>

Rock::Rock()
{
    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\tile\\rock.png"))
    {
        std::cout << "Rock Textures not found!"
                  << "\n";
    }
    this->setTexture(texture);
    sf::Sprite *sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    this->setSprite(sprite);
}

bool Rock::isAir()
{
    return false;
}