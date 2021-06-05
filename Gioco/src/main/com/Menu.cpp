#include "Menu.hpp"

#include <stdlib.h>  // div, div_t

#include <algorithm>  //std::copy
#include <iostream>

Menu::Menu() {
    setDefaultValue();
}

Menu::Menu(unsigned int w, unsigned int h, float x, float y) {
    setPosition(x, y);
    setDimension(w, h);
    setDefaultValue();
}

Menu::Menu(unsigned int w, unsigned int h, const sf::Vector2f& position) {
    setPosition(position);
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

bool Menu::selectVoice(int8_t directions) {
    // sf::Vector2<int8_t> vect = takeLastVoiceIdx();
    if (!positionReady) {
        takeLastVoiceIdx();
    }
    std::cout << unsigned(lastVoiceIdx.x) << " - " << unsigned(lastVoiceIdx.y) << std::endl;
    std::cout << "previous pos " << voiceX << " - " << voiceY << std::endl;
    short prevX = voiceX;
    short prevY = voiceY;
    switch (directions) {
        case 1:
            if (--voiceY < 0) {
                if (voiceX > lastVoiceIdx.x)
                    voiceX = lastVoiceIdx.x;
                voiceY = lastVoiceIdx.y;
            }

            break;

        case 2:
            if ((++voiceX >= lastVoiceIdx.x && voiceY == lastVoiceIdx.y) || voiceX >= columns) {
                voiceX = 0;
            }
            break;

        case 3:
            if (++voiceY >= rows) {
                voiceY = 0;
            } else if (voiceX >= lastVoiceIdx.x && voiceY == lastVoiceIdx.y) {
                voiceX = lastVoiceIdx.x;
            }

            break;

        case 4:
            if (--voiceX < 0) {
                if (voiceY == lastVoiceIdx.y)
                    voiceX = lastVoiceIdx.x;
                else
                    voiceX = columns - 1;
            }
            break;

        default:
            return false;
    }

    if (prevX != voiceX || prevY != voiceY) {
        std::cout << "da ridisegnare" << std::endl;
        spriteReady = false;
        return true;
    } else {
        std::cout << prevX << " = " << voiceX << "   " << prevY << " = " << voiceY << std::endl;
        return false;
    }
}

void Menu::setTextColor(const sf::Color& color) {
    text.setFillColor(color);
}

void Menu::setSelectedVoiceColor(const sf::Color& color) {
    selectedVoiceColor = color;
}

void Menu::setCharSize(unsigned int charSize) {
    text.setCharacterSize(charSize);
}

void Menu::setSelectedVoiceSize(unsigned int charSize) {
    selectedVoiceSize = charSize;
}

void Menu::makeMenu() {
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
}

void Menu::setFont(sf::Font& font){
    text.setFont(font);
}

// set the default value, created not to repeat same code in all constructors
void Menu::setDefaultValue() {
    backgroundColor = sf::Color::White;
    text.setCharacterSize(16);
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
    lastVoiceIdx = sf::Vector2<int8_t>(0, 0);
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
    temp.setFont(*text.getFont());
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

void Menu::takeLastVoiceIdx() {
    if (size > columns * rows) {
        lastVoiceIdx.x = columns - 1;
        lastVoiceIdx.y = rows - 1;
    } else {
        div_t divRes = div(size, columns);
        std::cout << divRes.quot << " - resto " << divRes.rem << std::endl;
        int8_t r = (divRes.quot >= rows) ? rows - 1 : divRes.quot + (divRes.rem > 0) - 1;
        int8_t c = (r > 0 && divRes.rem == 0) ? columns - 1 : divRes.rem - 1;
        lastVoiceIdx.x = c;
        lastVoiceIdx.y = r;
    }
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::Transform t = getTransform();
    target.draw(sprite, t);
}

Menu::~Menu() {
    delete[] voices;
}