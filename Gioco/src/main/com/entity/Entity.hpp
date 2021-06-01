#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class World;
class Entity
{
public:
    Entity(sf::Sprite *sprite, World *world);
    Entity(World *world);

public:
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();
    virtual void tick();
    void updateSprite();
    sf::Sprite getSprite();
    bool isAlive();
    void move(float x, float y);
    void moveTo(float x, float y);
    World *getWorld();

protected:
    sf::Sprite *sprite;
    sf::Texture *texture;
    bool alive;
    sf::Vector2f facing;
    World *world;
};

#endif