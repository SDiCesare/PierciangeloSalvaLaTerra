#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include "entity\\Entity.hpp"

Game::Game()
{
    srand(time(NULL));
    world = new World();
}

void Game::run()
{
    window.create(sf::VideoMode(Game::width, Game::height), "My window");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
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

void Game::checkInput()
{
    if (world->end)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            world = new World();
        }
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        //TODO Shooting
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        world->player->move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        world->player->move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        world->player->move(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        world->player->move(0, 1);
    }
}

void Game::draw()
{
    window.clear();
    world->display(window);
    window.display();
}

int Game::getRandInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

float Game::getRandFloat()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}