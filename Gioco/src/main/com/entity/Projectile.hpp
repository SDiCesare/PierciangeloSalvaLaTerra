#ifndef Projectile_hpp
#define Projectile_hpp

#include "LivingEntity.hpp"
#include "..\\Direction.hpp"

class Projectile : public Entity
{
public:
    Projectile(std::string name, Direction dir, float scale, Entity &source);
    virtual void tick() override;
    virtual void onHit(Entity &entity) override;
    virtual void onHit(Tile &tile) override;

protected:
    sf::Vector2f speed;
    float damage;
    Entity *source;

private:
    float clock;
};

#endif