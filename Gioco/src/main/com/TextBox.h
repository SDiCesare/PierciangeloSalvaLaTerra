#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>
#include <string>

class TextBox{

public:
    TextBox(int w, int h);
    TextBox(int w, int h, float x, float y);
    TextBox(int w, int h, sf::Vector2f position);
    void setPosition(sf::Vector2f newPosition);
    void setPosition(float x, float y);
    sf::Sprite* getSprite();
    void setString(std::string str);
    void setColor(sf::Color color);
    

private:
    sf::Font font;
    sf::Text text;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color color;
    void setInitialValue();

};

#endif