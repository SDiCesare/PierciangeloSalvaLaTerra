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
     * @brief Check if 2 Rectangle are colliding
     * 
     * @param x1 The x Position of the first Rectangle
     * @param y1 The y Position of the first Rectangle
     * @param width1 The width of the first Rectangle
     * @param height1 The height of the first Rectangle
     * @param x2 The x Position of the second Rectangle
     * @param y2 The y Position of the second Rectangle
     * @param width2 The width of the second Rectangle
     * @param height2 The height of the second Rectangle
     * 
     * @return True if the two rectangles are colliding, Flase otherwise 
     * */
    bool collideRect(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);

    /**
     * @brief Called from tick() to check the Entities collision in this World
     * */
    void checkCollision();

    /**
     * @brief Check if the entity can move to a new position (x, y)
     * 
     * @param e The Entity to move
     * @param x The new x position of the Entity
     * @param y The new y position of the Entity
     * @param width The Entity width
     * @param height The Entity height
     * 
     * @return True if the entity can move to (x, y), False otherwise
     * */
    bool canMove(Entity &e, float x, float y, float width, float height);

    /**
     * @brief Check if e1 hits e2
     * 
     * @param e1 The Entity that hits
     * @param e2 The Entity that is hitted
     * 
     * @return True if e1 hits e2, false otherwise
     * */
    bool isHitted(Entity e1, Entity e2);

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