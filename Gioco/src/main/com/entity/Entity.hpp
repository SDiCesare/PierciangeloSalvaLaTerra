#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

#include "..\\tile\\Tile.h"

class World;
class Entity
{
public:
    Entity(sf::Sprite *sprite, World *world);
    Entity(World *world);

public:
    void setPos(sf::Vector2f);
    void setPos(float x, float y);
    sf::Vector2f getPos();
    virtual void tick();
    void updateSprite();
    sf::Sprite getSprite();
    bool isAlive();
    void move(float x, float y);
    void moveTo(float x, float y);
    World *getWorld();
    virtual void onHit(Entity *entity);
    virtual void onHit(Tile *tile);
    int getWidth();
    int getHeight();
    float getHealth();
    void setHealth(float health);

protected:
    void setupSize(int width, int height);

protected:
    sf::Sprite *sprite;
    sf::Texture *texture;
    bool alive;
    sf::Vector2f facing;
    World *world;
    float health;

private:
    int width;
    int height;
};

#endif