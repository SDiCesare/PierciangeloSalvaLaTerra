#include <SFML/Graphics.hpp>
#include "World.h"

class Game
{
private:
    sf::RenderWindow *window;
    World *world;
    void tick();
    void draw();
    void checkInput();

public:
    Game();
    void run();
};