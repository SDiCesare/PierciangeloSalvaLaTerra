#ifndef Bullet_h
#define Bullet_h

#include "Entity.hpp"
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

private:
    Entity *source;
    sf::Vector2f speed;
    float strength;
};

#endif
