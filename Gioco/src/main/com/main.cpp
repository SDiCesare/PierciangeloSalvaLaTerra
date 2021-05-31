#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "Game.h"

void loadDLL()
{
    HINSTANCE dllHinstance = LoadLibrary("");
    if (dllHinstance == NULL)
    {
        printf("Can't load file");
    }
}

int main(int argv, char **argc)
{

    Game *game = new Game();
    game->run();

    return 0;
}