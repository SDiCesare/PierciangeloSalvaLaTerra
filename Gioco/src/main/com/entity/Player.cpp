#include "Player.h"
#include <iostream>

Player::Player(World *world) : Entity(world)
{
    texture = new sf::Texture();
    if (!texture->loadFromFile("..\\resources\\textures\\entity\\player.png"))
    {
        std::cout << "Bullet Textures not found!"
                  << "\n";
    }
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
    sprite->setPosition(0, 0);
    speed.x = 3;
    speed.y = 3;
    gun = new Gun("Gun", 1.5f, 1.f, 3.5f);
    lastShoot = 0;
}

void Player::tick()
{
    if (lastShoot > 0)
    {
        lastShoot -= 0.1f;
    }
}

Bullet *Player::shoot()
{
    if (lastShoot > 0)
    {
        return nullptr;
    }
    else
    {
        Bullet *bullet = new Bullet(this, this->facing * this->gun->getSpeedFactor());
        bullet->setStrength(this->gun->getStrength());
        bullet->setPosition(this->sprite->getPosition());
        lastShoot = this->gun->getDelay();
        return bullet;
    }
}

sf::Vector2f Player::getSpeed()
{
    return this->speed;
}