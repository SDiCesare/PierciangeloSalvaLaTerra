#include "Player.h"
#include <iostream>

Player::Player()
{
    if (!texture.loadFromFile("..\\resources\\textures\\entity\\player.png"))
    {
        std::cout << "Player Textures not found!"
                  << "\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    speed.x = 3;
    speed.y = 3;
}

void Player::tick()
{
    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x -= speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x += speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y -= speed.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y += speed.y;
    }
    sprite.setPosition(x, y);
}