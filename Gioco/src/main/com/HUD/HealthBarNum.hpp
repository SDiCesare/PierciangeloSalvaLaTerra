#ifndef HealthBarNum_h
#define HealthBarNum_h
#include "HealthBar.hpp"

class HealthBarNum : public HealthBar {
    public:
        HealthBarNum();
        HealthBarNum(int maxHealth, const sf::Vector2f& size);
        bool takeDamage(int damage) override;
        void setHealthStat(int health, int maxHealth) override;
        void setHealth(int health) override;
        void setMaxHealth(int maxHealth, bool propotionalHealth = true) override;
        void setBar(const sf::Vector2f& size) override;
        void setFont(sf::Font& font);

    private:
        sf::Font font;
        sf::Text healthNum;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateNum();
};

#endif