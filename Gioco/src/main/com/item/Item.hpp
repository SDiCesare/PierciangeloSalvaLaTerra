#ifndef Item_hpp
#define Item_hpp
#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class Item
 * 
 * Item is a class that represent items on the screen using SFML, it can be extended
 * to other class so as to help their development.
 * It's a subclass of sf::Drawable and sf::Transformable
 * 
 * @see sf::Drawable, sf::Transformable
 */
class Item : public sf::Transformable, public sf::Drawable {
   public:
   /**
    * @brief Default constructor
    * 
    * Create an empty Item
    */
    Item();

    /**
     * @brief Construct an item ready to use
     * 
     * The name will be used as item name and as name of the png to load as texture
     * to the item, if you want to use a different item name from the png name
     * look to the constructor with 2 parameters.
     * The png file must be in item folder
     * 
     * @param name The item name
     * @see #Item(std::string name, std::string fileName)
     */
    Item(std::string name);

    /**
     * @brief Construct an item ready to use
     * 
     * The png file must be in item folder
     * @param name The item name
     * @param fileName The png name to load as texture
     */
    Item(std::string name, std::string fileName);

    /**
     * @brief Set the item name
     * 
     * Will not change the item texture
     * @param name The item name
     */
    virtual void setName(std::string name);

    /**
     * @brief Get the item name
     * 
     * @return The item name
     */
    virtual const std::string& getName();

    /**
     * @brief Set the item texture from png
     * 
     * The png file must be in item folder
     * @param fileName The png name
     */
    virtual void setTexture(std::string fileName);

    /**
     * @brief Get the item texture
     * 
     * @return The item texture
     */
    virtual sf::Texture getTexture();

    /**
     * @brief Set the item texture
     * 
     * @param texture The texture to set
     */
    virtual void copyTexture(const sf::Texture& texture);

    /**
     * @brief Get the item size
     * 
     * The item size dependes from texture size,
     * the returned size isn't affected by scaling and other transformation
     * 
     * @return The item size
     */
    virtual const sf::Vector2f getSize();

   protected:
    sf::Texture texture;
    std::string name;
    sf::VertexArray textureBox;

   private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif