#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow window;
    int x;
    int y;
    void tick();
    void draw();
    void checkInput();

public:
    Game();
    void run();
};