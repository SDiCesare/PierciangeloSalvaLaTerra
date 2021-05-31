#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main(int argv, char **argc)
{

    Game *game = new Game();
    game->run();

    return 0;
}