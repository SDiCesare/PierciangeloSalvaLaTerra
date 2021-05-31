
#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
    world = new World();
    world->setup();
}

void Game::run()
{
    window->create(sf::VideoMode(800, 600), "My window");

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        checkInput();
        tick();
        draw();
    }
}

void Game::tick()
{
    world->tick();
}

void Game::draw()
{
    window->clear();
    world->display(window);
    window->display();
}

void Game::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        
    }
}