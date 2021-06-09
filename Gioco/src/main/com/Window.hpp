#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>
#include "entity\\Entity.hpp"
#include "tile\\Tile.hpp"
#include <list>

class Window
{
public:
    Window(sf::Vector2f playerPos);
    void drawWorld(std::list<Entity *> &entities, std::list<Tile *> &tiles);
    void setPlayerPos(sf::Vector2f playerPos);
    bool isOpen();
    void moveGameView(sf::Vector2f pos);
    bool pollEvent(sf::Event &event);
    void close();

private:
    sf::RenderWindow window;
    sf::View gameView;
    sf::View hudView;
    sf::Vector2f playerPos;

public:
    /**
     * @param width The width of the window
     * */
    const static int width = 800;

    /**
     * @param height The height of the window
     * */
    const static int height = 600;
};

#endif