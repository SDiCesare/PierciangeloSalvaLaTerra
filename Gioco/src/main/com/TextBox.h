#ifndef TextBox_h
#define TextBox_h
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>


/**
 * @class TextBox
 * 
 * TextBox is an object to create textbox in sfml, the text can be displayed immediatly
 * or in typewriter mode
 * 
 */
class TextBox
{

public:
    /**
     * @brief Default constructor, construct a textbox of w*h dimension
     * 
     * The textbox will have no text and will be in 0,0 position 
     * 
     * @param w The textbox width
     * @param h The textbox height
     */
    TextBox(int w, int h);

    /**
     * @brief Construct the textbox in the past position
     * 
     * The textbox will have no text
     * 
     * @param w The textbox width
     * @param h The textbox height
     * @param x The X coordinate of textbox position
     * @param y the Y coordinate of textbox position
     */
    TextBox(int w, int h, float x, float y);

    /**
     * @brief Construct the textbox in the past position
     * 
     * The textbox will have no text
     * 
     * @param w The textbox width
     * @param h The textbox height
     * @param position The textbox position
     * */
    TextBox(int w, int h, const sf::Vector2f& position);
    void setPosition(const sf::Vector2f& newPosition);
    void setPosition(float x, float y);
    sf::Sprite *getSprite();
    sf::Sprite *typewriter();
    bool setString(const std::string& str);
    bool setBackgroundColor(const sf::Color& color);
    bool setTextColor(const sf::Color& color);
    bool isPrinting();
    void setCharTime(float time);
    float getCharTime();

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
    float charTime;
};

#endif