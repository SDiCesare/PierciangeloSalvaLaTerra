#ifndef ResourceHandler_hpp
#define ResourceHandler_hpp

#include <SFML\\Graphics.hpp>
#include <iostream>

class ResourceHandler
{
public:
    static sf::Texture PLAYER_TEXTURE;
    static sf::Texture SNAKE_TEXTURE;

    static void loadResources()
    {
        std::cout << "Loading Resource...\n";
        if (PLAYER_TEXTURE.loadFromFile("..\\resources\\textures\\entity\\player.png"))
        {
            std::cout << "Loaded Player Texture: " << &PLAYER_TEXTURE << "\n";
        }
        if (SNAKE_TEXTURE.loadFromFile("..\\resources\\textures\\entity\\enemy.png"))
        {
            std::cout << "Loaded Enemy Snake Texture: " << &SNAKE_TEXTURE << "\n";
        }
        std::cout << "Resource Loaded\n================================\n";
    }
};
#endif