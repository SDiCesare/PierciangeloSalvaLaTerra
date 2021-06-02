#include "Menu.h"

#include <iostream>

Menu::Menu() {
    backgroundColor = sf::Color::White;
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf"))
    {
        // TODO create exception class
        throw 2;
    }
    text.setCharacterSize(16);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(0.f, 0.f);
}

void Menu::setVoices(std::vector<sf::String> menuVoices) {
    voices = menuVoices;
}

void Menu::setVoices(std::vector<std::string>& menuVoices) {
    size_t size = menuVoices.size();
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        voices[i] = menuVoices[i];
    }
}

void Menu::setVoices(std::string menuVoices[], size_t size) {
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        voices[i] = *(menuVoices+i);
    }
}

void Menu::setVoices(sf::String menuVoices[], size_t size) {
    // set the dimension needed once
    voices.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        voices[i] = *(menuVoices+i);
    }
}

sf::Sprite& Menu::getSprite() {
    
}
