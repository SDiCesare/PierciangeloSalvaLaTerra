#include "Projectile.hpp"
#include "LivingEntity.hpp"

Projectile::Projectile(std::string name, Direction dir, float scale, Entity &source) : Entity("projectile\\" + name)
{
    this->speed = sf::Vector2f(dir.getNormal().x * scale, dir.getNormal().y * scale);
    this->source = &source;
}

void Projectile::tick()
{
    this->move(this->speed);
}

void Projectile::onHit(Entity &entity)
{
    if (&entity == this->source)
        return;
    LivingEntity *e = dynamic_cast<LivingEntity *>(&entity);
    if (e != NULL && !e->isInvulnerable())
    {
        e->damage(this->damage);
        this->setAlive(false);
    }
}

void Projectile::onHit(Tile &tile)
{
    this->setAlive(false);
    if (tile.isBreakableTo(*this))
    {
        tile.onBreak(*this);
    }
}