#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include "World.hpp"

class Game
{
private:
    sf::RenderWindow window;
    World *world;
    void tick();
    void draw();
    void checkInput();

public:
    /**
     * @brief The Default Constructor of Game
     * */
    Game();

    /**
     * @brief Start The Game
     * */
    void run();

    /**
     * @brief Generates a random integer value from min to max 
     * //TODO Implements SEED SYSTEM
     * 
     * @param min The minimum value that can result
     * @param max The maximum value that can result
     * 
     * @return A Random integer value between min and max
     * */
    static int getRandInt(int min, int max);

    /**
     * @brief Generates a random floating point value
     * //TODO Implements SEED SYSTEM
     * 
     * @return A Random floating point
     * */
    static float getRandFloat();

    /**
     * @param width The width of the window
     * */
    const static int width = 800;

    /**
     * @param height The height of the window
     * */
    const static int height = 600;
};

#endif