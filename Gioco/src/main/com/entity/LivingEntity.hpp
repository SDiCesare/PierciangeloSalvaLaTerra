#ifndef LivingEntity_hpp
#define LivingEntity_hpp

#include "Entity.hpp"
#include <SFML\Graphics.hpp>

class LivingEntity : public Entity
{

public:
    /**
     * @brief The Constructor of the class
     * 
     * @param texture The Texture Entity
     * */
    LivingEntity(sf::Texture texture);

    /**
     * @return The Max Health of this Living Entity
     * */
    float getMaxHealth();

    /**
     * @brief Set the Max Health of this Living Entity
     * 
     * @param maxHealth The new Max Health
     * */
    void setMaxHealth(float maxHealth);

    /**
     * @return The Current Health of this Living Entity
     * */
    float getHealth();

    /**
     * @brief Set the Health of this Living Entity
     * 
     * @param health The new Health
     * */
    void setHealth(float health);

    /**
     * @return The Max Speed of this Living Entity
     * */
    sf::Vector2f getMaxSpeed();

    /**
     * @brief Set the Max Speed of this Living Entity
     * 
     * @param maxSpeed The new Max Speed
     * */
    void setMaxSpeed(sf::Vector2f maxSpeed);

protected:
    /**
     * @brief Called from the Constructor of LivingEntity. Override to set-up the stats
     * */
    virtual void entityInit();

private:
    sf::Vector2f maxSpeed;
    float health;
    float maxHealth;
};

#endif