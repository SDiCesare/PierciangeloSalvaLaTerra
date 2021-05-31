#include "TextBox.h"

// create texture with W x H size, save position to 0,0
TextBox::TextBox(int w, int h) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    position = sf::Vector2f(0.f, 0.f);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, float x, float y) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    position = sf::Vector2f(x, y);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, sf::Vector2f position) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    this->position = position;
    setInitialValue();
}

//initialize the other TextBox variable
void TextBox::setInitialValue() {
    color = sf::Color::White;
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf")) {
        // TODO create exception class
        throw 2;
    }

    text.setFont(font);
}

// update the position of textbox
void TextBox::setPosition(sf::Vector2f newPosition) { this->position = position; }

void TextBox::setPosition(float x, float y) { position = sf::Vector2f(x, y); }

//update the string in the drawable text
void TextBox::setString(std::string str) {
    text.setString(str);
}

//update the color that will be used after background.clear
void TextBox::setColor(sf::Color color) {
    this->color = color;
}

// return the pointer of a sprite to which the background and text was applied
sf::Sprite* TextBox::getSprite() {
    // create white background
    background.clear(color);
    // draw text on background
    background.draw(text);

    background.display();

    // put texture in a sprite and set the position
    sf::Sprite sprite(background.getTexture());
    sprite.setPosition(position);

    return &sprite;
}
