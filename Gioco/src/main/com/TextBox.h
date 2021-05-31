#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>
#include <string>

class TextBox{

public:
    TextBox(sf::Vector2f position, sf::Vector2f size);
    TextBox(float x, float y, float w, float h);
    TextBox();
    void setPosition(sf::Vector2f);
    void setPosition(float x, float y);
    void setSize(sf::Vector2f);
    void setSize(float x, float y);
    

private:
    std::string text;
    sf::RectangleShape background;

};

#endif