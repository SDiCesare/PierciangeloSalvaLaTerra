#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>
#include <string>

class TextBox{

public:
    TextBox(int w, int h);
    TextBox(int w, int h, float x, float y);
    TextBox(int w, int h, sf::Vector2f position);
    void setPosition(sf::Vector2f);
    void setPosition(float x, float y);
    sf::Sprite* getSprite();
    

private:
    sf::Text text;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color color;

};

#endif