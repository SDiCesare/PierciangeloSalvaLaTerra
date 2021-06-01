#ifndef TextBox_hpp
#define TextBox_hpp
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
    sf::Sprite* typewriter(int frame);
    void setString(std::string str);
    bool setColor(sf::Color color);
    bool isPrinting();
    

private:
    sf::Font font;
    sf::Text text;
    sf::String string;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color color;
    sf::Sprite sprite;
    void setInitialValue();
    bool printing;
    bool needToDraw;

};

#endif