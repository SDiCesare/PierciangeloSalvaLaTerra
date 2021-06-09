#include "Window.hpp"

Window::Window(sf::Vector2f playerPos)
{
    this->playerPos = playerPos;
    window.create(sf::VideoMode(width, height), "Game");
    window.setFramerateLimit(60);
    gameView = sf::View(sf::FloatRect(0, 0, width, height));
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

void Window::moveGameView(sf::Vector2f pos)
{
    gameView.setCenter(pos);
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

bool Window::pollEvent(sf::Event &event)
{
    return this->window.pollEvent(event);
}

void Window::close()
{
    this->window.close();
}