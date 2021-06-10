#include "HealthBarNum.hpp"

#include <string>

HealthBarNum::HealthBarNum() {
    healthNum.setCharacterSize(16);
}

HealthBarNum::HealthBarNum(int maxHealth, const sf::Vector2f& size, const sf::Font& font) : HealthBar(maxHealth, size) {
    healthNum.setCharacterSize(16);
    healthNum.setFont(font);
    updateNum();
}

void HealthBarNum::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Transform t = getTransform();
    target.draw(rect, t);
    target.draw(healthNum, t);
}

bool HealthBarNum::takeDamage(int damage) {
    bool ret = HealthBar::takeDamage(damage);
    updateNum();
    return ret;
}

void HealthBarNum::setHealthStat(int health, int maxHealth){
    HealthBar::setHealthStat(health, maxHealth);
    updateNum();
}

void HealthBarNum::setHealth(int health){
    HealthBar::setHealth(health);
    updateNum();
}

void HealthBarNum::setMaxHealth(int maxHealth, bool propotionalHealth){
    HealthBar::setMaxHealth(maxHealth);
    updateNum();
}

void HealthBarNum::setBar(const sf::Vector2f& size){
    HealthBar::setBar(size);
    healthNum.setPosition(rect.getLocalBounds().width - healthNum.getLocalBounds().width, 0.f);
}

void HealthBarNum::setFont(const sf::Font& font){
    healthNum.setFont(font);
}

void HealthBarNum::updateNum() {
    healthNum.setString(std::to_string(health) + "/" + std::to_string(maxHealth));
}