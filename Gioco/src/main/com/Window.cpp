#include "Window.hpp"
#include <list>

Window::Window(sf::Vector2f playerPos)
{
    this->playerPos = playerPos;
    window.create(sf::VideoMode(width, height), "Game");
    int x = this->playerPos.x - 300;
    int y = this->playerPos.y - 300;
    gameView = sf::View(sf::FloatRect(x, y, x + 600, y + 600));
    //TODO Set HUD View
}

void Window::drawWorld(std::list<Entity *> &entities, std::list<Tile *> &tiles)
{
    window.setView(gameView);
    window.clear();
    for (Tile *t : tiles)
    {
        window.draw(*t);
    }
    for (Entity *e : entities)
    {
        window.draw(*e);
    }
    window.display();
}

void Window::moveGameView(float x, float y)
{
    this->playerPos.x += x;
    this->playerPos.y += y;
    gameView.move(x, y);
}

void Window::setPlayerPos(sf::Vector2f playerPos)
{
    this->playerPos = playerPos;
    int x = this->playerPos.x - 300;
    int y = this->playerPos.y - 300;
    gameView = sf::View(sf::FloatRect(x, y, x + 600, y + 600));
}

bool Window::isOpen()
{
    return this->window.isOpen();
}