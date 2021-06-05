#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#include "..\\Direction.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{

public:
    /**
    * @brief Create an Entity with a representative Texture
    * 
    * @param texture The Texture with size [(nX4n) or (n*n)]
    * */
    Entity(sf::Texture texture);

    /**
     * @brief Called every tick from the World that contains this Entity
     * */
    virtual void tick();

    /**
     * @brief Called When the Entity hits another one
     * 
     * @param entity The Entity that this one hits
     * */
    virtual void onHit(Entity &entity);

    /**
     * @brief Set the position of the Entity at x, y
     * 
     * @param x The X coordinate
     * @param y The Y coordinate
     * */
    void setPosition(float x, float y);

    /**
     * @return The current position of the Entity
     * */
    sf::Vector2f getPosition();

    /**
     * @brief Move the Entity of (x, y)
     * 
     * @param x The movement on X axis
     * @param y The movement on Y axis
     * */
    void move(float x, float y);

    /**
     * @brief Move the Entity of vector (move)
     * 
     * @param move The movement vector
     * */
    void move(sf::Vector2f move);

    /**
     * @brief Set flag alive of this Entity
     * 
     * @param alive
     * */
    void setAlive(bool alive);

    /**
     * @return If thecurrent Entity is alive
     * */
    bool isAlive();

    /**
     * @return The Entity width
     * */
    int getWidth();

    /**
     * @return The Entity Height
     * */
    int getHeight();

private:
    /**
     * @brief Draw the Entity on the screen based on (texture) & (texturebox)
     * 
     * @param target The target drawed by the window
     * @param states The render states of the window
     * */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /**
     * @brief Update the texture to the facing direction (Only if the texture's size is [nx4n])
     * 
     * @param dir The entity direction
     * */
    void updateFacing(Direction dir);

protected:
    sf::Texture texture;

private:
    sf::VertexArray textureBox;
    float width;
    float height;
    bool alive;
};

#endif