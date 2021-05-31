#include "TextBox.h"

//value are passed through Vector2f
TextBox::TextBox(sf::Vector2f position, sf::Vector2f size){
    background = sf::RectangleShape(position);
    background.setSize(size);
}

//value are passed through float
TextBox::TextBox(float x, float y, float w, float h){
    background = sf::RectangleShape(sf::Vector2f(x, y));
    background.setSize(sf::Vector2f(w, h));
}

//use if want set position and size later
TextBox::TextBox(){
     background = sf::RectangleShape();
}

//update the position of textbox
void TextBox::setPosition(sf::Vector2f position){
    background.setPosition(position);
}

void TextBox::setPosition(float x, float y){
    background.setPosition(sf::Vector2f(x, y));
}


//update the size of textbox
void TextBox::setSize(sf::Vector2f position){
    background.setSize(position);
}

void TextBox::setSize(float x, float y){
    background.setSize(sf::Vector2f(x, y));
}

