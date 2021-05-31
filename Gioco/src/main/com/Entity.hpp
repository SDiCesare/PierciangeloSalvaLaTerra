#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    Entity(sf::Sprite);
    Entity();

public:
    void setPosition(sf::Vector2f);
    void tick();
    sf::Sprite getSprite();

protected:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif