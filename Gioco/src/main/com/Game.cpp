#include "Game.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "World.h"
#include "Bullet.h"

Game::Game()
{
    world = new World();
}

void Game::run()
{
    window.create(sf::VideoMode(Game::width, Game::height), "My window");
    window.setFramerateLimit(60.f);
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
        tick();
        draw();
    }
}

void Game::tick()
{
    world->tick();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        world->addEntity(new Bullet(world->player));
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
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

float Game::getRandFloat()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}