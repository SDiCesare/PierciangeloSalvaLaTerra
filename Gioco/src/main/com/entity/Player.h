#ifndef Player_h
#define Player_h

#include "Entity.hpp"
#include "..\\item\\Gun.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>

class World;
class Player : public Entity
{
public:
    Player(World *world);
    void tick() override;
    Bullet *shoot();
    sf::Vector2f getSpeed();
    void onHit(Entity *entity) override;

private:
    sf::Vector2f speed;
    Gun *gun;
    float lastShoot;
};

#endif