#include "HealthBar.hpp"

HealthBar::HealthBar() : textureBox(sf::TriangleStrip, 4){
    maxHealth = 0;
    health = 0;
}

HealthBar::HealthBar(int health, const sf::Vector2f& size) : textureBox(sf::TriangleStrip, 4){
    if(health < 0)
        maxHealth = 0;
    else
        maxHealth = health;
    this->health = maxHealth;
    this->setBar(size);
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &textureHealth;
    target.draw(textureBox, states);
}

bool HealthBar::takeDamage(int damage) {
    health -= damage;
    bool ret = true;
    if (health < 0) {
        health = 0;
        ret = false;
    } else if (health > maxHealth) {
        health = maxHealth;
    }
    renderHealthBar();
    return ret;
}

int HealthBar::getHealth() {
    return health;
}

void HealthBar::setHealth(int health) {
    if (health < 0)
        health = 0;

    this->health = health;
    if (maxHealth > 0) {
        if (health > maxHealth)
            this->health = maxHealth;
        renderHealthBar();
    }
}

void HealthBar::setMaxHealth(int maxHealth, bool propHealth) {
    if (maxHealth < 0)
        maxHealth = 0;

    if (this->maxHealth > 0) {
        if (propHealth) {
            health = maxHealth * health / this->maxHealth;
        } else if (maxHealth < health) {
            health = maxHealth;
        }
    } else {
        health = maxHealth;
    }

    this->maxHealth = maxHealth;

    renderHealthBar();
}

int HealthBar::getMaxHealth() {
    return maxHealth;
}

bool HealthBar::isAlive() {
    return health > 0;
}

void HealthBar::setHealthStat(int health, int maxHealth) {
    if (maxHealth > 0) {
        this->maxHealth = maxHealth;
    } else {
        this->maxHealth = 0;
    }

    if (health < 0)
        health = 0;

    if (maxHealth > health)
        this->health = health;
    else
        this->health = maxHealth;

    renderHealthBar();
}

void HealthBar::renderHealthBar() {
    unsigned int sizeBar = 0;
    if (maxHealth > 0)
        sizeBar = health * static_cast<int>(maxSize.x) / maxHealth;

    // rect.setSize(sf::Vector2f(static_cast<float>(sizeBar), maxSize.y));
    // rect.setTextureRect(sf::IntRect(0, 0, sizeBar, 30));
    float sizeB = static_cast<float>(sizeBar);
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0,  maxSize.y);
    textureBox[2].position = sf::Vector2f(sizeB, 0);
    textureBox[3].position = sf::Vector2f(sizeB,  maxSize.y);
    textureBox[0].texCoords = sf::Vector2f(0, 0);
    textureBox[1].texCoords = sf::Vector2f(0, maxSize.y);;
    textureBox[2].texCoords = sf::Vector2f(sizeB, 0);
    textureBox[3].texCoords = sf::Vector2f(sizeB, maxSize.y);
}

void HealthBar::setBar(const sf::Vector2f& size) {
    maxSize = size;

    //generate rectangle, use 2 triangles because quad is deprecated
    sf::VertexArray tri1(sf::Triangles, 3);
    tri1[0].position = sf::Vector2f(0.f, 0.f);
    tri1[1].position = sf::Vector2f(size.x, 0.f);
    tri1[2].position = size;
    tri1[0].color = sf::Color::Yellow;
    tri1[1].color = sf::Color::Red;
    tri1[2].color = sf::Color::Red;
    sf::VertexArray tri2(sf::Triangles, 3);
    tri2[0].position = sf::Vector2f(0.f, 0.f);
    tri2[1].position = sf::Vector2f(0.f, size.y);
    tri2[2].position = size;
    tri2[0].color = sf::Color::Yellow;
    tri2[1].color = sf::Color::Yellow;
    tri2[2].color = sf::Color::Red;

    sf::RenderTexture rend;
    if (!rend.create(static_cast<int>(size.x), static_cast<int>(size.y)))
        throw 1;
    rend.draw(tri1);
    rend.draw(tri2);

    textureHealth = rend.getTexture();
    //set the dimension
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, size.y);
    textureBox[2].position = sf::Vector2f(size.x, 0);
    textureBox[3].position = size;
    //set the texture position
    textureBox[0].texCoords = sf::Vector2f(0, 0);
    textureBox[1].texCoords = sf::Vector2f(0, size.y);;
    textureBox[2].texCoords = sf::Vector2f(size.x, 0);
    textureBox[3].texCoords = size;
    renderHealthBar();
}