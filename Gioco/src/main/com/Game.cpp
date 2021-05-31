
#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
    x = 0;
    y = 0;
}

void Game::run()
{
    window.create(sf::VideoMode(800, 600), "My window");

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
    if (x > window.getSize().x)
    {
        x = 0;
    }
    if (x < 0) {
        x = window.getSize().x;
    }
    if (y > window.getSize().y)
    {
        y = 0;
    }
    if (y < 0) {
        y = window.getSize().y;
    }
}

void Game::draw()
{
    window.clear();
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
    window.draw(shape);
    window.display();
}

void Game::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        x--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        x++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        y--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        y++;
    }
}