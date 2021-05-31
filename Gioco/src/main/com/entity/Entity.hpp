#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(sf::Sprite *sprite);
    Entity();

public:
    void setPosition(sf::Vector2f);
    virtual void tick();
    sf::Sprite getSprite();
    bool isAlive();

protected:
    sf::Sprite *sprite;
    sf::Texture *texture;
    bool alive;
};

#endif