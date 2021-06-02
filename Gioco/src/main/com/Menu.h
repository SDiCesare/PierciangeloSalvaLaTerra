#ifndef Menu_h
#define Menu_h
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


class Menu{

public:
    Menu();
    Menu(unsigned int w, unsigned int h, float x, float y);
    Menu(unsigned int w, unsigned int h, sf::Vector2f position);
    void setVoices(std::string menuVoices[], size_t size);
    void setVoices(std::vector<std::string>& menuVoices);
    void setVoices(std::vector<sf::String> menuVoices);
    void setVoices(sf::String menuVoices[], size_t size);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void setDimension(unsigned int w, unsigned int h);
    void setDisposition(unsigned short c, unsigned short r);
    const sf::Sprite& getSprite();

private:
    std::vector<sf::String> voices;
    sf::Font font;
    sf::Text text;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color backgroundColor;
    sf::Sprite sprite;
    unsigned short columns;
    unsigned short rows;
    bool spriteReady;
    void setDefaultValue();

};

#endif