#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(sf::Sprite);
    void setPosition(sf::Vector2f);
    void tick();
    sf::Sprite getSprite();

protected:
    sf::Sprite sprite;
};

#endif