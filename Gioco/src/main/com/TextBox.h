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
    sf::Sprite* typewriter();
    bool setString(std::string str);
    bool setBackgroundColor(sf::Color color);
    bool setTextColor(sf::Color color);
    bool isPrinting();
    

private:
    sf::Font font;
    sf::Text text;
    sf::String string;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color backgroundColor;
    sf::Sprite sprite;
    void setInitialValue();
    bool printing;
    bool needToDraw;
    sf::Clock clock;
    int indexTWChar;
    int sizeString;

};

#endif