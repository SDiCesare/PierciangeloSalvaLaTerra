#ifndef HealthBarNum_h
#define HealthBarNum_h
#include "HealthBar.hpp"

/**
 * @class HealthBarNum
 * 
 * HealthBarNum is a class that will keep health point of the player (or whatever you want)
 * and will display it on the window with the addition of 2 numbers representing the current
 * health and the max health.
 * It's a subclass of HealthBar
 * 
 * @see HealthBar
 */
class HealthBarNum : public HealthBar {
    public:
        /**
         * @brief Default constructor
         * 
         * Create an empty HealthBar with health and max health equal to 0
         * 
         * @see #setBar, #setFont, #setHealthStat
         */
        HealthBarNum();

        /**
         * @brief Construct a Health bar ready to use
         * 
         * The health and the max health will have the value past in the maxHealth
         * parameter, the numbers will use the past font
         * 
         * @param maxHealth The value to set on current health and amx health
         * @param size The bar size
         * @param font The font used by numbers
         */
        HealthBarNum(int maxHealth, const sf::Vector2f& size, const sf::Font& font);

        /**
         * @brief Update the health based on the damage suffered by the player
         * 
         * If the health reach the 0 the method will return false, 
         * the value can be negative to increment the health
         * 
         * @param damage The number of health point to remove
         * @return If the player is alive
         */
        bool takeDamage(int damage) override;

        /**
         * @brief Update the current health and the max health
         * 
         * If one of the value is below 0 it will be set to 0,
         * if the health is greater than max health it will set to max health value
         * @param health The player'scurrent health
         * @param maxHealth The player's max health
         */
        void setHealthStat(int health, int maxHealth) override;

        /**
         * @brief Update the player's current health
         * 
         * If the value is below 0 will be set to 0
         * 
         * @param health The player'scurrent health
         */
        void setHealth(int health) override;

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
        void setMaxHealth(int maxHealth, bool propotionalHealth = true) override;

        /**
         * @brief Set the size of the bar
         * 
         * The size referes to the size with max health
         * @param size The size of the bar
         */
        void setBar(const sf::Vector2f& size) override;

        /**
         * @brief Set the font used by numbers
         * 
         * @param font The font to use
         */
        void setFont(const sf::Font& font);

    private:
        sf::Font font;
        sf::Text healthNum;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateNum();
};

#endif