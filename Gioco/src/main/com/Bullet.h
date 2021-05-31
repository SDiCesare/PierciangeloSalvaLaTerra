#ifndef Bullet_h
#define Bullet_h

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Bullet : public Entity
{

public:
    Bullet(Entity *source);
    Bullet(Entity *source, sf::Vector2f speed);
    void tick() override;

private:
    Entity *source;
    sf::Vector2f speed;
};

#endif