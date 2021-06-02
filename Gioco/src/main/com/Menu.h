#ifndef Menu_h
#define Menu_h
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

/**
 * Implementation of Menu
 * 
 * Simple way to represent Menu in SFML giving the strings to be represented,
 * their disposition and the position of the menu in the window
 */
class Menu {
   public:
   
    /**
     * \brief Default constructor
     * Creates Menu with no voices, no setted disposition and no dimension
     */
    Menu();

    /**
     * \brief Creates Menu in the sent position and with the sent dimension
     * 
     * \param w Witdh of menu
     * \param h Height of menu
     * \param x X coordinate of the menu
     * \param y Y coordinate of the menu
     */
    Menu(unsigned int w, unsigned int h, float x, float y);

    /**
     * \brief Creates Menu in the sent position and with the sent dimension
     * 
     * \param w Witdh of menu
     * \param h Height of menu
     * \param position The position of the menu
     */
    Menu(unsigned int w, unsigned int h, sf::Vector2f position);

    /**
     * \brief Set the voices of the menu
     * 
     * The voices will be disposed in base of values passed to the methodsetDisposition
     * \param menuVoices Array of voices
     * \param size Lenght of menuVoices
     */
    void setVoices(std::string menuVoices[], size_t size);

    /**
     * \brief Set the voices of the menu
     * 
     * The voices will be disposed in base of values passed to the methodsetDisposition
     * \param menuVoices Vector of voices
     */
    void setVoices(std::vector<std::string>& menuVoices);

    /**
     * \brief Set the voices of the menu
     * 
     * The voices will be disposed in base of values passed to the methodsetDisposition
     * \param menuVoices Vector of voices
     */
    void setVoices(std::vector<sf::String> menuVoices);

    /**
     * \brief Set the voices of the menu
     * 
     * The voices will be disposed in base of values passed to the methodsetDisposition
     * \param menuVoices Array of voices
     * \param size Lenght of menuVoices
     */
    void setVoices(sf::String menuVoices[], size_t size);

    /**
     * \brief Set the position of the menu in the window
     * 
     * \param position The new position of the menu
     */
    void setPosition(sf::Vector2f position);

    /**
     * \brief Set the position of the menu in the window
     * 
     * \param x X coordinate of the menu
     * \param y Y coordinate of the menu
     */
    void setPosition(float x, float y);
    void setDimension(unsigned int w, unsigned int h);

    /**
     * \brief Set the disposition of voices in the menu
     * 
     * The voices will be arranged filling first the rows and after the columns
     * 
     * \param c Number of colomuns
     * \param r Number of rows
     */
    void setDisposition(unsigned short c, unsigned short r);

    /**
     * \brief Generate the sprite representing the menu
     * 
     * If not all essential value have been set, the menu will not be drawn
     * 
     * \return const sf::Sprite& A const reference to the sprite of the menu
     */
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