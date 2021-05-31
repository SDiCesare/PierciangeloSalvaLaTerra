#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include "World.h"

class Game
{
private:
    sf::RenderWindow window;
    World *world;
    void tick();
    void draw();

public:
    Game();
    void run();
    static int getRandInt(int min, int max);
    static float getRandFloat();
    const static int width = 800;
    const static int height = 600;
};

#endif