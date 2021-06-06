#ifndef Tile_hpp
#define Tile_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "..\\ResourceHandler.hpp"

class Entity;
class Tile : public sf::Drawable, public sf::Transformable
{

public:
    /**
    * @brief Create a Tile with a representative Texture
    * 
    * @param name The Tile name
    * */
    Tile(std::string name);

    /**
     * @return true if this tile has collision, false otherwise
     * */
    virtual bool isSolid();

    /**
     * @brief Set the position of the Tile at x, y
     * 
     * @param x The X coordinate
     * @param y The Y coordinate
     * */
    void setPosition(float x, float y);

    /**
     * @return The current position of the Tile
     * */
    sf::Vector2f getPosition();

    /**
     * @return The Tile width
     * */
    int getWidth();

    /**
     * @return The Tile height
     * */
    int getHeight();

    /**
     * @param entity The entity that trye
     * @return true If this tile can be broken by the entity
     * */
    virtual bool isBreakableTo(Entity &entity);

    /**
     * @brief called when the tile is break by an entity
     * @param entity The Entity that broke this tile
     * */
    virtual void onBreak(Entity &entity);

private:
    /**
     * @brief Draw the Tile on the screen based on (texture) & (texturebox)
     * 
     * @param target The target drawed by the window
     * @param states The render states of the window
     * */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
    sf::Texture texture;

private:
    sf::VertexArray textureBox;
    float width;
    float height;
};

#endif