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
     */
    TextBox(int w, int h, const sf::Vector2f& position);

    /**
     * @brief Update the textbox position
     * 
     * @param position The new textbox position
     */
    void setPosition(const sf::Vector2f& position);

    /**
     * @brief Update the textbox position
     * 
     * @param x The X coordinate of the new textbox position
     * @param y The Y coordinate of the new textbox position
     */
    void setPosition(float x, float y);

    /**
     * @brief Generate the textbox
     * 
     * Will generate the textbox with full text
     * @return The sprite in which the textbox was drawn
     */
    const sf::Sprite &getSprite();

    /**
     * @brief Generate the textbox in typewriter mode
     * 
     * Will generate the textbox with part of the text in base of how much time
     * has passed between a call and another, to get the typewriter effect is
     * required to call this method until the method isPrinting will return false
     * 
     * @see isPrinting
     * 
     * @return The sprite in which the textbox was drawn
     */
    const sf::Sprite &typewriter();

    /**
     * @brief Update the text in the textbox
     * 
     * @param text The new text
     * @return If the update has been applied 
     */
    bool setString(const sf::String& text);

    /**
     * @brief Update the textbox background color
     * 
     * @param color The new background color
     * @return If the update has been applied
     */
    bool setBackgroundColor(const sf::Color& color);

    /**
     * @brief Update the text color
     * 
     * @param color The new text color
     * @return If the update has been applied
     */
    bool setTextColor(const sf::Color& color);

    /**
     * @brief Check if the typewriter process needs to process textbox again to complete text
     * 
     * @return If the typewriter process needs to process textbox again
     */
    bool isPrinting();

    /**
     * @brief Update the elapsed time between two characters
     * 
     * This parameter is needed to typewriter process, default value is 0.4
     * @param time The time in seconds that needs to pass between the print of two characters
     */
    void setCharTime(float time);

    /**
     * @brief Get the elapsed time between two characters
     * 
     * @return The elapsed time between two characters
     */
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