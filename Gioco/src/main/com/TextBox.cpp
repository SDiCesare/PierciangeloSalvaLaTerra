#include "TextBox.h"

#include <stdlib.h>

// create texture with W x H size, save position to 0,0
TextBox::TextBox(int w, int h) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(0.f, 0.f);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, float x, float y) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(x, y);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, sf::Vector2f position) {
    if (!background.create(w, h)) {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(position);
    setInitialValue();
}

//initialize the other TextBox variable
void TextBox::setInitialValue() {
    color = sf::Color::White;
    background.clear(color);
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf")) {
        // TODO create exception class
        throw 2;
    }
    text.setCharacterSize(16);
    printing = false;
    needToDraw = false;
    text.setFont(font);
}

// update the position of textbox
void TextBox::setPosition(sf::Vector2f newPosition) {
    sprite.setPosition(position);
    needToDraw = true;
}

void TextBox::setPosition(float x, float y) {
    sprite.setPosition(x, y);
    needToDraw = true;
}

//update the string in the drawable text
void TextBox::setString(std::string str) {
    string = str;
}

//update the color, this will clear the texture, return True if change was applied
bool TextBox::setColor(sf::Color color) {
    if (!printing) {
        this->color = color;
        background.clear(color);
        return true;
    }
    return false;
}

bool TextBox::isPrinting() {
    return printing;
}

// return the pointer of a sprite to which the background and text was applied
sf::Sprite* TextBox::getSprite() {
    // create white background
    background.clear(color);
    // draw text on background
    text.setString(string);
    background.draw(text);

    background.display();

    // put texture in a sprite and set the position
    sprite.setTexture(background.getTexture());
    sprite.setPosition(position);

    return &sprite;
}

sf::Sprite* TextBox::typewriter(int frame) {
    if (!printing) {
        printing = true;
        needToDraw = true;
    }

    int framePerChar = 6;

    //more efficent way to get both quotient and remainder
    div_t divresult = div(frame, framePerChar);

    //update every 6 frame or if needToDraw is on (for now only when change sprite position)
    if (divresult.rem == 0 || needToDraw) {
        needToDraw = false;
        sf::String partStr = string.substring(0, divresult.quot);
        sprite.setTexture(background.getTexture());

        if (partStr.getSize() == string.getSize()) {
            printing = false;
        }
    }

    return &sprite;
}
