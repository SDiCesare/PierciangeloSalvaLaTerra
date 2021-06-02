#include "Menu.h"

#include <algorithm>  //std::copy
#include <iostream>

Menu::Menu() {
    setDefaultValue();
}

Menu::Menu(unsigned int w, unsigned int h, float x, float y) {
    sprite.setPosition(x, y);
    setDimension(w, h);
    setDefaultValue();
}

Menu::Menu(unsigned int w, unsigned int h, sf::Vector2f position) {
    sprite.setPosition(position);
    setDimension(w, h);
    setDefaultValue();
}

void Menu::setVoices(sf::String menuVoices[], size_t size) {
    if (this->size > 0)
        delete[] voices;

    this->size = size;
    voices = new sf::String[size];  //(std::string*)malloc(size);
    std::copy(menuVoices, menuVoices + size, voices);
}

void Menu::setDisposition(unsigned short c, unsigned short r) {
    columns = c;
    rows = r;
    spriteReady = false;
}

void Menu::setDimension(unsigned int w, unsigned int h) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }
    spriteReady = false;
}

void Menu::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Menu::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

const sf::Sprite& Menu::getSprite() {
    //avoid to elaborate again the same sprite
    if (!spriteReady) {
        background.clear(backgroundColor);
        short k = 0;
        short j = 0;
        float distance = takeDistance();
        sf::Vector2f currTextPos = position;
        std::cout << distance << std::endl;
        for (size_t i = 0; i < size; i++) {
            std::cout << k << " " << j << std::endl;
            std::string str = *(voices + i);
            text.setPosition(currTextPos);
            text.setString(str);
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            background.draw(text);
            currTextPos.x += distance;
            if (++k == columns) {
                if (++j == rows) {
                    break;
                }
                currTextPos.y += 60.f;
                k = 0;
                currTextPos.x = position.x;
            }
        }

        background.display();
        sprite.setTexture(background.getTexture());
        spriteReady = true;
    }
    return sprite;
}

// set the default value, created not to repeat same code in all constructors
void Menu::setDefaultValue() {
    backgroundColor = sf::Color::White;
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf")) {
        // TODO create exception class
        throw 2;
    }
    text.setCharacterSize(16);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    position = sf::Vector2f(0.f, 50.f);
    text.setPosition(0.f, 50.f);
    columns = 0;
    rows = 0;
    sprite.setPosition(0.f, 0.f);
    spriteReady = false;
    size = 0;
}

// calculate distancec between voices
float Menu::takeDistance() {
    //find the max lenght
    size_t max = 0;
    for (size_t i = 0; i < size; i++) {
        size_t dimensionStr = (voices + i)->getSize();

        if (dimensionStr > max)
            max = dimensionStr;
    }

    max *= 1;  //16 -> char size

    size_t w = background.getSize().x;
    std::cout << "w: " << w << "  max:" << max * columns << std::endl;
    size_t rem = w - max * columns;
    std::cout << rem << " " << static_cast<float>(columns + 1) << std::endl;
    float distance = static_cast<float>(rem) / static_cast<float>(columns + 1);
    position.x += distance;
    return distance;
}

Menu::~Menu() {
    delete[] voices;
}