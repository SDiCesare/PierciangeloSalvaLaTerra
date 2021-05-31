#include "TextBox.h"

//value are passed through Vector2f
TextBox::TextBox(sf::Vector2f position, sf::Vector2f size){
    background = sf::RectangleShape(position);
    background.setSize(size);
}

TextBox::TextBox(float x, float y, float w, float h){
    background = sf::RectangleShape(sf::Vector2f(x, y));
    background.setSize(sf::Vector2f(w, h));
}


TextBox::TextBox(){
     background = sf::RectangleShape();
}


void TextBox::setPosition(sf::Vector2f position){
    background.setPosition(position);
}

void TextBox::setPosition(float x, float y){
    background.setPosition(sf::Vector2f(x, y));
}

