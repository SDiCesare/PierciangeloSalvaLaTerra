#ifndef Tile_h
#define Tile_h

#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile();

public:
    sf::Vector2f getPos();
    void setPos(sf::Vector2f pos);
    void setPos(float x, float y);
    sf::Sprite getSprite();
    void setSprite(sf::Sprite *sprite);
    sf::Texture getTexture();
    void setTexture(sf::Texture *texture);
    virtual bool isAir();

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
};

#endif