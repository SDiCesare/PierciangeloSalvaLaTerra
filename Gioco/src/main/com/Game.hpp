#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <list>
#include "entity\Player.hpp"
#include "tile\Tile.hpp"
#include "Window.hpp"

class Game
{

public:
    Game();
    void run();
    void tick();
    void draw();
    void processInput();
    void addEntity(Entity &entity);
    void checkCollision();
    void checkPositions();
    void generateWorld();

public:
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

private:
    Window window;
    Player *player;
    std::list<Entity *> entities;
    std::list<Tile *> tiles;
    sf::Font font;
    int counter; //for debugging, it counts how many time the loop was executed
};

#endif