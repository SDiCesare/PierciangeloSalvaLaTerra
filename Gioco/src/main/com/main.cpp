#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "ResourceHandler.hpp"

int main(int argv, char **argc)
{
    ResourceHandler::loadDefault();
    Game *game = new Game();
    game->run();
    return 0;
}