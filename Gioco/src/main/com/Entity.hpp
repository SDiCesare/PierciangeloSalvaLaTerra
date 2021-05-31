#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(sf::Sprite);
    void setPosition(sf::Vector2f);

protected:
    sf::Sprite entitySprite;
};

#endif