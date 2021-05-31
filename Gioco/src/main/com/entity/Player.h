#ifndef Player_h
#define Player_h

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
public:
    Player();
    void tick() override;

private:
    void move();

private:
    sf::Vector2f speed;
};

#endif