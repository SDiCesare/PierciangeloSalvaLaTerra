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
    virtual void onHit(Entity *entity);
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