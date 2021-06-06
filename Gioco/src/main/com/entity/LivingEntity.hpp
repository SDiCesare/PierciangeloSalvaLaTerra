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
     * @param name The Entity Name
     * */
    LivingEntity(std::string name);

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

    /**
     * @return If this entity is invulnerable to damage
     * */
    virtual bool isInvulnerable();

    /**
     * @brief Damage the LivingEntity by the amount
     * 
     * @param amount The Damage amount
     * */
    virtual void damage(float amount);

private:
    sf::Vector2f maxSpeed;
    float health;
    float maxHealth;
};

#endif