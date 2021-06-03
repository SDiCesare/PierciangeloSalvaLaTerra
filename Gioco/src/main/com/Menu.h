#ifndef Menu_h
#define Menu_h
#include <SFML/Graphics.hpp>

/**
 * \brief Implementation of graphic menu in SFML
 * 
 * Simple way to represent Menu in SFML giving the strings to be represented,
 * their disposition and the position of the menu in the window, it has only
 * graphical purpose, it isn't designed to return values in base of the 
 * selected voice
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

    /**
     * \brief Set the dimension of menu
     * 
     * \param w Width of the menu
     * \param h Height of the menu
     */
    void setDimension(unsigned int w, unsigned int h);

    /**
     * \brief Set the disposition of voices in the menu
     * 
     * The voices will be arranged filling first the rows and after the columns
     * 
     * \param c Number of colomuns
     * \param r Number of rows
     */
    void setDisposition(uint8_t c, uint8_t r);

    /**
     * \brief Generate the sprite representing the menu
     * 
     * If not all essential value have been set, the menu will not be drawn
     * 
     * \return A const reference to the sprite of the menu
     */
    const sf::Sprite& getSprite();

     /**
     * \brief Select another voice, the ones above, those below,
     *  those on the right and those on the left can be selected
     * 
     * At the beginning the voices selected is the one on the top left
     * 
     * \param direction in which direction is the wanted voice
     * \code
     * menu.selectVoice(0); //keep the current selected voice
     * menu.selectVoice(1); //select the voice above
     * menu.selectVoice(2); //select the voice on the right
     * menu.selectVoice(3); //select the voice below
     * menu.selectVoice(4); //select the voice on the left
     * \endcode
     * \return If the selected voice is changed
     */
    bool selectVoice(int8_t direction);

    virtual ~Menu();

   private:
    // std::vector<sf::String> voices;
    sf::String* voices;
    size_t size;
    sf::Font font;
    sf::Text text;
    sf::RenderTexture background;
    sf::Vector2f position;
    sf::Color backgroundColor;
    sf::Sprite sprite;
    uint8_t columns;
    uint8_t rows;
    float distance;

    //save the position of the selected voices
    short voiceX;
    short voiceY;

    bool spriteReady;
    bool positionReady;
    void setDefaultValue();
    void takeDistance();
    //get the last element position in the menu disposition
    sf::Vector2<int8_t> takeLastVoiceIdx();
};

#endif