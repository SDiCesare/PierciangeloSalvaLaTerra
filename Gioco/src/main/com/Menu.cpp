#include "Menu.h"

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

// @brief set the default value, created not to repeat same code in all constructors
void Menu::setDefaultValue() {
    backgroundColor = sf::Color::White;
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf")) {
        // TODO create exception class
        throw 2;
    }
    text.setCharacterSize(16);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    position = sf::Vector2f(0.f, 0.f);
    text.setPosition(0.f, 0.f);
    columns = 0;
    rows = 0;
    sprite.setPosition(0.f, 0.f);
    spriteReady = false;
}

void Menu::setVoices(std::vector<sf::String> menuVoices) {
    voices = menuVoices;
    spriteReady = false;
}

void Menu::setVoices(std::vector<std::string>& menuVoices) {
    size_t size = menuVoices.size();
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++) {
        voices[i] = menuVoices[i];
    }
    spriteReady = false;
}

void Menu::setVoices(std::string menuVoices[], size_t size) {
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++) {
        voices[i] = *(menuVoices + i);
    }
    spriteReady = false;
}

void Menu::setVoices(sf::String menuVoices[], size_t size) {
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++) {
        voices[i] = *(menuVoices + i);
    }
    spriteReady = false;
}

void Menu::setDisposition(unsigned short c, unsigned short r) {
    columns = c;
    rows = r;
    spriteReady = false;
}

void Menu::setDimension(unsigned int w, unsigned h) {
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
    spriteReady = false;
    if (!spriteReady) {
        background.clear(backgroundColor);
        sf::Vector2f currTextPos = position;
        short i = 0;
        short j = 0;
        for (auto& str : voices) {
            text.setPosition(currTextPos);
            text.setString(str);
            background.draw(text);
            currTextPos.x += 60.f;
            if (++i == columns) {
                if (++j == rows) {
                    break;
                }
                currTextPos.y += 60.f;
                i = 0;
                currTextPos.x = position.x;
            }
        }

        background.display();
        sprite.setTexture(background.getTexture());
        spriteReady = true;
    }
    return sprite;
}
