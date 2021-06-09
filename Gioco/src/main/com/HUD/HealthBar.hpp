#ifndef HealthBar_hpp
#define HealthBar_hpp

#include <SFML/Graphics.hpp>

/**
 * @class HealthBar
 * 
 * HealthBar is a class that will keep health point of the player (or whatever you want)
 * and will display it on the window.
 * It's a subclass of sf::Drawable and sf::Transformable
 */
class HealthBar : public sf::Drawable, public sf::Transformable {
   public:
    /**
     * @brief Default constructor
     * 
     * Create an empty HealthBar with health and max health equal to 0
     */
    HealthBar();

    /**
     * @brief Construct a Health bar ready to use
     * 
     * The health and the max health will have the value past in the maxHealth
     * parameter
     * 
     * @param maxHealth The max health and the initial health
     * @param size The size of the bar
     */
    HealthBar(int maxHealth, const sf::Vector2f& size);

    /**
     * @brief Update the health based on the damage suffered by the player
     * 
     * If the health reach the 0 the method will return false, 
     * the value can be negative to increment the health
     * @param damage The number of health point to remove
     * @return If the player is alive
     */
    virtual bool takeDamage(int damage);

    /**
     * @brief Set the size of the bar
     * 
     * The size referes to the size with max health
     * @param size The size of the bar
     */
    virtual void setBar(const sf::Vector2f& size);

    /**
     * @brief Update the player's current health
     * 
     * If the value is below 0 will be set to 0
     * 
     * @param health The player'scurrent health
     */
    virtual void setHealth(int health);

    /**
     * @brief Update the player's max health
     * 
     * If the value is below 0 will be set to 0,
     * if the previous value of max health was 0 will be set the max health value
     * to current health
     * 
     * @param maxHealth The player's max health
     * @param propotionalHealth If the current heatlh needs to be proportional to new max health
     */
    virtual void setMaxHealth(int maxHealth, bool propotionalHealth = true);

    /**
     * @brief Update the current health and the max health
     * 
     * If one of the value is below 0 it will be set to 0,
     * if the health is greater than max health it will set to max health value
     * @param health The player'scurrent health
     * @param maxHealth The player's max health
     */
    virtual void setHealthStat(int health, int maxHealth);

    /**
     * @brief Get the the player's current health
     * 
     * @return The player's current health
     */
    int getHealth();

    /**
     * @brief Get the the player's max health
     * 
     * @return The player's max health
     */
    int getMaxHealth();

    /**
     * @brief Check if the player is alive
     * 
     * @return If the player is alive
     */
    bool isAlive();

   protected:
    int maxHealth;
    int health;
    sf::RectangleShape rect;
    sf::Texture textureHealth;
    sf::Vector2f maxSize;
    void renderHealthBar();

   private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif