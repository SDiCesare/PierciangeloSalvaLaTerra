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
    Game();
    void run();
    static int getRandInt(int min, int max);
    static float getRandFloat();
    const static int width = 800;
    const static int height = 600;
};

#endif