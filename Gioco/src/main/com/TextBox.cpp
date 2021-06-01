#include "TextBox.h"

// create texture with W x H size, save position to 0,0
TextBox::TextBox(int w, int h)
{
    if (!background.create(w, h))
    {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(0.f, 0.f);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, float x, float y)
{
    if (!background.create(w, h))
    {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(x, y);
    setInitialValue();
}

// create texture with W x H size and save position in a Vector2f
TextBox::TextBox(int w, int h, sf::Vector2f position)
{
    if (!background.create(w, h))
    {
        // TODO create exception class
        throw 1;
    }

    sprite.setPosition(position);
    setInitialValue();
}

//initialize the other TextBox variable
void TextBox::setInitialValue()
{
    backgroundColor = sf::Color::White;
    background.clear(backgroundColor);
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf"))
    {
        // TODO create exception class
        throw 2;
    }
    text.setCharacterSize(16);
    printing = false;
    needToDraw = false;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(0.f, 0.f);
    indexTWChar = 0;
    sizeString = 0;
    text.setPosition(0.f, 0.f);
}

// update the position of textbox
void TextBox::setPosition(sf::Vector2f newPosition)
{
    sprite.setPosition(position);
    needToDraw = true;
}

void TextBox::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
    needToDraw = true;
}

//update the string in the drawable text
bool TextBox::setString(std::string str)
{
    if (!printing)
    {
        string = str;
        sizeString = string.getSize();
        indexTWChar = 0;
        return true;
    }
    return false;
}

//update the backgroundColor, this will clear the texture, return True if change was applied
bool TextBox::setBackgroundColor(sf::Color color)
{
    if (!printing)
    {
        this->backgroundColor = color;
        return true;
    }
    return false;
}

//update the textColor, this will clear the texture, return True if change was applied
bool TextBox::setTextColor(sf::Color color)
{
    if (!printing)
    {
        text.setFillColor(color);
        return true;
    }
    return false;
}

bool TextBox::isPrinting()
{
    return printing;
}

// return the pointer of a sprite to which the background and text was applied
sf::Sprite *TextBox::getSprite()
{
    // create white background
    background.clear(backgroundColor);
    // draw text on background
    text.setString(string);
    background.draw(text);

    background.display();

    // put texture in a sprite and set the position
    sprite.setTexture(background.getTexture());
    // sprite.setPosition(position);

    return &sprite;
}

float TextBox::getCharTime()
{
    return this->charTime;
}

void TextBox::setCharTime(float charTime)
{
    this->charTime = charTime;
}

sf::Sprite *TextBox::typewriter()
{
    if (!printing && indexTWChar == 0)
    {
        printing = true;
        needToDraw = true;
        clock.restart();
        indexTWChar = 0;
    }

    float time = clock.getElapsedTime().asMilliseconds();
    //update every charTime second or if needToDraw is on (for now only when change sprite position)
    if (time >= charTime || needToDraw)
    {
        //add the new size
        indexTWChar += static_cast<int>(time / charTime);

        //if indexTWChar reach sizeString the printing is finished,
        //assign indexTWChar = sizeString in case indexTWChar is greather than sizeString
        if (indexTWChar >= sizeString)
        {
            printing = false;
            indexTWChar = sizeString;
        }

        needToDraw = false;

        sf::String partStr = string.substring(0, indexTWChar);
        text.setString(partStr);

        //draw and set texture to sprite
        background.clear(backgroundColor);
        background.draw(text);
        background.display();
        sprite.setTexture(background.getTexture());

        //restart the clock, otherwise next cicles will print new chars
        clock.restart();
    }

    return &sprite;
}
