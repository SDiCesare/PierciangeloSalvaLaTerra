#include "TextBox.hpp"

// create texture with W x H size, save position to 0,0
TextBox::TextBox(int w, int h) {
    setPosition(0.f, 0.f);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, float x, float y) {
    setPosition(x, y);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, const sf::Vector2f& position) {
    setPosition(position);
    setInitialValue();
}

//initialize the other TextBox variable
void TextBox::setInitialValue() {
    background.setFillColor(sf::Color::White);
    background.setPosition(0.f, 0.f);
    text.setCharacterSize(16);
    printing = false;
    needToDraw = false;
    text.setFillColor(sf::Color::Black);
    text.setPosition(0.f, 0.f);
    indexTWChar = 0;
    sizeString = 0;
    text.setPosition(0.f, 0.f);
    charTime = 400;
}

//update the string in the drawable text
bool TextBox::setString(const sf::String& str) {
    if (!printing) {
        string = str;
        sizeString = string.getSize();
        indexTWChar = 0;
        needToDraw = true;
        return true;
    }
    return false;
}

//update the backgroundColor, this will clear the texture, return True if change was applied
bool TextBox::setBackgroundColor(const sf::Color& color) {
    if (!printing) {
        this->background.setFillColor(color);
        return true;
    }
    return false;
}

//update the textColor, this will clear the texture, return True if change was applied
bool TextBox::setTextColor(const sf::Color& color) {
    if (!printing) {
        text.setFillColor(color);
        return true;
    }
    return false;
}

bool TextBox::isPrinting() {
    return printing;
}

// return the pointer of a sprite to which the background and text was applied
void TextBox::makeInstantText() {
    // draw text on background
    if (needToDraw)
        text.setString(string);
}

int TextBox::getCharTime() {
    return this->charTime;
}

void TextBox::setCharTime(int charTime) {
    this->charTime = charTime;
}

bool TextBox::setFont(sf::Font& font) {
    if (!printing) {
        text.setFont(font);
        return true;
    }
    return false;
}

void TextBox::typewriter() {
    if (!printing) {
        if (indexTWChar == 0) {
            printing = true;
            needToDraw = true;
            clock.restart();
            indexTWChar = 0;
        } else {
            return;
        }
    }

    int time = clock.getElapsedTime().asMilliseconds();
    //update every charTime second or if needToDraw is on (for now only when change sprite position)
    if (time >= charTime || needToDraw) {
        needToDraw = false;
        //add the new size
        indexTWChar += static_cast<int>(time / charTime);

        //if indexTWChar reach sizeString the printing is finished,
        //assign indexTWChar = sizeString in case indexTWChar is greather than sizeString
        if (indexTWChar >= sizeString) {
            printing = false;
            indexTWChar = sizeString;
        }

        sf::String partStr = string.substring(0, indexTWChar);
        text.setString(partStr);

        //restart the clock, otherwise next cicles will print new chars
        clock.restart();
    }
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // You can draw other high-level objects
    sf::Transform t = getTransform();
    target.draw(background, t);
    target.draw(text, t);
}
