#include "Menu.h"

#include <stdlib.h>  // div, div_t

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
    positionReady = false;
    spriteReady = false;
}

void Menu::setDisposition(uint8_t c, uint8_t r) {
    columns = c;
    rows = r;
    spriteReady = false;
    positionReady = false;
}

void Menu::setDimension(unsigned int w, unsigned int h) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }
    spriteReady = false;
    positionReady = false;
}

void Menu::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Menu::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

bool Menu::selectVoice(int8_t directions) {
    sf::Vector2<int8_t> vect = takeLastVoiceIdx();
    std::cout << unsigned(vect.x) << " - " << unsigned(vect.y) << std::endl;
    std::cout << "previous pos " << voiceX << " - " << voiceY << std::endl;
    short prevX = voiceX;
    short prevY = voiceY;
    switch (directions) {
        case 1:
            if (--voiceY < 0) {
                if (voiceX > vect.x)
                    voiceX = vect.x;
                voiceY = vect.y;
            }

            break;

        case 2:
            if ((++voiceX >= vect.x && voiceY == vect.y) || voiceX >= columns) {
                voiceX = 0;
            }
            break;

        case 3:
            if (++voiceY >= rows) {
                voiceY = 0;
            } else if (voiceX >= vect.x && voiceY == vect.y) {
                voiceX = vect.x;
            }

            break;

        case 4:
            if (--voiceX < 0) {
                if (voiceY == vect.y)
                    voiceX = vect.x;
                else
                    voiceX = columns - 1;
            }
            break;

        default:
            return false;
    }

    if (prevX != voiceX && prevY != voiceY) {
        spriteReady = false;
        return true;
    } else {
        return false;
    }
}

void Menu::setTextColor(sf::Color color){
    text.setFillColor(color);
}

void Menu::setSelectedVoiceColor(sf::Color color){
    selectedVoiceColor = color;
}

void Menu::setCharSize(unsigned int charSize){
    text.setCharacterSize(charSize);
}

void Menu::setSelectedVoiceSize(unsigned int charSize){
    selectedVoiceSize = charSize;
}

const sf::Sprite& Menu::getSprite() {
    //avoid to elaborate again the same sprite
    if (!spriteReady) {
        background.clear(backgroundColor);
        short k = 0;
        short j = 0;
        sf::Color textColor = text.getFillColor();
        unsigned int charSize = text.getCharacterSize();
        if (!positionReady)
            takeDistance();

        sf::Vector2f currTextPos = position;
        for (size_t i = 0; i < size; i++) {
            std::string str = *(voices + i);
            text.setPosition(currTextPos);
            text.setString(str);
            if (k == voiceX && j == voiceY) {
                text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setFillColor(selectedVoiceColor);
                text.setCharacterSize(selectedVoiceSize);
                background.draw(text);
                text.setCharacterSize(charSize);
                text.setFillColor(textColor);
                text.setStyle(sf::Text::Regular);
            } else {
                background.draw(text);
            }
            // sf::FloatRect textRect = text.getLocalBounds();
            // text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
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
    positionReady = false;
    voiceX = 0;
    voiceY = 0;
    selectedVoiceColor = sf::Color::Black;
    selectedVoiceSize = 16;
}

// calculate distancec between voices
void Menu::takeDistance() {
    if (columns <= 1) {
        distance = 0.f;
        position.x = 0.f;
        return;
    }

    //find the max bound, maybe there is a better way to calculate it
    sf::Text temp;
    temp.setCharacterSize(selectedVoiceSize);
    temp.setFont(font);
    temp.setPosition(0.f, 0.f);
    float max = 0.f;
    for (size_t i = 0; i < size; i++) {
        temp.setString(*(voices + i));
        sf::FloatRect bounds = temp.getLocalBounds();

        if (bounds.width > max)
            max = bounds.width;
    }

    
        float w = static_cast<float>(background.getSize().x);
        float columnsF = static_cast<float>(columns);
        distance = (w - max * columnsF) / (columnsF - 1.f) + max;
    position.x = 0.f;
}

sf::Vector2<int8_t> Menu::takeLastVoiceIdx() {
    if (size > columns * rows) {
        return sf::Vector2<int8_t>(columns - 1, rows - 1);
    } else {
        div_t divRes = div(size, columns);
        std::cout << divRes.quot << " - resto " << divRes.rem << std::endl;
        int8_t r = (divRes.quot >= rows) ? rows - 1 : divRes.quot + (divRes.rem > 0) - 1;
        int8_t c = (r > 0 && divRes.rem == 0) ? columns - 1 : divRes.rem - 1;
        return sf::Vector2<int8_t>(c, r);
    }
}

Menu::~Menu() {
    delete[] voices;
}