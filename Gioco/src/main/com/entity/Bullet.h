#ifndef Bullet_h
#define Bullet_h

#include "Entity.hpp"
#include "..\\tile\Tile.h"
#include <SFML/Graphics.hpp>

class World;
class Bullet : public Entity
{

public:
    Bullet(Entity *source);
    Bullet(Entity *source, sf::Vector2f speed);
    void tick() override;
    void setStrength(float strength);
    void onHit(Entity *entity) override;
    void onHit(Tile *tile) override;

private:
    Entity *source;
    sf::Vector2f speed;
    float strength;
};

#endif
