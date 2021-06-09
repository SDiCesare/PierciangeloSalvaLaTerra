#ifndef World_hpp
#define World_hpp

#include "entity\Player.hpp"
#include "tile\Tile.hpp"
#include "HUD\HealthBarNum.hpp"
#include "HUD\HealthBar.hpp"
#include "TextBox.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include "Menu.hpp"
#include "HUD\Inventory.hpp"
#include "room\\FireRoom.hpp"

//class Game;

class World
{
public:
    /**
     * @brief The Default Constructor of World
     * */
    World();

    /**
     * @brief The Player of the World
     * */
    Player *player;

    FireRoom *room;

    /**
     * @brief Called for updating the world's entities and collision system
     * */
    void tick();

    /**
     * @brief Called for setting up the world [entities, tiles, map and so on]
     * */
    void setup();

    /**
     * @brief Called for rendering the World on the Window
     * 
     * @param window The Window in which the world is renderized
     * */
    void display(sf::RenderWindow &window);

    /**
     * @brief Adds an Entity to this World
     * 
     * @param entity The Entity to add
     * */
    void addEntity(Entity &entity);

    /**
     * @brief Called from tick() to check the Entities collision in this World
     * */
    void checkCollision();

    /**
     * @brief Called from tick() to check the Entities positions in this World
     * */
    void checkPositions();

    /**
     * @param end If the Game int this World is ended
     *            True if the Player is ddead or all the Enemies are dead, false otherwise
     * */
    bool end;

private:
    /**
     * @brief Called from the Construcotr, initializes the map of the world with entities, tiles and so on
     * */
    void generateWorld();

private:
    std::list<Entity *> entities;
    std::list<Tile *> tiles;
    TextBox deathTextBox;
    TextBox winTextBox;
    sf::Font font;
    Menu menu;
    HealthBarNum healthBar;
    Inventory inventory;
    Item item;
    sf::Texture itemTexture;
    int counter; //for debugging, it counts how many time the loop was executed
};

#endif